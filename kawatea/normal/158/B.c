#include <stdio.h>

int main()
{
    int n, sum = 0, i;
    int a[4] = {0};

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
	int x;

	scanf("%d", &x);

	a[x - 1]++;
    }

    sum += a[3];

    sum += a[2];

    if (a[2] >= a[0]) {
	a[0] = 0;
    } else {
	a[0] -= a[2];
    }

    sum += a[1] / 2;

    a[1] %= 2;

    if (a[1] > 0) {
	sum++;

	if (a[0] <= 2) {
	    a[0] = 0;
	} else {
	    a[0] -= 2;
	}
    }

    sum += (a[0] + 3) / 4;

    printf("%d\n", sum);

    return 0;
}