#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first.first
#define yy first.second
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 1000000007ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
}
template<typename X, typename Y>
istream& operator>>(istream& in, pair<X, Y> a) {
	in >> a.first >> a.second;
	return in;
}
template<typename T>
void getv(T& i) {
	cin >> i;
}
template<typename T, typename... Ns>
void getv(vector<T>& v, int n, Ns... ns) {
	v.resize(n);
	for(auto& i : v)
		getv(i, ns...);
}
typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef ll _I;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <vd> vvd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct dsu {
	vi p, sz;
	dsu(ll n) {
		sz.resize(n+1,1);
		p.resize(n+1);
		for(ll i = 0; i < n; i++) p[i] = i;
	}
	int parent(ll i) {
		if(i == p[i]) return i;
		return p[i] = parent(p[i]);
	}
	ll unite(ll i, ll j) {
		ll x = parent(i), y = parent(j);
		if(x == y) return 0;
		if(sz[x] > sz[y]) swap(x, y);
		p[x] = y;
		ll ans = sz[y]*sz[x];
		sz[y]+=sz[x];
		return ans;
	}
};

ll n, m, f, t;
vvi g;
vpi a;


int main() {
	doin();
	cin >> n >> m;
	g.resize(n+1);
	for(ll i = 1; i <= n; i++)
		cin >> t, a.eb(t, i);
	for(ll i = 1; i <= m; i++) {
		cin >> f >> t;
		if(a[f-1].first > a[t-1].first) swap(f, t);
		g[f].pb(t);
	}
	sort(all(a), greater<pi>());
	ld ans = 0;
	dsu d(n);
	for(int i = 0; i < n; i++) {
		ll lans = 0, sq = 0, t;
		for(auto& j : g[a[i].second]) {
			t = d.unite(a[i].second, j);
			lans += t;
		}
		ans += lans*a[i].first;
	}
	cout << fixed << setprecision(15) << (2.0*ans)/(n-1.0)/(n+0.0);

}