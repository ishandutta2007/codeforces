#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;

int n;
vector <int> g[N];
int dep[N], fa[N][20];
int bg[N], ed[N], tme;

void dfs(int u, int p) {
	bg[u] = tme ++;
	for (int i = 0; i < g[u].size(); ++ i) {
		int v = g[u][i];
		if (v == p) continue;
		fa[v][0] = u;
		dep[v] = dep[u] + 1;
		dfs(v, u);
	}
	ed[u] = tme ++;
}

bool is_subtree(int u, int v) {
	return bg[u] <= bg[v] && ed[v] <= ed[u];
}

void LCA(int u, int v, int &l) {
	if (dep[u] > dep[v]) swap(u, v);
	for (int i = 19; ~i; -- i)
		if ((dep[v] - dep[u]) >> i & 1)
			v = fa[v][i];
	if (v == u) {l = u; return ;}
	for (int i = 19; ~i; -- i)
		if (fa[u][i] != fa[v][i])
			u = fa[u][i], v = fa[v][i];
	l = fa[u][0];
}

int Lca(int x, int y) {
	int l;
	LCA(x, y, l);
	return l;
}

int Dis(int x, int y) {
	int l = Lca(x, y);
	int d = dep[x] + dep[y] - 2 * dep[l];
	return d;
}

int get(int u, int x, int y) {
	int l = Lca(x, y), ans = l;
	if (is_subtree(l, Lca(u, x)) && dep[Lca(u, x)] >= dep[ans]) ans = Lca(u, x);
	if (is_subtree(l, Lca(u, y)) && dep[Lca(u, y)] >= dep[ans]) ans = Lca(u, y);
	return ans;
}

signed main() {
	scanf("%lld", &n);
	for (int i = 1; i < n; ++ i) {
		int u, v; scanf("%lld %lld", &u, &v);
		-- u; -- v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, -1);
	for (int i = 1; i < 20; ++ i)
		for (int j = 0; j < n; ++ j)
			fa[j][i] = fa[fa[j][i - 1]][i - 1];
	int q; scanf("%lld", &q);
	while (q --) {
		int x, y, a, b, k;
		scanf("%lld %lld %lld %lld %lld", &x, &y, &a, &b, &k);
		-- x, -- y, -- a, -- b;
		int Lxy = Lca(x, y);
		int La = get(a, x, y);
		int Lb = get(b, x, y);
		int DLab = Dis(La, Lb);
		int Da = Dis(a, La);
		int Db = Dis(b, Lb);
		int Dc = Dis(x, y) + 1;
		int Dab = Dis(a, b);
		bool ok = 0;
		if ((Da + Db + DLab) % 2 == k % 2)
			ok |= (Da + Db + DLab <= k);
		if ((Da + Db + Dc - DLab) % 2 == k % 2)
			ok |= (Da + Db + Dc - DLab <= k);
		if (Dab % 2 == k % 2) ok |= Dab <= k;
		puts(ok ? "YES" : "NO");
	}
	return 0;
}