// In the name of GOD
#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 200;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll n, m, q;
bool vis[MAXN];

vector<ll> g[MAXN][MAXN];

void dfs(ll v, ll c){
	ll u;
	vis[v] = 1;
	for(ll i = 0; i < g[c][v].size(); i++){
		u = g[c][v][i];
		if(!vis[u]){
			dfs(u, c);
		}
	}
	return;
}

int main(){
	fast_io;
	ll u, v, c;
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> u >> v >> c;
		g[c][v].pb(u);
		g[c][u].pb(v);
	}
	
	cin >> q;
	
	for(ll i = 0; i < q; i++){
		cin >> u >> v;
		c = 0;
		for(ll i = 1; i <= m; i++){
			fill(vis + 1, vis + n + 1, 0);
			dfs(u, i);
			if(vis[v]){
				c++;
			}
		}
		cout << c << endl;
	}
	
	return 0;
}