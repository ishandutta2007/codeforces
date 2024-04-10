#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
const int INF = 1e9;

#define ll int
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, u, v, c, ans;
bool visited[MAXN], rl[MAXN], f;
vector< pll > g[MAXN];
vector< pair< pll, ll > > e;
priority_queue < pair< pll, bool> > Cost;

int main(){
	ll t, o;
	fast_io;
	cin >> n >> m;
	for (ll i = 0; i < m; i++){
		cin >> u >> v >> c;
		g[u].pb({v, c});
		g[v].pb({u, c});
		e.pb({{u, v}, c});
		if(i == 0){
			t = u;
			o = v;
			visited[t] = 1;
			rl[t] = 0;
			visited[o] = 1;
			rl[o] = 1;
		}
	}
	for(ll i = 0; i < g[t].size(); i++){
		u = g[t][i].F;
		c = g[t][i].S;
		if(!visited[u]){
			Cost.push({{-c, u}, 0});
		}
	}
	for(ll i = 0; i < g[o].size(); i++){
		u = g[o][i].F;
		c = g[o][i].S;
		if(!visited[u]){
			Cost.push({{-c, u}, 1});
		}
	}
	while (!Cost.empty()){
		u = Cost.top().F.S;
		//cout << Cost.top().F.F << "_" << Cost.top().F.S << " " << Cost.top().S << endl;
		if(visited[u]){
			Cost.pop();
			continue;
		}
		rl[u] = Cost.top().S;
		Cost.pop();
		visited[u] = 1;
		for(ll i = 0; i < g[u].size(); i++){
			v = g[u][i].F;
			c = g[u][i].S;
			if(!visited[v]){
				Cost.push({{-c, v}, rl[u]});
			}
		}
	}
	ans = INF;
	for(ll i = 1; i < m; i++){
		u = e[i].F.F;
		v = e[i].F.S;
		c = e[i].S;
		if(rl[u] != rl[v]){
			ans = min(ans, c);
		}
	}
	cout << ans;
	return 0;
}