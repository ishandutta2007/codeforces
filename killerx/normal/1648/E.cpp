#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 4e5 + 5;

struct union_find {
	int fa[mxn];

	inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
};

struct kruskal_rebuild_tree {
	int n;
	std::vector <std::pair <int, std::pair <int, int> > > E;

	inline void init(int _n) {
		n = _n;
		E.clear();
	}

	inline void add_edge(int u, int v, int w) {
		E.push_back({w, {u, v}});
	}

	int tot, rt;
	union_find uf;
	int fa[mxn];
	int ls[mxn], rs[mxn];
	int wei[mxn];
	int dep[mxn];
	int sz[mxn], son[mxn];
	int top[mxn];
	int dfn[mxn], on[mxn], tim;

	inline void dfs(int u) {
		dep[u] = ~fa[u] ? dep[fa[u]] + 1 : 0;
		sz[u] = 1;
		if (u >= n) {
			dfs(ls[u]);
			sz[u] += sz[ls[u]];
			dfs(rs[u]);
			sz[u] += sz[rs[u]];
			son[u] = sz[ls[u]] < sz[rs[u]] ? rs[u] : ls[u];
		}
	}

	inline void hld(int u) {
		if (u < n) {
			on[tim] = u;
			dfn[u] = tim ++;
		}
		top[u] = ~fa[u] && u == son[fa[u]] ? top[fa[u]] : u;
		if (u >= n) {
			hld(ls[u]);
			hld(rs[u]);
		}
	}

	inline void build() {
		std::sort(E.begin(), E.end());
		tot = n;
		rep(i, n) uf.fa[i] = i;
		for (auto pr : E) {
			int u = pr.second.first;
			int v = pr.second.second;
			int w = pr.first;
			if (uf.find(u) != uf.find(v)) {
				int x = tot ++;
				u = uf.find(u);
				v = uf.find(v);
				uf.fa[x] = x;
				uf.fa[u] = x;
				uf.fa[v] = x;
				fa[u] = x;
				fa[v] = x;
				ls[x] = u;
				rs[x] = v;
				wei[x] = w;
			}
		}
		rt = tot - 1;
		fa[rt] = -1;
		dfs(rt);
		tim = 0;
		hld(rt);
	}

	inline int lca(int u, int v) {
		while (top[u] != top[v]) {
			if (dep[top[u]] > dep[top[v]]) std::swap(u, v);
			v = fa[top[v]];
		}
		return dep[u] < dep[v] ? u : v;
	}

	inline int query(int u, int v) {
		return wei[lca(u, v)];
	}
};

int n, m;
int U[mxn], V[mxn], W[mxn];
std::vector <int> adj_l[mxn], adj_r[mxn];

void Main() {
	scanf("%d %d", &n, &m);
	rep(i, m) scanf("%d %d %d", &U[i], &V[i], &W[i]), -- U[i], -- V[i];
	static kruskal_rebuild_tree tr1;
	tr1.init(n);
	rep(i, m) tr1.add_edge(U[i], V[i], W[i]);
	tr1.build();
	rep(i, n) adj_l[i].clear(), adj_r[i].clear();
	rep(i, m) {
		int u = tr1.dfn[U[i]], v = tr1.dfn[V[i]];
		if (u < v) adj_l[v].push_back(u), adj_r[u].push_back(v);
		else adj_l[u].push_back(v), adj_r[v].push_back(u);
	}
	rep(i, n) {
		std::sort(adj_l[i].rbegin(), adj_l[i].rend());
		std::sort(adj_r[i].begin(), adj_r[i].end());
	}
	static union_find uf;
	rep(i, n) uf.fa[i] = i;
	static kruskal_rebuild_tree tr2;
	tr2.init(n);
	while (true) {
		static int id[mxn];
		rep(i, n) id[i] = uf.find(tr1.on[i]);
		bool ok = 1;
		rep(i, n) ok &= id[i] == id[0];
		if (ok) break;
		static int lv[mxn], rv[mxn];
		rep(i, n)
			lv[i] = !i ? -1 : id[i - 1] == id[i] ? lv[i - 1] : i - 1;
		for (int i = n - 1; ~i; -- i)
			rv[i] = i == n - 1 ? -1 : id[i + 1] == id[i] ? rv[i + 1] : i + 1;
		static std::pair <int, std::pair <int, int> > oe[mxn];
		rep(i, n) oe[id[i]] = {0x3f3f3f3f, {-1, -1}};
		rep(i, n) {
			for (int u = lv[i], k = 0; ~u; u = !u ? -1 : id[u - 1] == id[i] ? lv[u - 1] : u - 1) {
				while (k < (int) adj_l[i].size() && adj_l[i][k] > u) ++ k;
				if (k == (int) adj_l[i].size() || adj_l[i][k] != u) {
					oe[id[i]] = std::min(oe[id[i]], std::make_pair(tr1.query(tr1.on[u], tr1.on[i]), std::make_pair(tr1.on[u], tr1.on[i])));
					break;
				}
			}
			for (int u = rv[i], k = 0; ~u; u = u == n - 1 ? -1 : id[u + 1] == id[i] ? rv[u + 1] : u + 1) {
				while (k < (int) adj_r[i].size() && adj_r[i][k] < u) ++ k;
				if (k == (int) adj_r[i].size() || adj_r[i][k] != u) {
					oe[id[i]] = std::min(oe[id[i]], std::make_pair(tr1.query(tr1.on[u], tr1.on[i]), std::make_pair(tr1.on[u], tr1.on[i])));
					break;
				}
			}
		}
		rep(i, n) {
			int u = oe[id[i]].second.first;
			int v = oe[id[i]].second.second;
			int w = oe[id[i]].first;
			if (~u && ~v) {
				if (uf.find(u) != uf.find(v)) {
					tr2.add_edge(u, v, w);
					uf.fa[uf.find(u)] = uf.find(v);
				}
			}
		}
	}
	tr2.build();
	rep(i, m) printf("%d ", tr2.query(U[i], V[i]));
	printf("\n");
}

int main() {
	int T;
	scanf("%d", &T);
	while (T --) Main();
	return 0;
}