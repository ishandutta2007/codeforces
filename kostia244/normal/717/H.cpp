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
const int mod = 1e9 + 7;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct dsu {
	vi r, p;
	void init(int n) {
		r.assign(n+1, 0);
		p.resize(n+1);
		for(int i = 0; i <= n; i++) p[i] = i;
	}
	int par(int i) {
		if(i == p[i]) return i;
		return p[i] = par(p[i]);
	}
	void unite(int i, int j) {
		i = par(i), j = par(j);
		if(i == j) return;
		if(r[i] < r[j]) swap(i, j);
		p[j] = i;
		r[i] += r[i] == r[j];
	}
	bool same(int i, int j) {
		return par(i) == par(j);
	}
};
int n, e;
vector<pair<int, int>> g;
vvi u;
vi perm;
#define tm tmworz
int tm[100100], co[10001000];
dsu d;
vi a, b;
vi t;
int ord() {
	fill(co, co+1000100, 1);
	a.clear();
	b.clear();
	t.clear();
	d.init(1000100);
	int c = 1;
	for(auto i : perm) {
		if(c++ <= n/2) {
		int ok = 0;
		for(auto j : u[i]) {
			if(d.same(0, j)) {
				ok = 1;
				tm[i] = j;
				break;
			}
		}
		if(!ok) {
			int q = rng()%u[i].size();
			t.pb(q);
			tm[i] = u[i][q];
			d.unite(0, u[i][q]);
		}
		a.pb(i);
		} else {
		int ok = 0;
		for(auto j : u[i]) {
			if(!d.same(0, j)) {
				ok = 1;
				tm[i] = j;
				co[j] = 2;
				break;
			}
		}
		if(ok) b.pb(i);
		else a.pb(i),
				tm[i] = u[i][0];
		}
	}
	d.init(n);
	for(auto i : a) d.unite(i, a.back());
	for(auto i : b) d.unite(i, b.back());
	int cc = 0;
	for(auto i : g) {
		cc += !d.same(i.first, i.second);
	}
	return cc;
}
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> e;
	for(int f, t, i = 0; i < e; i++) {
		cin >> f >> t;
		g.pb({f, t});
	}
	u.resize(n+1);
	int mx = 0;
	for(int l, t, i = 1; i <= n; i++) {
		cin >> l;
		while(l--) {
			cin >> t;
			tm[i] = i;
			mx = max(mx, t);
			u[i].pb(t);
		}
		perm.pb(i);
	}
	for(int i = 1; i <= 1000000; i++) co[i] = 1;
	while(true) {
		shuffle(all(perm), rng);
		if(ord()>=(e+1)/2) {
			for(int i = 1; i <= n; i++) cout << tm[i] << " ";cout << "\n";
			for(int i = 1; i <= mx; i++) cout << co[i] << " ";
			return 0;
		}
	}
}