#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, j, k;
    char s[10001] = "";

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
	char c[201];

	scanf("%s", c);

	if (c[0] == 'p') {
	    printf("%s/\n", s);

	    continue;
	}

	scanf("%s", c);

	if (c[0] == '/') {
	    strcpy(s, c);
	} else {
	    strcat(s, "/");
	    strcat(s, c);
	}

	for (j = 0; j < strlen(s); j++) {
	    if (s[j] == '.' && s[j + 1] == '.') {
		for (k = j - 2; k >= 0; k--) {
		    if (s[k] == '/') break;
		}

		s[k] = '\0';

		strcat(s, &s[j + 2]);

		j = k;
	    }
	}

	if (s[1] == '\0') s[0] = '\0';
    }

    return 0;
}