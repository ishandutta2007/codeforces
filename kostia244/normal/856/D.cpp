#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4.1,sse4.2,popcnt,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
const int maxn = 1<<18;
struct ctx {
	set<pair<ll, ll>> f;
	ll bias = 0;
	void addall(ll x) {
		bias += x;
	}
	bool has(ll i) {
		auto it = f.lower_bound({i, -(1ll<<60)});
		return it != f.end() && it->first == i;
	}
	ll get(ll i) {
		auto it = f.lower_bound({i, -(1ll<<60)});
		return it->second + bias;
	}
	void erase(ll i) {
		auto it = f.lower_bound({i, -(1ll<<60)});
		f.erase(it);
	}
	void merge(ctx &o, ll pen, ll &ans) {
		for(auto &[i, w] : o.f) {
			if(has(i)) {
				ans = max(ans, get(i) + w + o.bias - pen);
				erase(i);
			} else {
				f.insert({i, w+o.bias-bias});
			}
		}
	}
};
ll n, q, dp[maxn];
ctx c[maxn];
vector<ll> g[maxn];
vector<pair<ll, ll>> f[maxn];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> q;
	for(int t, i = 1; i < n; i++) {
		cin >> t;
		g[t].pb(i+1);
	}
	for(int a, b, c, i = 0; i < q; i++) {
		cin >> a >> b >> c;
		f[a].pb({i, c});
		f[b].pb({i, 0});
	}
	ll ans = 0;
	for(int v = n; v; v--) {
		for(auto &i : g[v])
			dp[v] += dp[i];
		for(auto &i : g[v])
			c[i].addall(dp[v]-dp[i]);
		for(auto &i : f[v]) c[v].f.insert(i);
		c[v].addall(dp[v]);
		for(auto &i : g[v]) {
			if(c[i].f.size() > c[v].f.size()) swap(c[i], c[v]);
		}
		ans = dp[v];
		for(auto &i : g[v]) {
			c[v].merge(c[i], dp[v], ans);
		}
		dp[v] = ans;
		//cout << v << " " << dp[v] << " :\n";
		//for(auto &i : c[v].f) cout << i.first << " " << i.second + c[v].bias << '\n';
	}
	cout << ans << '\n';
	return 0;
}