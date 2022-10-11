//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, dis[maxn], ans[maxn], v, u, c, cnt;

pll par[maxn];

pair<pll, ll> e[maxn];

vector<pll> g[maxn];

queue<ll> q;

map<pll, bool> vis;

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> e[i].F.F >> e[i].F.S >> e[i].S;
		g[e[i].F.F].pb({e[i].F.S, e[i].S});
		g[e[i].F.S].pb({e[i].F.F, e[i].S});
		cnt += 1 - e[i].S;
	}
	fill(dis, dis + maxn, inf);
	
	q.push(1);
	dis[1] = 0;
	
	while(!q.empty()){
		v = q.front();
		q.pop();
		for(ll i = 0; i < g[v].size(); i++){
			u = g[v][i].F;
			c = g[v][i].S;
			if(dis[u] > dis[v] + 1){
				dis[u] = dis[v] + 1;
				ans[u] = ans[v] + 1 - c;
				par[u] = {v, c};
				q.push(u);
			}
			if(dis[u] == dis[v] + 1){
				if(ans[u] > ans[v] + 1 - c){
					ans[u] = ans[v] + 1 - c;
					par[u] = {v, c};
				}
			}
		}
	}
	
	v = n;
	
	while(v != 1){
		vis[{v, par[v].F}] = 1;
		vis[{par[v].F, v}] = 1;
		v = par[v].F;
	}
	
	cout << m - dis[n] - cnt + ans[n] * 2 << endl;
	
	for(ll i = 0; i < m; i++){
		if(e[i].S ^ vis[{e[i].F.F, e[i].F.S}]){
			cout << e[i].F.F << " " << e[i].F.S << " " << 1 - e[i].S << '\n';
		}
	}
	
	return 0;
}