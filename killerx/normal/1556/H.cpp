#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 55;
const int mxlg = 6;

int n, K;
int lim[mxn];
int wei[mxn][mxn];

template <typename T>
struct Matroid {
	virtual void insert(T u);
	virtual void erase(T u);
	virtual void prepare();
	virtual bool can_insert(T u);
	virtual bool can_replace(T u, T v);
};

struct Edge {
	int u, v, w;
};

struct M1 : Matroid <Edge> {
	int cnt[mxn];

	M1() { memset(cnt, 0, sizeof(cnt)); }

	virtual void insert(Edge u) { cnt[u.u] += 1; cnt[u.v] += 1; }
	virtual void erase(Edge u) { cnt[u.u] -= 1; cnt[u.v] -= 1; }
	virtual void prepare() {}
	virtual bool can_insert(Edge u) { return cnt[u.u] + 1 <= lim[u.u] && cnt[u.v] + 1 <= lim[u.v]; }
	virtual bool can_replace(Edge u, Edge v) {
		if (cnt[v.u] + 1 - (u.u == v.u) - (u.v == v.u) > lim[v.u]) return false;
		if (cnt[v.v] + 1 - (u.u == v.v) - (u.v == v.v) > lim[v.v]) return false;
		return true;
	}
};

struct M2 : Matroid <Edge> {
	bool adj[mxn][mxn];
	int cc[mxn], c;
	int dep[mxn];
	int dfn[mxn], ed[mxn], tim;
	int fa[mxn], jmp[mxn][mxlg];

	M2() { memset(adj, 0, sizeof(adj)); }

	virtual void insert(Edge u) { adj[u.u][u.v] = adj[u.v][u.u] = true; }
	virtual void erase(Edge u) { adj[u.u][u.v] = adj[u.v][u.u] = false; }

	void dfs(int u, int p) {
		cc[u] = c;
		dfn[u] = tim ++;
		jmp[u][0] = fa[u];
		rep(i, mxlg - 1) jmp[u][i + 1] = jmp[jmp[u][i]][i];
		rep(v, n) if (adj[u][v] && v != p) {
			fa[v] = u;
			dep[v] = dep[u] + 1;
			dfs(v, u);
		}
		ed[u] = tim;
	}

	virtual void prepare() {
		c = tim = 0;
		rep(i, n) cc[i] = -1, dfn[i] = ed[i] = -1, fa[i] = -1, dep[i] = 0;
		rep(i, n) if (cc[i] == -1) dfs(i, -1), ++ c;
	}

	virtual bool can_insert(Edge u) { return cc[u.u] != cc[u.v]; }

	inline int lca(int u, int v) {
		if (dep[u] > dep[v]) std::swap(u, v);
		rep(i, mxlg) if ((dep[v] - dep[u]) >> i & 1) v = jmp[v][i];
		if (u == v) return u;
		for (int i = mxlg - 1; ~i; -- i) if (jmp[u][i] != jmp[v][i])
			u = jmp[u][i], v = jmp[v][i];
		return fa[u];
	}

	inline bool in_subt(int u, int v) { return dfn[u] <= dfn[v] && ed[v] <= ed[u]; }

	virtual bool can_replace(Edge u, Edge v) {
		if (cc[v.u] != cc[v.v]) return true;
		int x = lca(v.u, v.v);
		int a = u.u, b = u.v;
		if (cc[a] != cc[v.u]) return false;
		if (dep[a] > dep[b]) std::swap(a, b);
		if (in_subt(x, a) && in_subt(b, v.u)) return true;
		if (in_subt(x, a) && in_subt(b, v.v)) return true;
		return false;
	}
};

