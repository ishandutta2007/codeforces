#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, m, h[maxn], f[maxn], pos[maxn]; bool flg[maxn][maxn];
vector <int> g[maxn];

int dfs(int u) {
	if (~f[u]) return f[u]; f[u] = 0;
	for (int v : g[u]) f[u] = max(f[u], dfs(v));
	return ++f[u];
}

int main() {
	scanf("%d %d", &n, &m);
	memset(f, -1, sizeof f);
	memset(flg, 1, sizeof flg);
	for (int k = 0; k < m; k++) {
		for (int i = 1, x; i <= n; i++) {
			scanf("%d", &x), pos[x] = i;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				flg[i][j] &= pos[i] < pos[j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (flg[i][j]) g[i].push_back(j);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dfs(i));
	}
	printf("%d", ans);
	return 0;
}