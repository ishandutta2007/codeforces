#include <stdio.h>

int main()
{
    int n, i, j;

    scanf("%d", &n);

    for (i = 0; i <= n * 2; i++) {
	if (i < n) {
	    for (j = 0; j < n * 2 - i * 2; j++) putchar(' ');

	    for (j = 0; j <= i; j++) {
		if (j > 0) putchar(' ');
		printf("%d", j);
	    }
	    for (j = i - 1; j >= 0; j--) printf(" %d", j);
	} else if (i == n) {
	    for (j = 0; j <= i; j++) {
		if (j > 0) putchar(' ');
		printf("%d", j);
	    }
	    for (j = i - 1; j >= 0; j--) printf(" %d", j);
	} else {
	    for (j = 0; j < i * 2 - n * 2; j++) putchar(' ');

	    for (j = 0; j <= n * 2 - i; j++) {
		if (j > 0) putchar(' ');
		printf("%d", j);
	    }
	    for (j = n * 2 - i - 1; j >= 0; j--) printf(" %d", j);
	}

	puts("");
    }

    return 0;
}