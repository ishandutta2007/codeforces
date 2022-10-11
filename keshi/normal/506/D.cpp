//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll tof = 300;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, q, t;

bool vis[maxn];

vector<pll> e[maxn], mp[maxn];

vector<ll> g[maxn], a, b[maxn], o;

void dfs(ll v, ll c){
	ll u;
	o.pb(v);
	vis[v] = 1;
	mp[c].pb({v, t});
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]) dfs(u, c);
	}
	return;
}

int main(){
	ll v, u, c;
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u >> c;
		e[c].pb({v, u});
	}
	
	for(ll i = 1; i <= m; i++){
		if(e[i].empty()) continue;
		if(e[i].size() > tof){
			a.pb(i);
		}
		for(ll j = 0; j < e[i].size(); j++){
			v = e[i][j].F;
			u = e[i][j].S;
			g[v].pb(u);
			g[u].pb(v);
			vis[v] = 0;
			vis[u] = 0;
		}
		t = 1;
		for(ll j = 0; j < e[i].size(); j++){
			v = e[i][j].F;
			if(!vis[v]){
				o.clear();
				dfs(v, i);
				t++;
				if(e[i].size() <= tof){
					for(ll k = 0; k < o.size(); k++){
						for(ll p = 0; p < o.size(); p++){
							b[o[k]].pb(o[p]);
						}
					}
				}
			}
		}
		for(ll j = 0; j < e[i].size(); j++){
			v = e[i][j].F;
			u = e[i][j].S;
			g[v].clear();
			g[u].clear();
		}
		sort(mp[i].begin(), mp[i].end());
	}
	
	for(ll i = 1; i <= n; i++){
		sort(b[i].begin(), b[i].end());
	}
	
	cin >> q;
	
	while(q--){
		cin >> v >> u;
		c = upper_bound(b[v].begin(), b[v].end(), u) - lower_bound(b[v].begin(), b[v].end(), u);
		for(ll i = 0; i < a.size(); i++){
			if(lower_bound(mp[a[i]].begin(), mp[a[i]].end(), make_pair(v, -1ll)) -> F == v && lower_bound(mp[a[i]].begin(), mp[a[i]].end(), make_pair(u, -1ll)) -> F == u && lower_bound(mp[a[i]].begin(), mp[a[i]].end(), make_pair(v, -1ll)) -> S == lower_bound(mp[a[i]].begin(), mp[a[i]].end(), make_pair(u, -1ll)) -> S){
				c++;
			}
		}
		cout << c << '\n';
	}
	
	return 0;
}