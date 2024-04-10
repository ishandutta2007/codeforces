//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 510;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, v, u, c, a[maxn][maxn], d[maxn][maxn];

bool vis[maxn];

vector<pll> g[maxn];

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u >> c;
		g[v].pb({u, c});
		g[u].pb({v, c});
		d[v][u] = min(d[v][u], c);
	}
	
	for(ll i = 1; i <= n; i++){
		fill(d[i], d[i] + n + 1, inf);
		fill(vis, vis + n + 1, 0);
		d[i][i] = 0;
		for(ll j = 0; j < n; j++){
			v = 0;
			for(ll k = 1; k <= n; k++){
				if(!vis[k]){
					if(v == 0 || d[i][v] > d[i][k]) v = k;
				}
			}
			vis[v] = 1;
			for(ll k = 0; k < g[v].size(); k++){
				u = g[v][k].F;
				c = g[v][k].S;
				if(d[i][u] > d[i][v] + c){
					d[i][u] = d[i][v] + c;
					a[i][u] = 0;
				}
				if(d[i][u] == d[i][v] + c){
					a[i][u]++;
				}
			}
		}
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = i + 1; j <= n; j++){
			c = 0;
			for(ll k = 1; k <= n; k++){
				if(d[i][j] == d[i][k] + d[k][j]){
					c += a[i][k] + a[j][k];
				}
			}
			cout << c / 2 << " ";
		}
	}
	
	return 0;
}