#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n, m, a[maxn], par[maxn];

int find(int x) {
	return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int x, int y) {
	par[x = find(x)] = y = find(y), a[y] = min(a[x], a[y]);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i), par[i] = i;
	}
	for (int i = 1, x, y; i <= m; i++) {
		scanf("%d %d", &x, &y), unite(x, y);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += a[find(i)], a[find(i)] = 0;
	}
	printf("%I64d", ans);
	return 0;
}