template <typename T, typename M1, typename M2>
struct MatroidInter {
	template <typename C>
	std::vector <T> solve(int n,
			std::function <T(int)> get,
			std::function <C(T)> weight,
			std::function <C()> e, M1 m1, M2 m2) {
		std::vector <bool> vis(n);
		while (true) {
			m1.prepare();
			m2.prepare();
			std::vector <std::pair <C, int> > dis(n);
			std::vector <int> pr(n);
			std::vector <int> que;
			std::vector <bool> inque(n);
			int tar = -1;
			rep(i, n) dis[i] = std::make_pair(e(), 0x3f3f3f3f);
			#define relax(v, c, u) { \
				std::pair <C, int> d = std::make_pair(c.first + (!vis[v] ? weight(get(v)) : -weight(get(v))), c.second + 1); \
				if (d < dis[v]) { \
					dis[v] = d; \
					pr[v] = u; \
					if (!inque[v]) inque[v] = true, que.push_back(v); \
					if (!vis[v] && m2.can_insert(get(v))) { \
						if (!~tar || dis[v] < dis[tar]) tar = v; \
					} \
				} \
			}
			rep(i, n) if (!vis[i] && m1.can_insert(get(i))) relax(i, std::make_pair(0, 0), -1);
			rep(i, que.size()) {
				int u = que[i];
				inque[u] = false;
				if (vis[u]) {
					rep(v, n) if (!vis[v] && m1.can_replace(get(u), get(v))) relax(v, dis[u], u);
				} else {
					rep(v, n) if (vis[v] && m2.can_replace(get(v), get(u))) relax(v, dis[u], u);
				}
			}
			if (!~tar) break;
			for (int u = tar; ~u; u = pr[u]) {
				if (!vis[u]) vis[u] = true, m1.insert(get(u)), m2.insert(get(u));
				else vis[u] = false, m1.erase(get(u)), m2.erase(get(u));
			}
		}
		std::vector <T> ans;
		rep(i, n) if (vis[i]) ans.push_back(get(i));
		return ans;
	}
};

struct UnionFind {
	int fa[mxn];

	void init(int n) { rep(i, n) fa[i] = i; }

	inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

	inline bool same(int x, int y) { return find(x) == find(y); }

	inline void merge(int x, int y) { fa[find(x)] = find(y); }
};

int main() {
	scanf("%d %d", &n, &K);
	rep(i, n) lim[i] = n - 1;
	rep(i, K) scanf("%d", &lim[i]);
	rep(i, n) for (int j = i + 1; j < n; ++ j) scanf("%d", &wei[i][j]);
	std::vector <Edge> qwq;
	std::vector <std::pair <int, std::pair <int, int> > > edg;
	for (int i = K; i < n; ++ i) for (int j = i + 1; j < n; ++ j)
		edg.push_back(std::make_pair(wei[i][j], std::make_pair(i, j)));
	std::sort(edg.begin(), edg.end());
	UnionFind uf;
	uf.init(n);
	for (auto pr : edg) {
		int u = pr.second.first;
		int v = pr.second.second;
		if (!uf.same(u, v)) uf.merge(u, v), qwq.push_back(Edge{u, v, wei[u][v]});
	}
	rep(i, K) for (int j = K; j < n; ++ j) qwq.push_back(Edge{i, j, wei[i][j]});
	static int id[mxn][mxn];
	rep(i, qwq.size()) id[qwq[i].u][qwq[i].v] = i;
	int ans = 0x3f3f3f3f;
	rep(mask, 1 << (K * (K - 1) / 2)) {
		M1 m1;
		M2 m2;
		int cnt = 0, tr_cnt = 0;
		int base = 0;
		bool ok = true;
		rep(i, K) for (int j = i + 1; j < K; ++ j) {
			if (mask >> cnt & 1) {
				Edge e{i, j, wei[i][j]};
				m1.prepare();
				m2.prepare();
				if (!m1.can_insert(e)) ok = false;
				if (!m2.can_insert(e)) ok = false;
				if (!ok) goto FAIL;
				m1.insert(e);
				m2.insert(e);
				++ tr_cnt;
				base += wei[i][j];
			}
			++ cnt;
		}
		FAIL: if (!ok) continue;
		MatroidInter <Edge, M1, M2> mi;
		std::vector <Edge> tr = mi.solve <int> (
			(int) qwq.size(),
			[&] (int x) { return qwq[x]; },
			[&] (Edge x) { return x.w; },
			[&] () { return 0x3f3f3f3f; },
			m1, m2
		);
		int cur = 0;
		rep(i, tr.size()) cur += tr[i].w;
		if (tr_cnt + (int) tr.size() == n - 1) {
			/*
			eprintf("%d %d\n", cur, base);
			rep(i, tr.size()) eprintf("%d %d %d\n", tr[i].u + 1, tr[i].v + 1, tr[i].w);
			int temp = 0;
			rep(i, K) for (int j = i + 1; j < K; ++ j) {
				if (mask >> temp & 1) eprintf("%d %d %d\n", i + 1, j + 1, wei[i][j]);
				++ temp;
			}
			*/
			ans = std::min(ans, cur + base);
		}
	}
	printf("%d\n", ans);
	return 0;
}