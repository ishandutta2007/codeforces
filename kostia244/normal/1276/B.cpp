#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct dsu {
	vi r, p, m;
	void init(int n) {
		r.assign(n+1, 1);
		m.assign(n+1, 0);
		p.assign(n+1, 0);
		for(int i = 1; i <= n; i++) p[i] = i;
	}
	int par(int i) {
		if(i==p[i]) return i;
		return p[i] = par(p[i]);
	}
	void unite(int i, int j) {
		i = par(i), j = par(j);
		if(i==j) return;
		if(r[i] < r[j]) swap(i, j);
		p[j] = i;
		r[i] += r[j];
	}
	ll sz(int i) {
		return r[par(i)];
	}
};
ll n, m, x, y;
vector<vi> g;
vector<pi> e;
dsu d;
void read() {
	cin >> n >> m >> x >> y;
	g.assign(n+1, {});
	e.clear();
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		e.pb({f, t});
		g[f].pb(t);
		g[t].pb(f);
	}
}
void init() {
	d.init(n);
	d.r[x]=d.r[y]=0;
	for(auto i : e) {
		if(i.first==x||i.first==y) continue;
		if(i.second==x||i.second==y) continue;
		d.unite(i.first, i.second);
	}
}
void add(int x, int y, int a) {
	for(auto i : g[x]) {
		i = d.par(i);
		d.m[i]|=a;
	}
}
void solve() {
	read();
	ll ans = (n-2)*(n-3)/2;
	init();
	for(int i = 1; i <= n; i++) if(i!=x&&i!=y&&i==d.par(i)) ans -= d.sz(i)*(d.sz(i)-1)/2;
	add(x, y, 1);
	add(y, x, 2);
	vi a[4];
	for(int i = 1; i <= n; i++) {
		if(i==x||i==y||i!=d.par(i)) continue;
		a[d.m[i]].pb(i);
	}

	ll qq, cur;

	cur = 0;
	for(auto i : a[1]) ans -= cur*d.sz(i), cur += d.sz(i);
	qq = cur;

	cur = 0;
	for(auto i : a[2]) ans -= cur*d.sz(i), cur += d.sz(i);
	qq+=cur;

	cur = 0;
	for(auto i : a[3]) ans -= cur*d.sz(i), ans -= qq*d.sz(i), cur += d.sz(i);

	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}