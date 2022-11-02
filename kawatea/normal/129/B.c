#include <stdio.h>

int main()
{
    int n, m, i, j;
    int a[100][2], b[100] = {0};

    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++) {
	scanf("%d %d", &a[i][0], &a[i][1]);

	a[i][0]--;
	a[i][1]--;
    }

    for (i = 0; ; i++) {
	int f = 0;
	int c[100] = {0};

	for (j = 0; j < m; j++) {
	    if (b[a[j][0]] == 0 && b[a[j][1]] == 0) {
		c[a[j][0]]++;
		c[a[j][1]]++;
	    }
	}

	for (j = 0; j < n; j++) {
	    if (c[j] == 1) {
		f = 1;
		b[j] = 1;
	    }
	}

	if (f == 0) break;
    }

    printf("%d\n", i);

    return 0;
}