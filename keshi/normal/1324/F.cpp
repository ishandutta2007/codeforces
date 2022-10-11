//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, dp[maxn], pd[maxn];

bool vis[maxn], f[maxn];

vector<ll> g[maxn];

void dfs1(ll v){
	ll u;
	vis[v] = 1;
	if(f[v]) dp[v]++;
	else dp[v]--;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(vis[u]) continue;
		dfs1(u);
		dp[v] += max(0ll, dp[u]);
	}
	return;
}

void dfs2(ll v){
	ll u, s = 0;
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(vis[u]) continue;
		pd[u] = max(0ll, dp[v] + pd[v] - max(0ll, dp[u]));
		dfs2(u);
	}
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> f[i];
	}
	
	for(ll i = 1; i < n; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	dfs1(1);
	
	fill(vis, vis + maxn, 0);
	
	dfs2(1);
	
	for(ll i = 1; i <= n; i++){
		cout << dp[i] + pd[i] << " ";
	}
	
	
	return 0;
}