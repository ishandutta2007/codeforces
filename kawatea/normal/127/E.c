#include <stdio.h>

int main()
{
    int n, sum = 0, i, j;
    char s[2001][2001];
    int a[2000] = {0};
    int b[2000] = {0};
    int c[2000] = {0};
    int d[2000] = {0};

    scanf("%d", &n);

    for (i = 0; i < n; i++) scanf("%s", s[i]);

    for (i = 0; i < n; i++) {
	for (j = n - 1; j > i; j--) {
	    int p = s[i][j] - '0' + a[i] + b[j];

	    if (p % 2 == 1) {
		sum++;

		a[i]++;
		b[j]++;
	    }
	}
    }

    for (i = n - 1; i > 0; i--) {
	for (j = 0; j < i; j++) {
	    int p = s[i][j] - '0' + c[i] + d[j];

	    if (p % 2 == 1) {
		sum++;

		c[i]++;
		d[j]++;
	    }
	}
    }

    for (i = 0; i < n; i++) {
	int p = s[i][i] - '0' + a[i] + b[i] + c[i] + d[i];

	if (p % 2 == 1) sum++;
    }

    printf("%d\n", sum);

    return 0;
}