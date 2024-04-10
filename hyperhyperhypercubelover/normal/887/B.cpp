#include <cstdio>

int a[3][10];

int main() {
	int i, j, k, l, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) for (j = 0; j < 6; j++) {
		scanf("%d", &k);
		a[i][k] = 1;
	}
	for (i = 1; i < 1000; i++) {
		if (i < 10) {
			for (j = 0; j < n; j++) if (a[j][i]) goto succ;
			break;
		}
		else if (i < 100) {
			for (j = 0; j < n; j++) for (k = 0; k < n; k++) if (j != k && a[j][i / 10] && a[k][i % 10]) goto succ;
			break;
		}
		else {
			for (j = 0; j < n; j++) for (k = 0; k < n; k++) for (l = 0; l < n; l++) if (j != k && j != l && k != l && a[j][i / 100] && a[k][i / 10 % 10] && a[l][i % 10]) goto succ;
			break;
		}
succ:;
	}
	printf("%d\n", i - 1);
}