#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;

struct UnionFind {
	int fa[mxn * 2];

	void init(int n) { rep(i, n) fa[i] = i; }

	inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

	inline void merge(int x, int y) {
		x = find(x), y = find(y);
		fa[x] = y;
	}
} uf;

int n, q;
std::vector <std::pair <int, int> > adj[mxn];

inline void same(int u, int v) { uf.merge(u, v); uf.merge(u + n, v + n); }
inline void diff(int u, int v) { uf.merge(u + n, v); uf.merge(u, v + n); }

int vxor[mxn];
int fa[mxn], faid[mxn];

void dfs(int u, int p) {
	rep(i, adj[u].size()) {
		int v = adj[u][i].first, w = adj[u][i].second;
		if (v == p) continue;
		fa[v] = u;
		faid[v] = i;
		vxor[v] = vxor[u];
		if (w != -1) same(u, v), vxor[v] ^= w;
		else adj[u][i].second = 0;
		dfs(v, u);
	}
}

void Main() {
	scanf("%d %d", &n, &q);
	uf.init(n * 2);
	rep(i, n) adj[i].clear();
	rep(i, n - 1) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		-- u, -- v;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	dfs(0, -1);
	rep(i, q) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		-- u, -- v;
		int x = vxor[u] ^ vxor[v];
		if (__builtin_parity(x) == w) same(u, v);
		else diff(u, v);
	}
	rep(i, n) if (uf.find(i) == uf.find(i + n)) {
		puts("NO");
		return ;
	}
	puts("YES");
	static bool ovo[mxn];
	rep(i, n) {
		int x = uf.find(i);
		if (x < n) ovo[i] = true;
		else ovo[i] = false;
	}
	rep(i, n) if (i) {
		if (ovo[i] != ovo[fa[i]]) {
			adj[fa[i]][faid[i]].second = 1;
		}
	}
	rep(i, n) rep(j, adj[i].size()) if (adj[i][j].first != fa[i]) {
		printf("%d %d %d\n", i + 1, adj[i][j].first + 1, adj[i][j].second);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T --) Main();
	return 0;
}