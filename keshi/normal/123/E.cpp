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

ll n, m, sz[maxn], d[maxn], s[maxn], a[maxn], b[maxn], ans, x, y;

bool vis[maxn];

vector<ll> g[maxn];

void dfs(ll v){
	ll u;
	vis[v] = 1;
	s[v] = a[v];
	sz[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]){
			dfs(u);
			sz[v] += sz[u];
			s[v] += s[u];
			ans += b[v] * s[u] * sz[u];
		}
	}
	ans += b[v] * (x - s[v]) * (n - sz[v]);
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cout << setprecision(20) << fixed;
	
	cin >> n;
	
	for(ll i = 1; i < n; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
		x += a[i];
		y += b[i];
	}
	
	dfs(1);
	
	cout << ans * 1.000000 / (x * y);
	
	return 0;
}