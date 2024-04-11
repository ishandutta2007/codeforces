#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,popcnt,sse4.1,sse4.2,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<19, mod = 998244353 , lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct segtree {
	struct node {
		ll sm, lazy;
		node(ll x = 0) : sm(x), lazy(0) {}
	};
	node merge(const node &a, const node &b) {
		return node(a.sm + b.sm);
	}
	vector<node> t;
	int n;
	void init(int _n) {
		n = _n;
		t.resize(4*n + 5);
	}
	void push(int v, int l, int r) {
		if(t[v].lazy) {
			t[v].sm += t[v].lazy*(r - l + 1);
			if(l != r) {
				t[v << 1].lazy += t[v].lazy;
				t[v << 1 | 1].lazy += t[v].lazy;
			}
			t[v].lazy = 0;
		}
	}
	void add(int ql, int qr, int x, int v, int l, int r) {
		push(v, l, r);
		if(r < ql || qr < l) return;
		if(ql <= l && r <= qr) {
			t[v].lazy += x;
			push(v, l, r);
			return;
		}
		int mid = (l + r) >> 1;
		add(ql, qr, x, v << 1, l, mid);
		add(ql, qr, x, v << 1 | 1, mid + 1, r);
		t[v] = merge(t[v << 1], t[v << 1 | 1]);
	}
	void add(int ql, int qr, int x) { add(ql, qr, x, 1, 1, n);}
	node get(int ql, int qr, int v, int l, int r) {
		if(r < ql || qr < l) return node();
		if(ql <= l && r <= qr) return t[v];
		int mid = (l + r) >> 1;
		return merge(get(ql, qr, v << 1, l, mid), get(ql, qr, v << 1 | 1, mid + 1, r));
	}
	ll get(int ql, int qr) { return get(ql, qr, 1, 1, n).sm;}
};
ll ans[maxn];
int n;
vi g[maxn];

int sz[maxn], p[maxn], tin[maxn], head[maxn], timer = 0;
vi lst[maxn];

void sizes(int v) {
	sz[v] = 1;
	for(auto &i : g[v]) {
		p[i] = v;
		sizes(i);
		sz[v] += sz[i];
		if(sz[i] > sz[g[v][0]]) swap(i, g[v][0]);
	}
}

int dfs(int v, int h = 0) {
	ans[v] = -(h+1);
	tin[v] = ++timer;
	lst[h].pb(v);
	for(auto &i : g[v]) {
		head[i] = g[v][0]==i?head[v]:i;
		dfs(i, h+1);
	}
}

segtree st;

void add(int v) {
	while(v) {
		st.add(tin[head[v]], tin[v], 1);
		v = p[head[v]];
	}
}

ll get(int v) {
	ll res = 0;
	while(v) {
		res += st.get(tin[head[v]], tin[v]);
		v = p[head[v]];
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int t, i = 1; i <= n; i++) {
		cin >> t;
		g[t].pb(i);
	}
	
	p[1] = 0, sizes(g[0][0]);
	head[1] = 1, dfs(g[0][0]);
	
	st.init(n);
	for(int i = 0; i < n; i++) {
		for(auto j : lst[i]) add(j);
		for(auto j : lst[i]) ans[j] += get(j);
	}
	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
	return 0;
}