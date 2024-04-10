//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, t, c, ans;

bool vis[maxn], val[maxn], f;

vector<ll> g[maxn];

void dfs(ll v){
	ll u;
	vis[v] = 1;
	if(val[v]) f = 1;
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
		val[v] = 1;
		val[u] = 1;
		if(v == u) c++;
		else{
			g[v].pb(u);
			g[u].pb(v);
		} 
	}
	
	for(ll i = 1; i <= n; i++){
		if(!vis[i]){
			f = 0;
			dfs(i);
			if(f) t++;
		}
	}
	
	if(t > 1){
		cout << 0;
		return 0;
	}
	
	for(ll i = 1; i <= n; i++){
		t = g[i].size();
		ans += t * (t - 1) / 2;
	}
	
	cout << ans + (m - c) * c + c * (c - 1) / 2;
	
	return 0;
}