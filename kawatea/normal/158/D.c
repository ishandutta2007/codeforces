#include <stdio.h>

int main()
{
    int n, max = -1e9, i, j;
    int a[20000], b[20000];

    scanf("%d", &n);

    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    for (i = 3; i <= n; i++) {
	if (n % i == 0) {
	    int x = n / i;

	    for (j = 0; j < x; j++) b[j] = 0;

	    for (j = 0; j < n; j++) b[j % x] += a[j];

	    for (j = 0; j < x; j++) {
		if (b[j] > max) max = b[j];
	    }
	}
    }

    printf("%d\n", max);

    return 0;
}