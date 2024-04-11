#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 998244353;
const int maxn = 2e5 + 33;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, k;
vvi dp;
vector<vector<pair<ll, ll>>> g;

void dfs(ll v, ll p = 0) {
	ll ans = 0;
	vector<pair<ll, ll>> a;
	for(auto to : g[v]) {
		ll i = to.first;
		if(i == p) continue;
		dfs(i, v);
		ans += dp[i][0];
		if(dp[i][0] > to.second+dp[i][1]) {
		} else {
			a.pb({-dp[i][0]+dp[i][1]+to.second, i});
		}
	}
	sort(all(a), greater<pair<ll, ll>>());
	dp[v][0]=dp[v][1]=ans;
	for(int i = 0; i < a.size(); i++) {
		if(i < k) {
			dp[v][0] += max(0ll, a[i].first);
		}
	}
	for(int i = 0; i < a.size(); i++) {
		if(i+1 < k) {
			dp[v][1] += max(0ll, a[i].first);
		}
	}
}

void solve() {
	cin >> n >> k;
	g.assign(n+1, {});
	dp.assign(n+44, vi(2, 0));
	for(ll f, t, c, i = 1; i < n; i++) {
		cin >> f >> t >> c;
		g[f].pb({t, c});
		g[t].pb({f, c});
	}
	dfs(1);
	cout << dp[1][0] << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int q;
	cin >> q;
	while(q--) solve();
}