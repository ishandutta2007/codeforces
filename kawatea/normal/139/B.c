#include <stdio.h>

int main()
{
    int n, m, sum = 0, i, j;
    int a[500][3], b[500][3];

    scanf("%d", &n);

    for (i = 0; i < n; i++) scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);

    scanf("%d", &m);

    for (i = 0; i < m; i++) scanf("%d %d %d", &b[i][0], &b[i][1], &b[i][2]);

    for (i = 0; i < n; i++) {
	int min = 1e9;
	int x = (a[i][0] + a[i][1]) * 2;

	for (j = 0; j < m; j++) {
	    int y;

	    if (a[i][2] > b[j][0]) continue;

	    y = b[j][0] / a[i][2] * b[j][1];

	    if (x % y == 0) {
		y = x / y;
	    } else {
		y = x / y + 1;
	    }

	    if (y * b[j][2] < min) min = y * b[j][2];
	}

	sum += min;
    }

    printf("%d\n", sum);

    return 0;
}