#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5, inf = 0x3f3f3f3f;

int n, m;
struct edge {
	int u, v, w, b;
};
edge E[mxn];

std::vector <std::pair <int, int> > adj[mxn];
bool vis[mxn];
int dep[mxn];
bool flg;
int cc[mxn], c;

inline void dfs(int u) {
	vis[u] = 1, cc[u] = c;
	rep(i, adj[u].size()) {
		int v = adj[u][i].first, w = adj[u][i].second;
		if (!vis[v]) dep[v] = dep[u] + w, dfs(v);
		else if (dep[v] != dep[u] + w) flg = 0;
	}
}

inline int chk(int Lim) {
	rep(i, n) adj[i].clear();
	rep(i, Lim) {
		adj[E[i].u].push_back({E[i].v, +E[i].w * E[i].b});
		adj[E[i].v].push_back({E[i].u, -E[i].w * E[i].b});
	}
	rep(i, n) vis[i] = 0, dep[i] = 0, cc[i] = -1;
	flg = 1;
	c = 0;
	rep(i, n) if (!vis[i]) dfs(i), ++ c;
	if (!flg) return -1;
	rep(i, n) {
		if (i != 0 && cc[0] == cc[i] && dep[i] <= dep[0]) return -1;
		if (i != n - 1 && cc[n - 1] == cc[i] && dep[i] >= dep[n - 1]) return -1;
	}
	static int mn[mxn], mx[mxn];
	rep(i, c) mn[i] = +inf, mx[i] = -inf;
	rep(i, n) mn[cc[i]] = std::min(mn[cc[i]], dep[i]);
	rep(i, n) mx[cc[i]] = std::max(mx[cc[i]], dep[i]);
	if (cc[0] == cc[n - 1]) rep(i, c) if (cc[0] != i) {
		if (mx[i] - mn[i] >= dep[n - 1] - dep[0]) return -1;
	}
	return cc[0] == cc[n - 1] ? dep[n - 1] - dep[0] : 0;
}

int main() {
	scanf("%d %d", &n, &m);
	rep(i, m) scanf("%d %d %d %d", &E[i].u, &E[i].v, &E[i].w, &E[i].b), -- E[i].u, -- E[i].v;
	int lb = 0, rb = m;
	while (lb < rb) {
		int md = (lb + rb + 1) >> 1;
		if (chk(md) >= 0) lb = md;
		else rb = md - 1;
	}
	if (lb == m) {
		int ans = chk(m);
		if (!ans) puts("UNKNOWN");
		else printf("%d\n", ans);
	} else printf("BAD %d\n", lb + 1);
	return 0;
}