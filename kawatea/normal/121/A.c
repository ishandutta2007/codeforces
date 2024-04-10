#include <stdio.h>

int main()
{
    long long a[10000];
    int p = 0, q = 2, r = 2, x, y, i, j;
    long long sum;

    scanf("%d %d", &x, &y);

    a[0] = 4;
    a[1] = 7;

    for (i = 0; i < 9; i++) {
	for (j = p; j < q; j++) {
	    a[r++] = a[j] * 10 + 4;
	    a[r++] = a[j] * 10 + 7;
	}

	p = q;
	q = r;
    }

    for (i = 0; i < r; i++) {
	if (a[i] >= x) break;
    }

    sum = a[i];

    for (; i < r; i++) {
	if (a[i] > y) {
	    sum += a[i] * (y - x);

	    break;
	} else {
	    sum += a[i] * (a[i] - x);

	    x = a[i];
	}
    }

    printf("%I64d\n", sum);

    return 0;
}