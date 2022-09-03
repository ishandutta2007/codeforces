#include <cstdio>

int a[101];

int main() {
	int i, j, k, n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (i = 1; i <= n; i++) {
		k = 0;
		for (j = 1; j <= n; j++) if (a[i] % 2 != a[j] % 2) k++;
		if (k > 1) printf("%d", i);
	}
}