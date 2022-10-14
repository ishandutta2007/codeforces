#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 1e5 + 22, mod = 1e9 + 7;
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
int n;
ll a[maxn], b[maxn], ans[maxn];
LineContainer mx[maxn], mn[maxn];
vi g[maxn];
ll dfs(int v, int p) {
	for(auto i : g[v]) {
		if(i==p) continue;
		dfs(i, v);
		if(mx[i].size() > mx[v].size()) swap(mx[i], mx[v]);
		if(mn[i].size() > mn[v].size()) swap(mn[i], mn[v]);
	}
	for(auto i : g[v]) {
		if(i==p) continue;
		for(auto j : mn[i]) mn[v].add(j.k, j.m);
		for(auto j : mx[i]) mx[v].add(j.k, j.m);
	}
	ll x=0, y=0;
	if(g[v].size()>1||p==v) {
		x = -mn[v].query(a[v]);
		y = mx[v].query(a[v]);
	}
	mx[v].add(b[v], x);
	mn[v].add(-b[v], -x);
	if(x!=y) {
		mx[v].add(b[v], y);
		mn[v].add(-b[v], -y);
	}
	ans[v] = x;
	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	dfs(1, 1);
	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
}