#include <cstdio>

int a[16];

int main() {
	int i, j, k, n, m, t;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = t = 0; j < m; j++) {
			scanf("%d", &k);
			t = t << 1 | k;
		}
		a[t] = 1;
	}
	for (i = 1; i < 1 << 16; i++) {
		for (j = 0; j < 16; j++) if (i >> j & 1 && !a[j]) break;
		if (j < 16) continue;
		for (j = 0; j < 4; j++) {
			t = 0;
			for (k = 0; k < 16; k++) if (i >> k & 1) t += k >> j & 1 ? 1 : -1;
			if (t > 0) break;
		}
		if (j == 4) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}