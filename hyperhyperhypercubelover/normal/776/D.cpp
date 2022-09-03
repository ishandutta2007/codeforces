#include <cstdio>

int a[100001];
int d[100001];
int p[200002];

int f(int x) {
	return x == p[x] ? x : p[x] = f(p[x]);
}

int main() {
	int i, j, n, m;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (i = 1; i <= m; i++) {
		p[i] = i;
		p[i + m] = i + m;
	}
	for (j = 1; j <= m; j++) {
		scanf("%d", &n);
		while (n--) {
			scanf("%d", &i);
			if (d[i]) {
				if (a[i]) {
					p[f(j)] = f(d[i]);
					p[f(j + m)] = f(d[i] + m);
				}
				else {
					p[f(j)] = f(d[i] + m);
					p[f(j + m)] = f(d[i]);
				}
			}
			else d[i] = j;
		}
	}
	for (i = 1; i <= m; i++) if (f(i) == f(i + m)) {
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}