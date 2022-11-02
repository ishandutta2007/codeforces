#include <stdio.h>
#include <string.h>

int main()
{
    int c = 1, p = 0, i;
    char s[101];

    scanf("%s", s);

    for (i = 0; i < strlen(s); i++) {
	if (i == 0) {
	    p++;
	} else if (p == 5 || s[i] != s[i - 1]) {
	    c++;
	    p = 1;
	} else {
	    p++;
	}
    }

    printf("%d\n", c);

    return 0;
}