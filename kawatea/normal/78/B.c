#include <stdio.h>

int main()
{
    int n, i;
    char s[7] = "ROYGBIV";
    char ss[4] = "GBIV";

    scanf("%d", &n);

    if (n % 7 == 0 || n % 7 >= 4) {
	for (i = 0; i < n; i++) {
	    putchar(s[i % 7]);
	}
	puts("");
    } else {
	printf("ROY");
	for (i = 3; i < n; i++) {
	    putchar(ss[i % 4]);
	}
	puts("");
    }

    return 0;
}