#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector <int> adj[N];
int h[N], a[N], sum[N];
int T, n, m, ans;

int dfs1(int u, int fa) {
	int now = 0;
	sum[u] = a[u];
	for (int i = 0; i < (int)adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == fa) continue;
		now += dfs1(v, u); sum[u] += sum[v];
	}
	if (-sum[u] + now * 2 > h[u] || sum[u] < h[u] || ((sum[u] - h[u]) & 1)) {
		ans = 0;
		return 0;
	}
	return (sum[u] + h[u]) / 2;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), adj[i].clear();
		for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
		for (int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		ans = 1; dfs1(1, 0);
		printf("%s\n", ans ? "YES" : "NO");
	}
	return 0;
}