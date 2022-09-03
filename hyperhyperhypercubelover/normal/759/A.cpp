#include <cstdio>

int a[200002];
int d[200002];
int v[200002];

int main() {
	int i, j, n, t, r = 1;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (i = 0; i < n; i++) {
		scanf("%d", &d[i]);
		r ^= d[i];
	}
	t = 0;
	for (i = 1; i <= n; i++) if (!v[i]) {
		t++;
		for (j = i; !v[j]; j = a[j]) v[j] = 1;
	}
	printf("%d", r + (t > 1 ? t : 0));
}