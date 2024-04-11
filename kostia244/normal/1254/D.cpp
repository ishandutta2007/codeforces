#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const int mod = 998244353;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void norm(int &x) {
	if (x >= mod)
		x -= mod;
	if (x < 0)
		x += mod;
}
struct fenwick {
	vi tree;
	void init(int n) {
		tree.resize(n + 1);
	}
	void add(int i, int x) {
		while (i < tree.size()) {
			tree[i] += x;
			norm(tree[i]);
			i += i & -i;
		}
	}
	void add(int l, int r, int x) {
		add(l, x);
		add(r + 1, -x);
	}
	int get(int i) {
		int ans = 0;
		while (i) {
			ans += tree[i];
			norm(ans);
			i -= i & -i;
		}
		return ans;
	}
};
int bp(int a, int p) {
	int r = 1;
	while (p) {
		if (p & 1)
			r = (r * 1ll * a) % mod;
		a = (a * 1ll * a) % mod;
		p >>= 1;
	}
	return r;
}
int n, q, timer = 0, invN;
vvi g;
vi ein, eout, head, par, sz, lazy;
fenwick f;
void rem(vi& a, int x) {
	for (auto &i : a)
		if (i == x)
			swap(i, a.back());
	a.pop_back();
}
void predfs(int v = 1, int p = 1) {
	if (v != p)
		rem(g[v], p);
	sz[v] = 1;
	for (auto &i : g[v]) {
		par[i] = v;
		predfs(i, v);
		sz[v] += sz[i];
		if (sz[i] > sz[g[v][0]])
			swap(g[v][0], i);
	}
}
void dfs(int v = 1) {
	ein[v] = ++timer;
	for (auto i : g[v]) {
		head[i] = i == g[v][0] ? head[v] : i;
		dfs(i);
	}
	eout[v] = timer;
}
void init() {
	invN = bp(n, mod - 2);
	f.init(n);
	for (auto* i : { &ein, &eout, &head, &par, &sz, &lazy })
		i->resize(n + 1);
	par[1] = -1;
	predfs();
	head[1] = 1;
	dfs();
}
void upd(int v, int d) {
	lazy[v] += d;
	norm(lazy[v]);
	if (!g[v].empty()) {
		int t = ((n - sz[g[v][0]]) * 1ll * invN) % mod;
		t = (t * 1ll * d) % mod;
		f.add(ein[g[v][0]], eout[g[v][0]], t);
	}
	f.add(ein[v], ein[v], d);
	if (par[v] > 0) {
		int t = (sz[v] * 1ll * invN) % mod;
		t = (t * 1ll * d) % mod;
		f.add(1, n, t);
		f.add(ein[v], eout[v], -t);
	}
}
void get(int v) {
	ll ans = f.get(ein[v]);
//	cout << v << ":\n";
	while (par[head[v]] != -1) {
		int t = ((n - sz[head[v]]) * 1ll * invN) % mod;
		t = (t * 1ll * lazy[par[head[v]]]) % mod;
		ans += t;
		if (ans >= mod)
			ans -= mod;
//		cout << head[v] << " ";
		v = par[head[v]];
//		cout << v << "\n";
	}
	cout << ans << "\n";
}
void solve() {
	int t, v, d;
	while (q--) {
		cin >> t >> v;
		if (t == 1) {
			cin >> d;
			upd(v, d);
		} else {
			get(v);
		}
	}
}
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	g.resize(n + 1);
	for (int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	init();
	solve();
}