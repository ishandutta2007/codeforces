//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 110;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, c[2][maxn], d[2][maxn], v, u, ans;

bool vis[maxn];

vector<ll> g[maxn], h[2][maxn];

queue<ll> q;

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	q.push(1);
	vis[1] = 1;
	
	while(!q.empty()){
		v = q.front();
		q.pop();
		h[0][d[0][v]].pb(v);
		for(ll i = 0; i < g[v].size(); i++){
			u = g[v][i];
			if(!vis[u]){
				d[0][u] = d[0][v] + 1;
				vis[u] = 1;
				q.push(u);
			}
		}
	}
	
	fill(vis, vis + n, 0);
	
	q.push(n);
	vis[n] = 1;
	
	while(!q.empty()){
		v = q.front();
		q.pop();
		h[1][d[1][v]].pb(v);
		for(ll i = 0; i < g[v].size(); i++){
			u = g[v][i];
			if(!vis[u]){
				d[1][u] = d[1][v] + 1;
				vis[u] = 1;
				q.push(u);
			}
		}
	}
	
	c[0][1] = 1;
	
	for(ll i = 0; i < maxn; i++){
		for(ll j = 0; j < h[0][i].size(); j++){
			v = h[0][i][j];
			for(ll k = 0; k < g[v].size(); k++){
				u = g[v][k];
				if(d[0][v] > d[0][u]){
					c[0][v] += c[0][u];
				}
			}
		}
	}
	
	c[1][n] = 1;
	
	for(ll i = 0; i < maxn; i++){
		for(ll j = 0; j < h[1][i].size(); j++){
			v = h[1][i][j];
			for(ll k = 0; k < g[v].size(); k++){
				u = g[v][k];
				if(d[1][v] > d[1][u]){
					c[1][v] += c[1][u];
				}
			}
		}
	}
	
	ans = c[0][n];
	
	for(ll i = 2; i < n; i++){
		if(d[0][i] + d[1][i] <= d[0][n]) ans = max(ans, 2 * c[0][i] * c[1][i]);
	}
	
	cout << setprecision(10);
	
	cout << ld(ans) / ld(c[0][n]);
	
	return 0;
}