#include <bits/stdc++.h>
using namespace std;

const int N = 185;

int n, K;
int d[N];
int ans[N];
int f[N][N];
int dis[N][N];
vector <int> g[N];
int dp[N], dp0[N][N][N];
int pre[N], pre0[N][N][N];
int siz[N], dfn[N], on[N], tme;

void dfs(int u, int p) {
	on[tme] = u; dfn[u] = tme ++;
	siz[u] = 1;
	for (int j = 0; j < n; ++ j) f[u][j] = d[j];
	for (int i = 0; i < g[u].size(); ++ i) {
		int v = g[u][i];
		if (v == p) continue;
		dfs(v, u);
		for (int j = 0; j < n; ++ j) {
			f[u][j] += f[v][j + 1];
		}
		siz[u] += siz[v];
	}
}

void dfs0(int u, int p) {
	for (int i = 0; i < g[u].size(); ++ i) {
		int v = g[u][i];
		if (v == p) continue;
		dfs0(v, u);
	}
	dp[u] = 0x3f3f3f3f;
	for (int x = u; ~x && dfn[x] < dfn[u] + siz[u]; x = on[dfn[x] + 1]) {
		for (int v = on[dfn[u] + siz[u] - 1]; v != u; v = on[dfn[v] - 1]) {
			if (dfn[v] <= dfn[x] && dfn[x] < dfn[v] + siz[v]) {
				dp0[u][x][v] = (~on[dfn[v] + 1] ? dp0[u][x][on[dfn[v] + 1]] : 0);
				pre0[u][x][v] = 0;
				continue;
			}
			dp0[u][x][v] = (~on[dfn[v] + siz[v]] ? dp0[u][x][on[dfn[v] + siz[v]]] : 0) + dp[v] - f[v][dis[v][x]];
			pre0[u][x][v] = 1;
			if ((~on[dfn[v] + 1] ? dp0[u][x][on[dfn[v] + 1]] : 0) < dp0[u][x][v]) {
				dp0[u][x][v] = (~on[dfn[v] + 1] ? dp0[u][x][on[dfn[v] + 1]] : 0);
				pre0[u][x][v] = 0;
			}
		}
		int cur = (~on[dfn[u] + 1] ? dp0[u][x][on[dfn[u] + 1]] : 0) + K;
		for (int v = u; ~v && dfn[v] < dfn[u] + siz[u]; v = on[dfn[v] + 1])
			cur += d[dis[x][v]];
		if (cur < dp[u]) {
			dp[u] = cur;
			pre[u] = x;
		}
	}
}

void prt(int u) {
	int x = pre[u];
	for (int v = u; ~v && dfn[v] < dfn[u] + siz[u]; v = on[dfn[v] + 1])
		ans[v] = x;
	int v = on[dfn[u] + 1];
	while (~v && dfn[v] < dfn[u] + siz[u]) {
		if (pre0[u][x][v]) prt(v);
		v = pre0[u][x][v] ? on[dfn[v] + siz[v]] : on[dfn[v] + 1];
	}
}

int main() {
	scanf("%d %d", &n, &K);
	for (int i = 1; i < n; ++ i) scanf("%d", &d[i]);
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 0; i < n; ++ i) dis[i][i] = 0;
	for (int i = 1; i < n; ++ i) {
		int u, v; scanf("%d %d", &u, &v); -- u, -- v;
		g[u].push_back(v); g[v].push_back(u);
		dis[u][v] = dis[v][u] = 1;
	}
	for (int k = 0; k < n; ++ k) {
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < n; ++ j) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	on[n] = -1;
	dfs(0, -1);
	dfs0(0, -1);
	printf("%d\n", dp[0]);
	prt(0);
	for (int i = 0; i < n; ++ i) printf("%d ", ans[i] + 1); puts("");
	return 0;
}