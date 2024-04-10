//In the name of GOD
//Hello Yellow
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 5e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, x;

bool vis[maxn];

pll a[maxn];

vector<ll> g[maxn];

void dfs(ll v){
	ll u;
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]) a[u].F = ++x;
	}
	a[v].S = ++x;
	for(ll i = g[v].size() - 1; i > -1; i--){
		u = g[v][i];
		if(!vis[u]) dfs(u);
	}
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n;
	
	if(n == 1){
		cout << "1 2";
		return 0;
	}
	
	for(ll i = 1; i < n; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	a[1].F = ++x;
	dfs(1);
	
	for(ll i = 1; i <= n; i++){
		cout << a[i].F << " " << a[i].S << '\n';
	}
	
	return 0;
}