//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, x, t[maxn];

bool vis[maxn];

vector<ll> g[maxn], a;
vector<pll> b;
vector<pair<ll, pll> > ans;

void dfs(ll v){
	vis[v] = 1;
	t[x++] = v;
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
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	for(ll i = 1; i <= n; i++){
		if(!vis[i]){
			x = 0;
			dfs(i);
			if(x > 3){
				cout << -1;
				return 0;
			}
			if(x == 1){
				a.pb(t[0]);
			}
			else if(x == 2){
				b.pb({t[0], t[1]});
			}
			else{
				ans.pb({t[0], {t[1], t[2]}});
			}
		}
	}
	
	if(b.size() > a.size()){
		cout << -1;
		return 0;
	}
	for(ll i = 0; i < b.size(); i++){
		ans.pb({a[i], b[i]});
	}
	for(ll i = b.size(); i < a.size(); i += 3){
		ans.pb({a[i], {a[i + 1], a[i + 2]}});
	}
	
	for(ll i = 0; i < ans.size(); i++){
		cout << ans[i].F << " " << ans[i].S.F << " " << ans[i].S.S << endl;
	}
	
	return 0;
}