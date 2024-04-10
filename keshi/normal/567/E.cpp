#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll inf = 1e18;

#define pb push_back
#define F first
#define S second

ll n, m, d[2][maxn], s, t, h[maxn], l[maxn];

pair<pll, ll> e[maxn];

bool vis[maxn], f[maxn];

vector<pll> gin[maxn], gout[maxn], gp[maxn];

priority_queue<pll> q;

void dfs(ll v, ll p){
	ll u, c;
	l[v] = inf;
	vis[v] = 1;
	for(ll i = 0; i < gp[v].size(); i++){
		u = gp[v][i].F;
		c = gp[v][i].S;
		if(!vis[u]){
			h[u] = h[v] + 1;
			dfs(u, c);
			if(l[u] <= h[v]) f[c] = 0;
			l[v] = min(l[v], l[u]);
		}
		else if(c != p){
			l[v] = min(l[v], h[u]);
			f[c] = 0;
		}
	}
	return;
}

int main(){
	ll v, u, c;
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	cin >> n >> m;
	cin >> s >> t;

	for(ll i = 0; i < m; i++){
		cin >> v >> u >> c;
		e[i].F.F = v;
		e[i].F.S = u;
		e[i].S = c;
		gout[v].pb({u, c});
		gin[u].pb({v, c});
	}

	fill(d[0], d[0] + n + 1, inf);
	fill(vis, vis + n + 1, 0);

	d[0][s] = 0;
	q.push({-d[0][s], s});

	while(!q.empty()){
		v = q.top().S;
		q.pop();
		if(vis[v]) continue;
		for(ll i = 0; i < gout[v].size(); i++){
			u = gout[v][i].F;
			c = gout[v][i].S;
			if(d[0][u] > d[0][v] + c){
				d[0][u] = d[0][v] + c;
				q.push({-d[0][u], u});
			}
		}
	}

	fill(d[1], d[1] + n + 1, inf);
	fill(vis, vis + n + 1, 0);

	d[1][t] = 0;
	q.push({-d[1][t], t});

	while(!q.empty()){
		v = q.top().S;
		q.pop();
		if(vis[v]) continue;
		for(ll i = 0; i < gin[v].size(); i++){
			u = gin[v][i].F;
			c = gin[v][i].S;
			if(d[1][u] > d[1][v] + c){
				d[1][u] = d[1][v] + c;
				q.push({-d[1][u], u});
			}
		}
	}

	for(ll i = 0; i < m; i++){
		v = e[i].F.F;
		u = e[i].F.S;
		c = e[i].S;
		if(d[0][v] + c + d[1][u] == d[0][t]){
			gp[v].pb({u, i});
			gp[u].pb({v, i});
			f[i] = 1;
		}
	}

	fill(vis, vis + n + 1, 0);
	dfs(s, 0);

	for(ll i = 0; i < m; i++){
		if(f[i]) cout << "YES\n";
		else{
			v = e[i].F.F;
			u = e[i].F.S;
			c = e[i].S;
			if(d[0][t] - 1 - (d[0][v] + d[1][u]) > 0) cout << "CAN " << c - d[0][t] + 1 + (d[0][v] + d[1][u]) << '\n';
			else cout << "NO\n";
		}
	}

	return 0;
}