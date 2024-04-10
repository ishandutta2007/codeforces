//In the name of GOD
//Hello Yellow
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

ll n, m, a[maxn];

bool vis[maxn], f;

vector<ll> g[maxn], ans;

void solve(ll v){
	ll u;
	vis[v] = 1;
	ans.pb(v);
	a[v] = 1 - a[v];
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(vis[u]) continue;
		solve(u);
		ans.pb(v);
		a[v] = 1 - a[v];
		if(a[u]){
			ans.pb(u);
			a[u] = 1 - a[u];
			ans.pb(v);
			a[v] = 1 - a[v];
		}
	}
	return;
}

void dfs(ll v){
	ll u;
	vis[v] = 1;
	if(a[v]) f = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]) dfs(u);
	}
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	v = 0;
	for(ll i = 1; i <= n; i++){
		if(!vis[i]){
			f = 0;
			dfs(i);
			if(f){
				if(v){
					cout << -1;
					return 0;
				}
				v = i;
			}
		}
	}
	
	fill(vis, vis + maxn, 0);
	
	solve(v);
	
	if(a[v]) ans.pop_back();
	
	cout << ans.size() << '\n';
	
	for(ll i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}