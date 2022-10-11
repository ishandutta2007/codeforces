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

ll n, m, s, l, dis[maxn], v, u, c, ans;

bool vis[maxn];

pair<pll, ll> e[maxn];

vector<pll> g[maxn];

priority_queue<pll> q;

int main(){
	fast_io;
	
	cin >> n >> m >> s;
	
	for(ll i = 0; i < m; i++){
		cin >> e[i].F.F >> e[i].F.S >> e[i].S;
		g[e[i].F.F].pb({e[i].F.S, e[i].S});
		g[e[i].F.S].pb({e[i].F.F, e[i].S});
	}
	
	cin >> l;
	
	fill(dis, dis + n + 1, inf);
	dis[s] = 0;
	q.push({-dis[s], s});
	
	while(!q.empty()){
		v = q.top().S;
		q.pop();
		if(vis[v]) continue;
		vis[v] = 1;
		for(ll i = 0; i < g[v].size(); i++){
			u = g[v][i].F;
			c = g[v][i].S;
			if(dis[v] + c < dis[u]){
				dis[u] = dis[v] + c;
				q.push({-dis[u], u});
			}
		}
	}
	
	for(ll i = 1; i <= n; i++){
		if(dis[i] == l){
			ans++;
		}
	}
	
	for(ll i = 0; i < m; i++){
		v = e[i].F.F;
		u = e[i].F.S;
		c = e[i].S;
		if(0 < l - dis[v] && l - dis[v] < c){
			if(2 * l <= dis[v] + dis[u] + c) ans++;
		}
		if(0 < l - dis[u] && l - dis[u] < c){
			if(2 * l < dis[u] + dis[v] + c) ans++;
		}
	}
	
	cout << ans;
	
	return 0;
}