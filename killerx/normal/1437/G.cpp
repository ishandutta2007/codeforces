#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

#define endl '\n'

struct SEG {
	static const int mxn = 1 << 20;

	int mx[mxn << 1];

	void init() {
		memset(mx, -1, sizeof(mx));
	}

	void upd(int x, int v) {
		mx[x += mxn] = v;
		for (; x >>= 1; mx[x] = max(mx[x << 1], mx[x << 1 | 1]));
	}

	int qry(int l, int r) {
		int ans = -1;
		for (l += mxn, r += mxn; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ans = max(ans, mx[l ++]);
			if (r & 1) ans = max(ans, mx[-- r]);
		}
		return ans;
	}
} seg;

struct TREE {
	static const int mxn = 6e5 + 5;

	int fa[mxn], top[mxn];
	int sz[mxn], son[mxn];
	int dfn[mxn], ed[mxn], tme;
	vector <int> g[mxn];

	void dfs0(int u) {
		sz[u] = 1;
		rep(i, g[u].size()) {
			int v = g[u][i];
			fa[v] = u;
			dfs0(v);
			sz[u] += sz[v];
		}
		son[u] = -1;
		rep(i, g[u].size()) {
			int v = g[u][i];
			if (son[u] == -1 || sz[v] > sz[son[u]])
				son[u] = v;
		}
	}

	void dfs1(int u) {
		dfn[u] = tme ++;
		if (u && u == son[fa[u]])
			top[u] = top[fa[u]];
		else
			top[u] = u;
		if (son[u] != -1)
			dfs1(son[u]);
		rep(i, g[u].size()) {
			int v = g[u][i];
			if (v != son[u])
				dfs1(v);
		}
		ed[u] = tme;
	}

	void build(int n, const vector <pair <int, int> > &E) {
		rep(i, E.size()) {
			int u = E[i].first - 1;
			int v = E[i].second - 1;
			g[u].pb(v);
		}
		dfs0(0);
		dfs1(0);
		seg.init();
	}

	void upd(int u, int v) {
		-- u;
		seg.upd(dfn[u], v);
	}

	int qry(int u) {
		-- u;
		int ans = -1;
		while (top[u]) {
			ans = max(ans, seg.qry(dfn[top[u]], dfn[u] + 1));
			u = fa[top[u]];
		}
		ans = max(ans, seg.qry(dfn[0], dfn[u] + 1));
		return ans;
	}
} tree;

struct SAM {
	static const int sigma = 26;
	static const int mxn = 6e5 + 5;

	int ord(char ch) {
		return ch - 'a';
	}

	int go[mxn][sigma];
	int len[mxn];
	int link[mxn];
	int tot, lst;

	void init() {
		tot = lst = 1;
	}

	void add(int ch) {
		int p = lst, np = ++ tot;
		lst = np;
		len[np] = len[p] + 1;
		while (p && !go[p][ch])
			go[p][ch] = np, p = link[p];
		if (!p)
			link[np] = 1;
		else {
			int q = go[p][ch];
			if (len[q] == len[p] + 1)
				link[np] = q;
			else {
				int nq = ++ tot;
				len[nq] = len[p] + 1;
				memcpy(go[nq], go[q], sizeof(go[q]));
				link[nq] = link[q];
				link[q] = link[np] = nq;
				while (go[p][ch] == q)
					go[p][ch] = nq, p = link[p];
			}
		}
	}

	void add(const string &s) {
		rep(i, s.size())
			add(ord(s[i]));
		lst = 1;
	}

	int get(const string &s) {
		int u = 1;
		rep(i, s.size()) {
			int ch = ord(s[i]);
			u = go[u][ch];
		}
		return u;
	}

	vector <pair <int, int> > print() {
		vector <pair <int, int> > E;
		for (int i = 2; i <= tot; ++ i)
			E.pb(mp(link[i], i));
		return E;
	}
} sam;

const int mxn = 6e5 + 5;

int n, m;
int x[mxn], val[mxn];
string name[mxn];
set <pair <int, int> > st[mxn];

struct Query {
	int type;
	string name;
	int i, x;
} q[mxn];

void upd(int x, int i, int v) {
	if (st[x].find(mp(val[i], i)) != st[x].end())
		st[x].erase(mp(val[i], i));
	val[i] = v;
	st[x].insert(mp(val[i], i));
	tree.upd(x, st[x].rbegin()->first);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	rep(i, n)
		cin >> name[i];
	sam.init();
	rep(i, m) {
		cin >> q[i].type;
		if (q[i].type == 1) {
			cin >> q[i].i >> q[i].x;
			-- q[i].i;
		}
		else {
			cin >> q[i].name;
			sam.add(q[i].name);
		}
	}

	tree.build(sam.tot, sam.print());
	rep(i, n) {
		x[i] = sam.get(name[i]);
		if (x[i])
			upd(x[i], i, 0);
	}

	rep(i, m) {
		if (q[i].type == 1) {
			if (x[q[i].i])
				upd(x[q[i].i], q[i].i, q[i].x);
		}
		else {
			int ans = -1;
			int u = 1;
			rep(j, q[i].name.size()) {
				int ch = sam.ord(q[i].name[j]);
				u = sam.go[u][ch];
				ans = max(ans, tree.qry(u));
			}
			cout << ans << endl;
		}
	}

	return 0;
}