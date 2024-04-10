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
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], t, ans;
pll b[maxn], c[maxn];
bool vis[maxn];
vector<ll> g[maxn];

void dfs(ll v, ll x){
	ll u;
	vis[v] = 1;
	x = min(x, a[v]);
	if(b[v].F == 1 && b[v].S == 0) c[v].F++;
	if(b[v].F == 0 && b[v].S == 1) c[v].S++;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]){
			dfs(u, x);
			c[v].F += c[u].F;
			c[v].S += c[u].S;
		}
	}
	if(c[v].F < c[v].S){
		ans += c[v].F * x;
		c[v].S -= c[v].F;
		c[v].F = 0;
	}
	else{
		ans += c[v].S * x;
		c[v].F -= c[v].S;
		c[v].S = 0;
	}
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n;
	for(ll i = 1; i <= n; i++){
		cin >> a[i] >> b[i].F >> b[i].S;
		if(b[i].F) t++;
		if(b[i].S) t--;
	}
	if(t){
		cout << -1;
		return 0;
	}
	for(ll i = 1; i < n; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	dfs(1, inf);
	cout << 2 * ans;
	
	return 0;
}