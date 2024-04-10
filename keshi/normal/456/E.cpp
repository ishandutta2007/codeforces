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

ll n, m, q, t, p[maxn], par[maxn], dis[maxn], d[maxn], r[maxn];

bool vis[maxn], mark[maxn];

vector<ll> g[maxn], a[maxn], pa;

void dfs1(ll v){
	ll u;
	vis[v] = 1;
	a[t].pb(v);
	p[v] = t;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]){
			dis[u] = dis[v] + 1;
			dfs1(u);
		}
	}
	return;
}

void dfs2(ll v){
	ll u;
	mark[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!mark[u]){
			par[u] = v;
			dis[u] = dis[v] + 1;
			dfs2(u);
		}
	}
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n >> m >> q;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	for(ll i = 1; i <= n; i++){
		if(!vis[i]){
			dfs1(i);
			v = i;
			for(ll j = 0; j < a[t].size(); j++){
				u = a[t][j];
				if(dis[u] > dis[v]) v = u;
			}
			dis[v] = 0;
			dfs2(v);
			for(ll j = 0; j < a[t].size(); j++){
				u = a[t][j];
				if(dis[u] > dis[v]) v = u;
			}
			pa.clear();
			while(v){
				pa.pb(v);
				v = par[v];
			}
			d[t] = ll(pa.size() - 1);
			r[t] = pa[pa.size() / 2];
			t++;
		}
	}
	
	while(q--){
		cin >> t;
		if(t == 1){
			cin >> v;
			cout << d[p[v]] << '\n';
		}
		else{
			cin >> v >> u;
			v = p[v];
			u = p[u];
			if(v == u) continue;
			if(a[v].size() < a[u].size()) swap(v, u);
			d[v] = max((d[v] + 1) / 2 + 1 + (d[u] + 1) / 2, max(d[v], d[u]));
			if(max((d[v] + 1) / 2, (d[u] + 1) / 2 + 1) > max((d[u] + 1) / 2, (d[v] + 1) / 2 + 1)) r[v] = r[u];
			for(ll i = 0; i < a[u].size(); i++){
				a[v].pb(a[u][i]);
				p[a[u][i]] = v;
			}
		}
	}
	
	return 0;
}