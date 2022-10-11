#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, q, vis[maxn], dp[maxn][2];
vector<pll> g[maxn];

void dfs(ll v){
	ll u, w;
	vector<ll> c;
	vis[v] = 1;
	dp[v][1] = 0;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		w = g[v][i].S;
		if(vis[u]) continue;
		dfs(u);
		dp[v][1] += dp[u][0];
		if(dp[u][1] + w > dp[u][0]){
			c.pb(dp[u][1] + w - dp[u][0]);
		}
	}
	sort(c.begin(), c.end(), greater<ll>());
	for(ll i = 0; i < k - 1 && i < c.size(); i++){
		dp[v][1] += c[i];
	}
	dp[v][0] = dp[v][1];
	if(k - 1 < c.size()){
		dp[v][0] += c[k - 1];
	}
	return;
}

int main(){
	fast_io;
	ll v, u, w;
	
	cin >> q;
	
	while(q--){
		cin >> n >> k;
		fill(vis, vis + n + 1, 0);
		for(ll i = 1; i <= n; i++){
			g[i].clear();
		}
		for(ll i = 1; i < n; i++){
			cin >> v >> u >> w;
			g[v].pb({u, w});
			g[u].pb({v, w});
		}
		dfs(1);
		cout << max(dp[1][0], dp[1][1]) << endl;
	}
	
	return 0;
}