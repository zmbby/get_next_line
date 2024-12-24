/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoentifi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 01:16:01 by zoentifi          #+#    #+#             */
/*   Updated: 2024/12/22 01:16:05 by zoentifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new_str;

	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = strlen(s1);
	if (s2)
		len2 = strlen(s2);
	new_str = malloc(len1 + len2 + 1);
	if (!new_str)
		return (NULL);
	if (s1)
		memcpy(new_str, s1, len1);
	if (s2)
		memcpy(new_str + len1, s2, len2);
	new_str[len1 + len2] = '\0';
	return (new_str);
}

char	*ft_realloc(char *old_str, char *append)
{
	char	*new_str;

	new_str = ft_strjoin(old_str, append);
	if (old_str)
		free(old_str);
	return (new_str);
}

/*int	init_buffer(t_buff *buff)
{
	if (!buff->buffer)
	{
		buff->buffer = malloc(BUFFER_SIZE);
		if (!buff->buffer)
			return (0);
	}
	return (1);
}*/

char	*read_from_buffer(t_buff *buff, char *line)
{
	char	temp[2];

	while (buff->buffer_index < buff->bytes_read)
	{
		temp[0] = buff->buffer[buff->buffer_index];
		buff->buffer_index++;
		line = ft_realloc(line, temp);
		if (!line)
			return (NULL);
		if (temp[0] == '\n')
			return (line);
	}
	return (line);
}