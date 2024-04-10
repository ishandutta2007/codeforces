//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 5e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, t, n1, n2, n3, c[2][maxn], d[maxn], par[maxn][maxn], s[maxn];
bool f, vis[maxn];
vector<ll> g[maxn];
vector<ll> a[2][maxn];

void dfs(ll v){
	ll u;
	vis[v] = 1;
	c[d[v]][t]++;
	a[d[v]][t].pb(v);
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]) d[u] = 1 - d[v], dfs(u);
		else if(d[v] == d[u]) f = 1;
	}
	return;
}

int main(){
	fast_io;
	ll v, u;
	
	cin >> n >> m >> n1 >> n2 >> n3;
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	for(ll i = 1; i <= n; i++){
		if(!vis[i]){
			t++;
			dfs(i);
		}
	}
	if(f){
		cout << "NO\n";
		return 0;
	}
	par[0][0] = 1;
	for(ll i = 1; i <= t; i++){
		for(ll j = 0; j <= n; j++){
			if(j >= c[0][i] && par[i - 1][j - c[0][i]]) par[i][j] = 1;
			if(j >= c[1][i] && par[i - 1][j - c[1][i]]) par[i][j] = 2;
		}
	}
	
	if(par[t][n2] == 0){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	ll x = t;
	while(x){
		if(par[x][n2] == 1){
			n2 -= c[0][x];
			for(ll i = 0; i < a[0][x].size(); i++){
				s[a[0][x][i]] = 2;
			}
		}
		else{
			n2 -= c[1][x];
			for(ll i = 0; i < a[1][x].size(); i++){
				s[a[1][x][i]] = 2;
			}
		}
		x--;
	}
	
	for(ll i = 1; i <= n; i++){
		if(s[i] == 0){
			if(n1){
				s[i] = 1;
				n1--;
			}
			else{
				s[i] = 3;
				n3--;
			}
		}
		cout << s[i];
	}
	
	return 0;
}