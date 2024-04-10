//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, dsu[maxn], sz[maxn], ans, c, d;

pll a[maxn];

vector<ll> g1[maxn], g2[maxn], vec;

void init(){
    for(ll i = 1; i <= n; i++){
    	dsu[i] = i;
    	sz[i] = 1;
	}
}

ll root(ll i){
	if (dsu[i] == i) return dsu[i];
	dsu[i] = root(dsu[i]);
	return dsu[i];
}

void Union(ll i, ll j){
    ll v = root(i), u = root(j);
    if(v == u) return;
    if(sz[v] > sz[u]) swap(v, u);
	dsu[v] = dsu[u];
	sz[u] += sz[v];
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i].F;
		a[i].S = i;
	}
	
	for(ll i = 1; i < n; i++){
		cin >> v >> u;
		if(a[v].F < a[u].F){
			g2[v].pb(u);
			g1[u].pb(v);
		}
		else if(a[v].F > a[u].F){
			g1[v].pb(u);
			g2[u].pb(v);
		}
		else if(v < u){
			g2[v].pb(u);
			g1[u].pb(v);
		}
		else{
			g1[v].pb(u);
			g2[u].pb(v);
		}
	}
	
	sort(a + 1, a + n + 1);
	init();
	
	for(ll i = 1; i <= n; i++){
		v = a[i].S;
		c = 1;
		for(ll j = 0; j < g1[v].size(); j++){
			u = g1[v][j];
			ans += a[i].F * sz[root(u)] * c;
			c += sz[root(u)];
			Union(v, u);
		}
	}
	
	sort(a + 1, a + n + 1, greater<pll>());
	init();
	
	for(ll i = 1; i <= n; i++){
		v = a[i].S;
		c = 1;
		for(ll j = 0; j < g2[v].size(); j++){
			u = g2[v][j];
			ans -= a[i].F * sz[root(u)] * c;
			c += sz[root(u)];
			Union(v, u);
		}
	}
	
	cout << ans;
	
	return 0;
}