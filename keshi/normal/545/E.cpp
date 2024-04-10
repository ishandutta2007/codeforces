//In the name of GOD
//Harsh Revenge
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, root, dis[maxn], par[maxn], v, u, c, ans;

bool vis[maxn];

pair<pll, ll> e[maxn];

vector<pll> g[maxn];

priority_queue<pll> q;

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 1; i <= m; i++){
		cin >> e[i].F.F >> e[i].F.S >> e[i].S;
		g[e[i].F.F].pb({e[i].F.S, i});
		g[e[i].F.S].pb({e[i].F.F, i});
	}
	cin >> root;
	
	fill(dis, dis + n + 1, inf);
	dis[root] = 0;
	q.push({-dis[root], root});
	
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
			else if(dis[v] + c == dis[u]){
				if(e[par[u]].S > c) par[u] = g[v][i].S;
			}
		}
	}
	
	for(ll i = 1; i <= n; i++){
		if(par[i]){
			ans += e[par[i]].S;
		}
	}
	
	cout << ans << '\n';
	
	
	for(ll i = 1; i <= n; i++){
		if(par[i]){
			cout << par[i] << " ";
		}
	}
	
	return 0;
}