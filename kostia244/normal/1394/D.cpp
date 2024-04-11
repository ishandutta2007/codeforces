#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<19;
const ll inf = 1ll<<40;
using state = array<ll, 3>;
ll n, a[maxn], h[maxn];
vector<int> g[maxn];
state def {inf, inf, inf};
state dfs(int v) {//{up, no, down}
	state dp = {inf, inf, inf};
	ll cur_val = 0;
	vector<ll> uptodown;
	for(auto i : g[v]) {
		g[i].erase(find(all(g[i]), v));
		auto t = dfs(i);
		
		ll cup   = h[i] > h[v] ? inf : min(t[0], t[1]+a[i]);
		ll cdown = h[i] < h[v] ? inf : min(t[2], t[1]+a[i]);
		
		cur_val += cup;
		uptodown.push_back(-cup+cdown);
	}
	sort(all(uptodown));
	for(int down = 0; down <= g[v].size(); down++) {
		int up = g[v].size() - down;
		
		if(up) dp[0] = min(dp[0], cur_val + max(up-1, down)*a[v] + a[v]);
		dp[1] = min(dp[1], cur_val + max(up, down)*a[v]);
		if(down) dp[2] = min(dp[2], cur_val + max(up, down-1)*a[v] + a[v]);
		
		if(down < g[v].size()) cur_val += uptodown[down];
	}
	return dp;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> h[i];
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	auto t = dfs(1);
	cout << *min_element(all(t)) << '\n';
}