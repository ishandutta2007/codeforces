#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define R first
#define L second

ll n, ans;
vector<ll> g[MAXN];
bool vis[MAXN];

ll dfs(ll v){
	ll u, c = 1;
	vis[v] = 1;
	
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]){
			c += dfs(u);
		}
	}
	if(c % 2){
		return c;
	}
	if(v != 1){
		ans++;
	}
	return 0;
}

int main(){
	fast_io;
	ll u, v;
	
	cin >> n;
	
	for(ll i = 1; i < n; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	if(dfs(1)){
		ans = -1;
	}
	
	cout << ans;
	
	return 0;
}