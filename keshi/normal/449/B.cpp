//In the name of GOD
//Harsh Revenge
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, k, dis[maxn], par[maxn], v, u, c, ans;

bool vis[maxn];

pair<pll, ll> e[maxn];

vector<pll> g[maxn];

priority_queue<pll> q;

int main(){
	fast_io;
	
	cin >> n >> m >> k;
	
	for(ll i = 0; i < m; i++){
		cin >> e[i].F.F >> e[i].F.S >> e[i].S;
		g[e[i].F.F].pb({e[i].F.S, i});
		g[e[i].F.S].pb({e[i].F.F, i});
	}
	
	for(ll i = m; i < m + k; i++){
		e[i].F.F = 1;
		cin >> e[i].F.S >> e[i].S;
		g[e[i].F.F].pb({e[i].F.S, i});
		g[e[i].F.S].pb({e[i].F.F, i});
	}
	
	fill(dis, dis + n + 1, inf);
	dis[1] = 0;
	q.push({-dis[1], 1});
	
	while(!q.empty()){
		v = q.top().S;
		q.pop();
		if(vis[v]) continue;
		vis[v] = 1;
		for(ll i = 0; i < g[v].size(); i++){
			u = g[v][i].F;
			c = e[g[v][i].S].S;
			if(dis[v] + c < dis[u]){
				dis[u] = dis[v] + c;
				par[u] = g[v][i].S;
				q.push({-dis[u], u});
			}
			else if(dis[v] + c == dis[u] && g[v][i].S < m){
				par[u] = g[v][i].S;
			}
		}
	}
	
	ans = k;
	
	for(ll i = 1; i <= n; i++){
		if(par[i] >= m){
			ans--;
		}
	}
	
	cout << ans;
	
	return 0;
}