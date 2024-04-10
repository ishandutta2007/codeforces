#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000000];
    int f = 0, c = 0, i;

    scanf("%s", s);

    for (i = strlen(s) - 1; i > 0; i--) {
	if (s[i] == '0') {
	    if (f == 0) {
		c++;
	    } else {
		c += 2;
	    }
	} else {
	    if (f == 0) {
		c += 2;
		f = 1;
	    } else {
		c++;
	    }
	}
    }

    if (f == 1) c++;

    printf("%d\n", c);

    return 0;
}