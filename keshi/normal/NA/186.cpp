#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;

#define pb push_back
#define F first
#define S second

ll n, m, k, ve, ed;

bool vis[maxn], mark[maxn], val[maxn];

vector<pll> h[maxn];

vector<pair<ll, pll> > g[maxn];

void dfs(ll v, ll p){
	ll u, c;
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		c = g[v][i].S.F;
		if(vis[u]){
			if(c != p){
				ve = v;
				ed = c;
			}
		}
		else{
			dfs(u, c);
		}
	}
	return;
}

void fix(ll v, ll p){
	ll u, c;
	mark[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		c = g[v][i].S.F;
		if(c == p){
			val[c] = 1 - g[v][i].S.S;
		}
		else if(!mark[u]){
			fix(u, c);
		}
	}
	return;
}

int main(){
	ll v, u, x;
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >> n >> m;
	
	for(ll i = 1; i <= n; i++){
		cin >> k;
		for(ll j = 0; j < k; j++){
			cin >> x;
			if(x < 0) h[-x].pb({i, 0});
			else h[x].pb({i, 1});
		}
	}
	
	for(ll i = 1; i <= m; i++){
		if(h[i].empty()) continue;
		if(h[i].size() == 1){
			g[0].pb({h[i][0].F, {i, h[i][0].S}});
			g[h[i][0].F].pb({0, {i, 1 - h[i][0].S}});
		}
		else{
			if(h[i][0].S == h[i][1].S){
				g[0].pb({h[i][0].F, {i, h[i][0].S}});
				g[h[i][0].F].pb({0, {i, 1 - h[i][0].S}});
				g[0].pb({h[i][1].F, {i, h[i][1].S}});
				g[h[i][1].F].pb({0, {i, 1 - h[i][1].S}});
			}
			else{
				g[h[i][0].F].pb({h[i][1].F, {i, h[i][1].S}});
				g[h[i][1].F].pb({h[i][0].F, {i, h[i][0].S}});
			}
		}
	}
	
	fix(0, 0);
	
	for(ll i = 1; i <= n; i++){
		if(!mark[i]){
			ve = 0;
			ed = 0;
			dfs(i, 0);
			if(ve == 0){
				cout << "NO";
				return 0;
			}
			fix(ve, ed);
		}
	}
	
	cout << "YES\n";
	
	for(ll i = 1; i <= m; i++){
		cout << val[i];
	}
}