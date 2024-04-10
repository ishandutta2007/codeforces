//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 110;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, q;

pll p[maxn];

bool vis[maxn];

vector<ll> g[maxn];

void dfs(ll v){
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		ll u = g[v][i];
		if(!vis[u]){
			dfs(u);
		}
	}
	return;
}

int main(){
	ll u, v;
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> q >> v >> u;
		if(q == 1){
			p[n].F = v;
			p[n].S = u;
			for(ll i = 0; i < n; i++){
				if(p[i].F < v && v < p[i].S || p[i].F < u && u < p[i].S){
					g[n].pb(i);
				}
				if(v < p[i].F && p[i].F < u || v < p[i].S && p[i].S < u){
					g[i].pb(n);
				}
			}
			n++;
		}
		else{
			fill(vis, vis + n, 0);
			v--;
			u--;
			dfs(v);
			if(vis[u]) cout << "YES";
			else cout << "NO";
			cout << endl;
		}
	}
	
	return 0;
}