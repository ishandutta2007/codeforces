#include <cstdio>

int a[1001][5];

int f(int i, int j) {
	int k, r = 0;
	for (k = 0; k < 5; k++) r += a[i][k] * a[j][k];
	return r;
}

int r[100], rn;

int main() {
	int i, j, k, n, t;
	scanf("%d", &n);
	if (n > 100) {
		puts("0");
		return 0;
	}
	for (i = 0; i < n; i++) for (j = 0; j < 5; j++) scanf("%d", &a[i][j]);
	for (i = 0; i < n; i++) {
		t = 1;
		for (j = 0; j < n; j++) if (i != j) for (k = 0; k < n; k++) if (i != k && j != k) {
			if (f(i, i) - f(i, j) - f(i, k) + f(j, k) > 0) t = 0;
		}
		if (t) r[rn++] = i;
	}
	printf("%d\n", rn);
	for (i = 0; i < rn; i++) printf("%d ", r[i] + 1);
	return 0;
}