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
using pi = pair<int, int>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 105, mod = 1e9 + 7;
const ld tau = 6.28318530717958647692;
const ld A = 2.5*tau - 20.;
const ld B = 5.0*tau - 20.;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
	int n, m;
	cin >> n >> m;
	vvi g(n+1);
	vi u(n+1);
	for(int i = 1; i <= n; i++) cin >> u[i];
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[t].pb(f);
	}
	map<vi, ll> c;
	for(ll t, i = 1; i <= n; i++) {
		if(!g[i].size()) continue;
		sort(all(g[i]));
		g[i].erase(unique(all(g[i])), g[i].end());
		c[g[i]] += u[i];
	}
	ll gc = 0;
	for(auto i : c) gc = __gcd(gc, i.second);
	cout << gc << '\n';
	}
}