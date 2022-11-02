#include <stdio.h>

int main()
{
    int n, p = 0, q = 2, r = 2, i, j;
    int a[1000];

    scanf("%d", &n);

    a[0] = 4;
    a[1] = 7;

    for (i = 0; i < 5; i++) {
	for (j = p; j < q; j++) {
	    a[r++] = a[j] * 10 + 4;
	    a[r++] = a[j] * 10 + 7;
	}

	p = q;
	q = r;
    }

    for (i = 0; i < r; i++) {
	if (a[i] > n) break;

	if (n % a[i] == 0) {
	    puts("YES");

	    return 0;
	}
    }

    puts("NO");

    return 0;
}