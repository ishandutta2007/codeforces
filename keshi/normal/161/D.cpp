//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e4 + 100;
const ll maxk = 510;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, dp[maxn][maxk], pd[maxn][maxk], par[maxn], ans;

bool vis[maxn];

vector<ll> g[maxn];

void sfd(ll v){
	for(ll i = 1; i <= k; i++){
		if(v == 1) continue;
		pd[v][i] = pd[par[v]][i - 1] + dp[par[v]][i - 1];
		if(i >= 2){
			pd[v][i] -= dp[v][i - 2];
		}
	}
	for(ll i = 0; i < g[v].size(); i++){
		ll u = g[v][i];
		if(u != par[v]){
			sfd(u);
		}
	}
	return;
}

void dfs(ll v){
	vis[v] = 1;
	dp[v][0] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		ll u = g[v][i];
		if(!vis[u]){
			par[u] = v;
			dfs(u);
			for(ll i = 1; i <= k; i++){
				dp[v][i] += dp[u][i - 1];
			}
		}
	}
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n >> k;
	
	for(ll i = 1; i < n; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	dfs(1);
	sfd(1);
	
	for(ll i = 1; i <= n; i++){
		ans += dp[i][k] + pd[i][k];
	}
	
	cout << ans / 2;
	
	return 0;
}