#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<18, mod = 1e9 + 7;
namespace treemx {
int val[maxn], p[maxn][19], mx[maxn][19], h[maxn];
void add(int v, int a, int w) {
	//cout << v << " " << w << " ::::" << endl;
	val[v] = w;
	h[v] = h[a]+1;
	p[v][0] = a;
	mx[v][0] = w;
	for(int i = 1; i < 19; i++) {
		p[v][i] = p[p[v][i-1]][i-1];
		mx[v][i] = max(mx[p[v][i-1]][i-1], mx[v][i-1]);
	}
}
int qry(int u, int v) {
	int ans = -(1<<30);
	if(h[u] < h[v]) swap(u, v);
	int d = h[u]-h[v];
	for(int i = 0; i < 19; i++) if((d>>i)&1) {
		ans = max(ans, mx[u][i]);
		u = p[u][i];
	}
	if(u == v) return ans;
	for(int i = 19;i--;) if(p[u][i] != p[v][i]) {
		ans = max(ans, mx[u][i]);
		ans = max(ans, mx[v][i]);
		u = p[u][i];
		v = p[v][i];
	}
	ans = max(ans, mx[u][0]);
	ans = max(ans, mx[v][0]);
	//cout << u << " " << v << " " << ans << endl;
	return ans;
}
};
struct dsu {
	vector<int> p, r;
	vector<array<int, 2>> mn;
	dsu(int n = 0) : p(n+1), r(n+1, 1), mn(n+1, {0, 0}) { iota(all(p), 0); }
	int par(int i) {
		if(i == p[i]) return i;
		return p[i] = par(p[i]);
	}
	void unite(int i, int j) {
		i = par(i), j = par(j);
		if(i == j) return;
		if(r[i] < r[j]) swap(i, j);
		p[j] = i;
		r[i] += r[j];
		mn[i] = min(mn[i], mn[j]);
	}
	bool con(int i, int j) {
		return par(i) == par(j);
	}
	int rpar(int v) {
		v = par(v);
		return mn[v][1];
	}
};
int n, m;
vector<array<int, 4>> edges;
vector<array<int, 2>> g[maxn];
int h[maxn], p[maxn], pi[maxn], mc[maxn], cst[maxn], of[maxn], ot[maxn], tri[maxn];
void dfs(int v, int pr) {
	for(auto &[i, idx] : g[v]) if(i != pr) {
		h[i] = h[v] + 1;
		p[i] = v;
		pi[i] = idx;
		treemx::add(i, v, cst[idx]);
		dfs(i, v);
	}
}
dsu par;
void push(int &u) {
	u = par.rpar(u);
}
void up(int &u, int C) {
	mc[pi[u]] = C;
	par.unite(p[u], u);
}
void minq(int u, int v, int C) {
	push(u), push(v);
	while(u != v) {
		if(h[u] < h[v]) swap(u, v);
		up(u, C);
		push(u);
	}
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	memset(mc, 0x4f, sizeof mc);
	memset(treemx::mx, -0x4f, sizeof treemx::mx);
	memset(treemx::val, -0x4f, sizeof treemx::val);
	cin >> n >> m;
	for(int c, f, t, i = 0; i < m; i++) {
		cin >> f >> t >> c;
		cst[i] = c;
		of[i] = f;
		ot[i] = t;
		edges.push_back({c, f, t, i});
	}
	sort(all(edges));
	dsu d(n);
	vector<array<int, 3>> o;
	for(auto [c, f, t, i] : edges) if(!d.con(f, t)) {
		d.unite(f, t);
		tri[i] = 1;
		g[f].push_back({t, i}), g[t].push_back({f, i});
	} else o.push_back({c, f, t});
	dfs(1, 1);
	par = dsu(n);
	for(int i = 1; i <= n; i++) par.mn[i] = {h[i], i};
	for(auto [c, f, t] : o) {
		minq(f, t, c);
	}
	for(int i = 0; i < m; i++) {
		if(tri[i]) {
			--mc[i];
			cout << (mc[i] > (1<<30) ? -1 : mc[i]) << " ";
		} else cout << treemx::qry(of[i], ot[i])-1 << " ";
	}
	cout << endl;
}