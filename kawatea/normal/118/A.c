#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int p = 0, i, j;
    char s[101], c[101];
    char t[6] = {"aoyeui"};

    scanf("%s", s);

    for (i = 0; i < strlen(s); i++) s[i] = tolower(s[i]);

    for (i = 0; i < strlen(s); i++) {
	for (j = 0; j < 6; j++) {
	    if (s[i] == t[j]) break;
	}

	if (j == 6) c[p++] = s[i];
    }

    for (i = 0; i < p; i++) printf(".%c", c[i]);
    puts("");

    return 0;
}