#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<20, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, d;
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> d >> m;
	vector<ll> b, g, pg;
	ll ans = 0;
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		if(t > m) b.push_back(t);
		else g.push_back(t);
	}
	sort(all(b), greater<>());
	sort(all(g));
	pg.push_back(0);
	for(int i = 0; i < g.size(); i++) pg.push_back(pg.back() + g[i]);
	ll cur = 0;
	for(int i = 0; i <= b.size(); i++) {
		ll take = max(0ll, (i-1)*1ll*d);
		ll gd = max((ll)0, take - (int)b.size() + i);
		if(gd > g.size()) continue;
		ans = max(ans, cur + pg.back() - pg[gd]);
		if(i < b.size()) cur += b[i];
	}
	cout << ans << endl;
}