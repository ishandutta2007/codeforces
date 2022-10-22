#include <bits/stdc++.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

typedef long long ll;
typedef std::pair <int, int> pii;

const int mxn = 1 << 19;
const int lg = 19;

struct TREE {
	int n;
	std::vector <int> adj[mxn];
	int fa[mxn];
	int jump[mxn][lg];
	int sz[mxn], dep[mxn];
	int dfn[mxn], ed[mxn], on[mxn];

	void dfs0(int u, int p) {
		static int tim = 0;
		on[tim] = u;
		dfn[u] = tim ++;
		sz[u] = 1;
		fa[u] = jump[u][0] = u ? p : 0;
		rep(i, lg - 1) jump[u][i + 1] = jump[jump[u][i]][i];
		rep(i, adj[u].size()) {
			int v = adj[u][i];
			if (v == p) continue;
			dep[v] = dep[u] + 1;
			dfs0(v, u);
			sz[u] += sz[v];
		}
		ed[u] = tim;
	}

	void init(int _n, std::vector <int> _adj[]) {
		n = _n;
		rep(i, n) adj[i] = _adj[i];
		dfs0(0, -1);
	}

	int lca(int u, int v) {
		if (dep[u] > dep[v]) std::swap(u, v);
		for (int i = lg - 1; ~i; -- i)
			if ((dep[v] - dep[u]) >> i & 1)
				v = jump[v][i];
		if (u == v) return u;
		for (int i = lg - 1; ~i; -- i)
			if (jump[u][i] != jump[v][i])
				u = jump[u][i],
				v = jump[v][i];
		return fa[u];
	}

	int la(int u, int k) {
		for (int i = lg - 1; ~i; -- i)
			if (k >> i & 1)
				u = jump[u][i];
		return u;
	}

	bool insubt(int u, int v) {
		return dfn[u] <= dfn[v] && ed[v] <= ed[u];
	}
} tree;

struct Counter {
	int n;
	pii pnt[mxn];
	int vec[lg + 1][mxn];

	void reg_point(int x, int y) {
		pnt[n ++] = {x, y};
	}

	void init() {
		std::sort(pnt, pnt + n);
		for (int i = n; i < mxn; ++ i)
			pnt[i] = {mxn, mxn};
		rep(i, mxn) vec[0][i] = pnt[i].second;
		rep(i, lg) for (int j = 0; j < mxn; j += 1 << (i + 1))
			std::merge( vec[i] + j, vec[i] + j + (1 << i),
						vec[i] + j + (1 << i), vec[i] + j + (1 << (i + 1)),
						vec[i + 1] + j);
	}

	inline int Q(int i, int a, int b, int v) {
		return std::lower_bound(vec[i] + a, vec[i] + b, v) - (vec[i] + a);
	}

	int query(int l, int r, int v, int i, int a, int b) {
		if (l <= a && b <= r) return Q(i, a, b, v);
		if (r <= a || b <= l) return 0;
		int m = (a + b) >> 1;
		int lans = query(l, r, v, i - 1, a, m);
		int rans = query(l, r, v, i - 1, m, b);
		return lans + rans;
	}

	int query(int l, int r, int v) {
		l = std::lower_bound(pnt, pnt + n, (pii){l, 0}) - pnt;
		r = std::lower_bound(pnt, pnt + n, (pii){r, 0}) - pnt;
		return query(l, r, v, lg, 0, mxn);
	}
} cnter;

struct SEG {
	struct Node {
		int s;
		Node *ls, *rs;
	};

	void insert(Node *&i, int a, int b, int x) {
		if (!i) i = new Node(), i->s = 0, i->ls = i->rs = NULL;
		i->s += 1;
		if (a + 1 == b) return ;
		int m = (a + b) >> 1;
		if (x < m) insert(i->ls, a, m, x);
		else insert(i->rs, m, b, x);
	}

	int query(Node *i, int a, int b, int l, int r) {
		if (!i) return 0;
		if (r <= a || b <= l) return 0;
		if (l <= a && b <= r) return i->s;
		int m = (a + b) >> 1;
		return query(i->ls, a, m, l, r) + query(i->rs, m, b, l, r);
	}

	void print(Node *i, int a, int b, std::vector <int> &v) {
		if (!i) return ;
		if (a + 1 == b) {
			rep(s, i->s) v.push_back(a);
			return ;
		}
		int m = (a + b) >> 1;
		print(i->ls, a, m, v);
		print(i->rs, m, b, v);
	}
} seg;

int n, q, k;
std::vector <int> adj[mxn];
pii qry[mxn];
ll ans = 0;
std::vector <pii> qon[mxn];
int vec[mxn << 1], vsz;
int stk[mxn], top;
std::vector <int> nadj[mxn];
std::vector <int> info[mxn];
int nwlca;
SEG::Node *rt[mxn];

bool compdfn(int u, int v) { return tree.dfn[u] < tree.dfn[v]; }

