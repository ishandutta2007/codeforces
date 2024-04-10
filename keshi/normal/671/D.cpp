//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, dp[maxn], d[maxn], a[maxn], f[maxn];
bool vis[maxn], val;
vector<ll> g[maxn];
vector<pll> q[maxn];
set<pll> s[maxn];

void dfs(ll v){
	ll u;
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]){
			d[u] = d[v] + 1;
			dfs(u);
		}
	}
	return;
}

void solve(ll v){
	ll u, c = 0;
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(vis[u]) continue;
		solve(u);
		while(!s[u].empty() && f[s[u].begin() -> S] > d[v]) s[u].erase(s[u].begin());
		if(s[u].empty()){
			val = 1;
			return;
		}
		dp[u] = s[u].begin() -> F + a[u];
		a[u] -= dp[u];
		if(s[v].size() < s[u].size()) s[v].swap(s[u]), swap(a[v], a[u]);
		for(set<pll>::iterator it = s[u].begin(); it != s[u].end(); it++){
			s[v].insert(Mp(it -> F + a[u] - a[v], it -> S));
		}
		c += dp[u];
		s[u].clear();
	}
	for(ll i = 0; i < q[v].size(); i++){
		s[v].insert(Mp(q[v][i].F - a[v], q[v][i].S));
	}
	a[v] += c;
	return;
}

int main(){
	ll v, u, c;
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 1; i < n; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	dfs(1);
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u >> c;
		if(d[v] < d[u]) swap(v, u);
		f[i] = d[u];
		q[v].pb(Mp(c, i));
	}
	
	fill(vis, vis + maxn, 0);
	solve(1);
	
	if(val){
		cout << -1;
		return 0;
	}
	
	c = 0;
	for(ll i = 0; i < g[1].size(); i++){
		u = g[1][i];
		c += dp[u];
	}
	cout << c;
	
	return 0;
}