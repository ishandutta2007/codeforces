#include <cstdio>

double d[10001][1001];

int main() {
	int i, j, n, m;
	scanf("%d%d", &n, &m);
	d[0][0] = 1;
	for (i = 1; i <= 10000; i++) for (j = 1; j <= n; j++) d[i][j] = (d[i - 1][j] * j + d[i - 1][j - 1] * (n - j + 1)) / n;
	while (m--) {
		scanf("%d", &i);
		for (j = 1; d[j][n] * 2000 + 1e-7 < i; j++);
		printf("%d\n", j);
	}
}