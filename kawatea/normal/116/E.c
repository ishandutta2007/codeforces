#include <stdio.h>

int a[500000][2];
int b[500000][2];

int main()
{
    int n, m, x = 1, mod = 1000003, i, j;
    char s[500001];

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++) {
	for (j = 0; j < 2; j++) {
	    a[i][j] = 1;
	}
    }

    for (i = 0; i < m; i++) {
	for (j = 0; j < 2; j++) {
	    b[i][j] = 1;
	}
    }

    for (i = 0; i < n; i++) {
	scanf("%s", s);

	for (j = 0; j < m; j++) {
	    if (s[j] == '1' || s[j] == '2') {
		a[i][j % 2] = 0;
	    } else if (s[j] == '3' || s[j] == '4') {
		a[i][(j + 1) % 2] = 0;
	    }
	}

	for (j = 0; j < m; j++) {
	    if (s[j] == '1' || s[j] == '4') {
		b[j][i % 2] = 0;
	    } else if (s[j] == '2' || s[j] == '3') {
		b[j][(i + 1) % 2] = 0;
	    }
	}
    }

    for (i = 0; i < n; i++) {
	x *= (a[i][0] + a[i][1]);
	x %= mod;
    }

    for (i = 0; i < m; i++) {
	x *= (b[i][0] + b[i][1]);
	x %= mod;
    }

    printf("%d\n", x);

    return 0;
}