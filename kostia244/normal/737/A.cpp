#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 755, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, k, s, t;
vector<ll> g;
vector<array<ll, 2>> a;
bool can(ll x) {
	ll sp = 0;
	for(int i = 1; i < g.size(); i++) {
		ll l = g[i] - g[i-1];
		if(l > x) return 0;
		sp += 2*l - min(x-l, l);
	}
	return sp <= t;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k >> s >> t;
	a.resize(n);
	for(auto &i : a) cin >> i[0] >> i[1];
	g.resize(k);
	for(auto &i : g) cin >> i;
	g.push_back(0), g.push_back(s);
	sort(all(g));
	ll mv = 0;
	for(ll z = 1ll<<50; z>>=1;)
		mv += z*!can(mv+z);
	ll ans = 1ll<<60;
	for(auto i : a) if(i[1] > mv) ans = min(ans, i[0]);
	if(ans == 1ll<<60) ans = -1;
	cout << ans << endl;
}