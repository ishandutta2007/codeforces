#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 1<<17, mod = 1e9 + 7;
int n, m;
vector<array<int, 2>> g[maxn];
int good, vis[maxn];
void dfs(int v) {
	for(auto [i, c] : g[v]) {
		if(vis[i]) good &= (vis[v]^c) == vis[i];
		else {
			vis[i] = vis[v]^c;
			dfs(i);
		}
	}
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int f, t, c, i = 0; i < m; i++) {
		cin >> f >> t >> c; c ^= 1; c *= 3;
		g[f].push_back({t, c});
		g[t].push_back({f, c});
	}
	ll ans = 1;
	for(int i = 1; i <= n; i++) if(!vis[i]) {
		vis[i] = good = 1;
		dfs(i);
		ans = ans*good*2ll%mod;
	}
	ans = (ans * 1ll * (mod+1)/2)%mod;
	cout << ans << endl;
}