#include <stdio.h>
#include <string.h>

int main()
{
    int f = 0, i, j;
    char s[105];

    scanf("%s", s);

    for (i = 0; i < strlen(s); i++) {
	char x = s[i];
	int c = 0;

	for (j = i; j < strlen(s); j++) {
	    if (s[j] == x) {
		c++;
	    } else {
		break;
	    }
	}

	if (c >= 7) {
	    f = 1; break;
	}
    }

    if (f == 1) {
	puts("YES");
    } else {
	puts("NO");
    }

    return 0;
}