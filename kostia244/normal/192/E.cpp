#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
const ll mod = 696969569;
using oset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int maxn = 1 << 17;
struct segtree {
	int n, tree[maxn<<2], lazy[maxn<<2];
	void init(int sz) {
		n = sz;
		memset(tree, 0, sizeof tree);
		memset(lazy, 0, sizeof lazy);
	}
	void push(int v, int l, int r) {
		if(!lazy[v]) return;
		tree[v] += (r-l+1) * lazy[v];
		if(l!=r) {
			lazy[v<<1]+=lazy[v];
			lazy[v<<1|1]+=lazy[v];
		}
		lazy[v] = 0;
	}
	void upd(int l, int r, int x) {
		upd(1, 1, n, l, r, x);
	}
	void upd(int v, int l, int r, int ql, int qr, int x) {
		push(v,l,r);
		if(l > qr || r < ql) return;
		if(ql<=l&&r<=qr) {
			lazy[v] += x;
			push(v, l, r);
			return;
		}
		int mid = (l+r)>>1;
		upd(v<<1, l, mid, ql, qr, x);
		upd(v<<1|1, mid+1, r, ql, qr, x);
	}
	int get(int i) {
		return get(1, 1, n, i);
	}
	int get(int v, int l, int r, int i) {
		push(v, l, r);
		if(l > i|| r < i) return 0;
		if(l==r) return tree[v];
		int mid = (l+r)>>1;
		return get(v<<1, l, mid, i)+get(v<<1|1, mid+1, r, i);
	}
};

int n, timer = 0;
vvi g;
vi ein, eout, sz, head, p;
vector<pair<int, int>> ans;
segtree st;

bool par(int x, int y) {
	return ein[x] <= ein[y] && ein[y] <= eout[x];
}

void dfs_sz(int v, int par) {
	sz[v] = 1;
	p[v] = par;
	for (auto &i : g[v]) {
		if (i == par)
			continue;
		dfs_sz(i, v);
		sz[v] += sz[i];
		if (g[v][0] == par || sz[i] >= sz[g[v][0]])
			swap(g[v][0], i);
	}
}

void dfs_hld(int v, int p) {
	ein[v] = ++timer;

	for (auto i : g[v]) {
		if (i == p)
			continue;
		head[i] = (i == g[v][0] ? head[v] : i);
		dfs_hld(i, v);
	}

	eout[v] = timer;
}

void init_hld() {
	dfs_sz(1, 1);

	head[1] = 1;
	dfs_hld(1, 1);

	st.init(n);
}
void init() {
	cin >> n;
	g.resize(n + 1);
	p.resize(n + 1);
	sz.resize(n + 1);
	ein.resize(n + 1);
	eout.resize(n + 1);
	head.resize(n + 1);

	for (int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		ans.pb({f, t});
		g[f].pb(t);
		g[t].pb(f);
	}

	init_hld();
}
void go(int &x, int &y) {
	while(!par(head[x], y)) {
		st.upd(ein[head[x]], ein[x], 1);
		x = p[head[x]];
	}
}
void add(int x, int y) {
	if(x==y)return;
	int ans = 0;
	go(x, y);
	go(y, x);
	if(!par(x, y)) swap(x, y);
	st.upd(ein[x], ein[y], 1);
	st.upd(ein[x], ein[x], -1);
}
void solve() {
	int m;
	cin >> m;
	for(int x, y, i = 0; i < m; i++) {
		cin >> x >> y;
		add(x, y);
	}
	for(auto i : ans) {
		if(!par(i.second, i.first)) swap(i.first, i.second);
		cout << st.get(ein[i.first]) << " ";
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	solve();
}