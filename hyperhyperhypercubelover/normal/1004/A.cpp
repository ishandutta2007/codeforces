#include <cstdio>

int d[101];

int main() {
	int i, j, n, m, r = 2;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) scanf("%d", &d[i]);
	for (i = 1; i < n; i++) {
		if (d[i] - d[i - 1] > m + m) r++;
		if (d[i] - d[i - 1] >= m + m) r++;
	}
	printf("%d\n", r);
	return 0;
}