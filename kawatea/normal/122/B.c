#include <stdio.h>
#include <string.h>

int main()
{
    int p = 0, q = 0, i;
    char s[51];

    scanf("%s", s);

    for (i = 0; i < strlen(s); i++) {
	if (s[i] == '4') {
	    p++;
	} else if (s[i] == '7') {
	    q++;
	}
    }

    if (p == 0 && q == 0) {
	puts("-1");
    } else if (p >= q) {
	puts("4");
    } else {
	puts("7");
    }

    return 0;
}