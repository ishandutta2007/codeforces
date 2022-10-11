#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 5e5 + 100;

#define pb push_back
#define F first
#define S second

ll n, m, s, t, ds, dt, c, si[maxn], ti[maxn];

bool vis[maxn];

vector<ll> g[maxn], b;

vector<pll> e;

void dfs1(ll v){
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++) if(!vis[g[v][i]]) dfs1(g[v][i]);
	return;
}

void dfs(ll v){
	ll u;
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]){
			e.pb({v, u});
			dfs(u);
		}
		if(u == s){
			si[c] = v;
		}
		if(u == t){
			ti[c] = v;
		}
	}
	return;
}

int main(){
	ll v, u;
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	dfs1(1);
	
	if(*min_element(vis + 1, vis + n + 1) == 0){
		cout << "No";
		return 0;
	}
	
	fill(vis, vis + maxn, 0);
	
	cin >> s >> t >> ds >> dt;
	
	vis[s] = 1;
	vis[t] = 1;
	
	for(ll i = 1; i <= n; i++){
		if(!vis[i]){
			dfs(i);
			c++;
		}
	}
	
	for(ll i = 0; i < c; i++){
		if(si[i] && ti[i]){
			b.pb(i);
		}
		else if(si[i]){
			ds--;
			e.pb({s, si[i]});
		}
		else{
			dt--;
			e.pb({t, ti[i]});
		}
	}
	
	if(b.empty()){
		ds--;
		dt--;
		e.pb({s, t});
	}
	else{
		ds--;
		dt--;
		e.pb({s, si[b[0]]});
		e.pb({t, ti[b[0]]});
	}
	
	for(ll i = 1; i < b.size(); i++){
		if(ds > 0){
			ds--;
			e.pb({s, si[i]});
		}
		else if(dt > 0){
			dt--;
			e.pb({t, ti[i]});
		}
		else{
			cout << "No";
			return 0;
		}
	}
	if(ds < 0 || dt < 0){
		cout << "No";
		return 0;
	}
	
	cout << "Yes" << endl;
	
	for(ll i = 0; i < e.size(); i++){
		cout << e[i].F << " " << e[i].S << '\n';
	}
	
	return 0;
}