void dfs0(int u) {
	int son = -1;
	rep(i, nadj[u].size()) {
		int v = nadj[u][i];
		dfs0(v);
		if (son == -1 || (rt[v] ? rt[v]->s : 0) > (rt[son] ? rt[son]->s : 0)) son = v;
	}
	rt[u] = son == -1 ? NULL : rt[son];
	rep(i, nadj[u].size()) {
		int v = nadj[u][i];
		if (v == son) continue;
		std::vector <int> vec;
		seg.print(rt[v], 0, mxn, vec);
		rep(j, vec.size()) {
			int x = tree.on[vec[j]];
			int ndep = std::max(1, k - (tree.dep[u] - tree.dep[nwlca]));
			if (tree.dep[x] >= tree.dep[nwlca] + ndep) {
				int y = tree.la(x, tree.dep[x] - (tree.dep[nwlca] + ndep));
				if (u != nwlca) ans += seg.query(rt[u], 0, mxn, tree.dfn[y], tree.ed[y]);
			}
		}
		rep(j, vec.size()) {
			seg.insert(rt[u], 0, mxn, vec[j]);
		}
	}
	rep(i, info[u].size()) {
		int x = info[u][i];
		int ndep = std::max(1, k - (tree.dep[u] - tree.dep[nwlca]));
		if (tree.dep[x] >= tree.dep[nwlca] + ndep) {
			int y = tree.la(x, tree.dep[x] - (tree.dep[nwlca] + ndep));
			if (u != nwlca) ans += seg.query(rt[u], 0, mxn, tree.dfn[y], tree.ed[y]);
		}
		seg.insert(rt[u], 0, mxn, tree.dfn[x]);
	}
}

int main() {
	scanf("%d %d %d", &n, &q, &k);
	rep(i, n - 1) {
		int u, v;
		scanf("%d %d", &u, &v);
		-- u, -- v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	rep(i, q) {
		int u, v;
		scanf("%d %d", &u, &v);
		-- u, -- v;
		qry[i] = {u, v};
	}
	tree.init(n, adj);
	rep(i, q) {
		int u = qry[i].first;
		int v = qry[i].second;
		int l = tree.lca(u, v);
		cnter.reg_point(tree.dfn[u], tree.dep[l]);
		cnter.reg_point(tree.dfn[v], tree.dep[l]);
		qon[l].push_back({u, v});
	}
	cnter.init();
	rep(x, n) {
		int a0 = cnter.query(tree.dfn[x], tree.ed[x], tree.dep[x] - k);
		int a1 = cnter.query(tree.dfn[x], tree.ed[x], tree.dep[x] - k + 1);
		ans += ll(a0) * (a1 - a0);
	}
	rep(l, n) {
		std::vector <std::pair <pii, int> > nqon;
		rep(i, qon[l].size()) {
			int u = qon[l][i].first;
			int v = qon[l][i].second;
			int flag = 0;
			if (tree.dep[u] - tree.dep[l] >= k) {
				flag |= 1;
				u = tree.la(u, tree.dep[u] - (tree.dep[l] + k));
			}
			if (tree.dep[v] - tree.dep[l] >= k) {
				flag |= 2;
				v = tree.la(v, tree.dep[v] - (tree.dep[l] + k));
			}
			if (!flag) continue;
			nqon.push_back({{u, v}, flag});
		}
		if (nqon.size() <= 1) continue;
		std::map <int, std::vector <int> > qwq;
		rep(i, nqon.size()) {
			int u = nqon[i].first.first;
			int v = nqon[i].first.second;
			int flag = nqon[i].second;
			if (flag & 1) qwq[u].push_back(v == l ? l : tree.la(v, tree.dep[v] - tree.dep[l] - 1));
			if (flag & 2) qwq[v].push_back(u == l ? l : tree.la(u, tree.dep[u] - tree.dep[l] - 1));
		}
		for (auto x : qwq) {
			int u = x.first;
			std::vector <int> vec = x.second;
			std::sort(vec.begin(), vec.end());
			ans += ll(vec.size()) * (vec.size() - 1) / 2;
			int las = 0;
			rep(i, vec.size()) {
				if (i && vec[i] != vec[i - 1]) {
					if (vec[las] != l) ans -= ll(i - las) * (i - las - 1) / 2;
					las = i;
				}
			}
			if (vec[las] != l) ans -= ll(vec.size() - las) * (vec.size() - las - 1) / 2;
		}
	}
	rep(l, n) {
		if (qon[l].size() <= 1) continue;
		vsz = 0;
		rep(i, qon[l].size()) {
			int u = qon[l][i].first;
			int v = qon[l][i].second;
			vec[vsz ++] = u;
			vec[vsz ++] = v;
		}
		std::sort(vec, vec + vsz, compdfn);
		vsz = std::unique(vec, vec + vsz) - vec;
		int osz = vsz;
		rep(i, osz - 1) vec[vsz ++] = tree.lca(vec[i], vec[i + 1]);
		std::sort(vec, vec + vsz, compdfn);
		vsz = std::unique(vec, vec + vsz) - vec;
		rep(i, vsz) nadj[vec[i]].clear();
		top = 0;
		rep(i, vsz) {
			int u = vec[i];
			while (top >= 1 && !tree.insubt(stk[top - 1], u)) -- top;
			if (top) nadj[stk[top - 1]].push_back(u);
			stk[top ++] = u;
		}
		rep(i, vsz) info[vec[i]].clear();
		rep(i, qon[l].size()) {
			int u = qon[l][i].first;
			int v = qon[l][i].second;
			if (u == l || v == l) continue;
			if (tree.dfn[u] > tree.dfn[v]) std::swap(u, v);
			info[u].push_back(v);
		}
		nwlca = l;
		dfs0(vec[0]);
	}
	printf("%lld\n", ans);
	return 0;
}