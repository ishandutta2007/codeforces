//In the name of GOD
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

ll n, m, d[maxn], a[maxn], b[maxn], s, t, v, u, c;

bool vis[maxn];

vector<pll> gp[maxn], g[maxn];

priority_queue<pll> q;

void f(ll x){
	
	cin >> a[x] >> b[x];
	
	fill(vis, vis + n + 1, 0);
	fill(d, d + n + 1, inf);
	d[x] = 0;
	
	q.push({-d[x], x});
	while(!q.empty()){
		v = q.top().S;
		q.pop();
		if(vis[v]) continue;
		vis[v] = 1;
		if(d[v] <= a[x]){
			g[x].pb({v, b[x]});
		}
		for(ll i = 0; i < gp[v].size(); i++){
			u = gp[v][i].F;
			c = gp[v][i].S;
			if(d[v] + c < d[u]){
				d[u] = d[v] + c;
				q.push({-d[u], u});
			}
		}
	}
	return;
}

int main(){
	fast_io;
	
	cin >> n >> m >> s >> t;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u >> c;
		gp[v].pb({u, c});
		gp[u].pb({v, c});
	}
	
	for(ll i = 1; i <= n; i++){
		f(i);
	}
	
	fill(d, d + n + 1, inf);
	fill(vis, vis + n + 1, 0);
	d[s] = 0;
	
	q.push({-d[s], s});
	
	while(!q.empty()){
		v = q.top().S;
		q.pop();
		if(vis[v]) continue;
		vis[v] = 1;
		for(ll i = 0; i < g[v].size(); i++){
			u = g[v][i].F;
			c = g[v][i].S;
			if(d[v] + c < d[u]){
				d[u] = d[v] + c;
				q.push({-d[u], u});
			}
		}
	}
	
	if(!vis[t]){
		cout << -1;
	}
	else{
		cout << d[t];
	}
	
	return 0;
}