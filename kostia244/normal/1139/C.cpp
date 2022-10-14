#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define __V vector
#define vi __V<ll>
#define pi pair<ll, ll>
#define all(x) x.begin(), x.end()
#define mod 1000000007ll
//using namespace __gnu_pbds;
using namespace std;
ll n, k, u, v, b, ans;
__V<__V<ll>> g;
vi dp;
bitset<100005> vis(0);
ll binpow (ll a, ll n) {
	ll res = 1;
	while (n)
		if (n & 1) {
			res *= a;
			res %= mod;
			--n;
		}
		else {
			a *= a;
			a %= mod;
			n >>= 1;
		}
	res %= mod;
	return res;
}

void dfs(ll v, ll p = 0) {
	dp[v] = 1;
	vis.set(v);
	for(auto& u : g[v]) {
		if(u != p) {
			dfs(u, v);
			dp[v] += dp[u];
		}
	}
}

int main() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
	cin >> n >> k;
	g.resize(n + 1);
	dp.resize(n + 1, 1);
	for(ll i = 1; i < n; i++) {
		cin >> u >> v >> b;
		if(b == 1) continue;
		g[v].pb(u);
		g[u].pb(v);
	}
	ans = binpow(n, k);
	for(ll i = 1; i <= n; i++)
		if(!vis.test(i)) {
			dfs(i);
			ans -= binpow(dp[i], k);
			ans += mod;
			ans %= mod;
			ans += mod;
			ans %= mod;
			ans += mod;
			ans %= mod;
		}
	cout << fixed << ans << "\n";
}