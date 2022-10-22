#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct segment_tree {
	static const int mxn = 1 << 20;
	int rmn[mxn << 1], rmx[mxn << 1];
	int mn[mxn << 1], mx[mxn << 1];
	int tag[mxn << 1];

	inline void push(int x, bool tp) {
		mn[x] = tp ? rmn[x] : +mxn;
		mx[x] = tp ? rmx[x] : -mxn;
		tag[x] = tp;
	}

	inline void pushdown(int x) {
		if (~tag[x]) {
			push(x << 1, tag[x]);
			push(x << 1 | 1, tag[x]);
			tag[x] = -1;
		}
	}

	inline void pushup(int x) {
		mn[x] = std::min(mn[x << 1], mn[x << 1 | 1]);
		mx[x] = std::max(mx[x << 1], mx[x << 1 | 1]);
	}

	inline void init(int n, int dfn[]) {
		rep(i, mxn << 1) rmn[i] = mn[i] = +mxn, rmx[i] = mx[i] = -mxn, tag[i] = -1;
		rep(i, n) rmn[i + mxn] = rmx[i + mxn] = dfn[i];
		for (int i = mxn - 1; i; -- i) {
			pushup(i);
			rmn[i] = std::min(rmn[i << 1], rmn[i << 1 | 1]);
			rmx[i] = std::max(rmx[i << 1], rmx[i << 1 | 1]);
		}
	}

	inline void update(int l, int r, bool tp, int i = 1, int a = 0, int b = mxn) {
		if (l <= a && b <= r) return push(i, tp);
		if (r <= a || b <= l) return ;
		pushdown(i);
		int m = (a + b) >> 1;
		update(l, r, tp, i << 1, a, m);
		update(l, r, tp, i << 1 | 1, m, b);
		pushup(i);
	}

	inline int querymin(int l, int r, int i = 1, int a = 0, int b = mxn) {
		if (l <= a && b <= r) return mn[i];
		if (r <= a || b <= l) return +mxn;
		pushdown(i);
		int m = (a + b) >> 1;
		return std::min(querymin(l, r, i << 1, a, m), querymin(l, r, i << 1 | 1, m, b));
	}

	inline int querymax(int l, int r, int i = 1, int a = 0, int b = mxn) {
		if (l <= a && b <= r) return mx[i];
		if (r <= a || b <= l) return -mxn;
		pushdown(i);
		int m = (a + b) >> 1;
		return std::max(querymax(l, r, i << 1, a, m), querymax(l, r, i << 1 | 1, m, b));
	}
} seg;

struct tree {
	static const int mxn = 6e5 + 5, mxlg = 20;
	std::vector <int> adj[mxn];

	inline void add_edge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int dfn[mxn], ed[mxn], on[mxn], tim;
	int siz[mxn], son[mxn], fa[mxn], dep[mxn], top[mxn];

	inline void dfs(int u, int p) {
		dfn[u] = tim;
		on[tim] = u;
		fa[u] = p;
		dep[u] = ~p ? dep[p] + 1 : 0;
		++ tim;
		siz[u] = 1, son[u] = -1;
		for (int v : adj[u]) {
			if (v == p) continue;
			dfs(v, u);
			siz[u] += siz[v];
			if (!~son[u] || siz[v] > siz[son[u]]) son[u] = v;
		}
		ed[u] = tim;
	}
	
	inline void hld(int u, int p) {
		top[u] = ~p && u == son[p] ? top[p] : u;
		for (int v : adj[u]) {
			if (v == p) continue;
			hld(v, u);
		}
	}

	int rt;

	inline void build(int _rt) {
		rt = _rt;
		tim = 0;
		dfs(rt, -1);
		hld(rt, -1);
	}

	inline int lca(int u, int v) {
		while (top[u] != top[v]) {
			if (dep[top[u]] > dep[top[v]]) u = fa[top[u]];
			else v = fa[top[v]];
		}
		return dep[u] > dep[v] ? v : u;
	}
} tr;

const int mxn = 6e5 + 5;

struct edge {
	int u, v, w;
};

int n;
std::vector <edge> e;

int fa[mxn];
inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int wei[mxn];

int main() {
	int q;
	scanf("%d %d", &n, &q);
	rep(i, n - 1) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		-- u, -- v;
		e.push_back({u, v, w});
	}
	std::sort(e.begin(), e.end(), [&] (const edge &a, const edge &b) { return a.w < b.w; });
	rep(i, n) fa[i] = i;
	int tot = n;
	rep(i, n - 1) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		u = find(u), v = find(v);
		int x = tot;
		fa[x] = x; wei[x] = w;
		tr.add_edge(x, u), tr.add_edge(x, v);
		fa[u] = fa[v] = x;
		++ tot;
	}
	int rt = tot - 1;
	tr.build(rt);
	seg.init(tot, tr.dfn);
	while (q --) {
		int tp; scanf("%d", &tp);
		if (tp <= 2) {
			int l, r;
			scanf("%d %d", &l, &r);
			-- l;
			seg.update(l, r, 2 - tp);
		} else {
			int x;
			scanf("%d", &x);
			-- x;
			int u = seg.mn[1], v = seg.mx[1];
			if (u >= +mxn && v <= -mxn) {
				puts("-1");
				continue;
			}
			int a[] = {x, tr.on[u], tr.on[v]};
			int ans = -1;
			rep(i, 3) rep(j, i) {
				int c = tr.lca(a[i], a[j]);
				if (c >= n) ans = std::max(ans, wei[c]);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}