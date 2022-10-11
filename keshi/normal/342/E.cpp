//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, q, sz[maxn], hide[maxn], h[maxn], d[maxn];
vector<ll> g[maxn];
vector<pll> vec[maxn];

void plant(ll v, ll par = -1){
	sz[v] = 1;
	for(ll u : g[v]){
		if(hide[u] || u == par) continue;
		plant(u, v);
		sz[v] += sz[u];
	}
}
void add(ll v, ll r, ll par = -1){
	sz[v] = 1;
	vec[v].pb(Mp(r, h[v]));
	for(ll u : g[v]){
		if(hide[u] || u == par) continue;
		h[u] = h[v] + 1;
		add(u, r, v);
		sz[v] += sz[u];
	}
}

ll centroid(ll v, ll s, ll par = -1){
	for(ll u : g[v]){
		if(!hide[u] && u != par && sz[u] * 2 > s){
			return centroid(u, s, v);
		}
	}
	return v;
}

void solve(ll v){
	plant(v);
	v = centroid(v, sz[v]);
	h[v] = 0;
	add(v, v);
	hide[v] = 1;
	for(ll u : g[v]){
		if(!hide[u]){
			solve(u);
		}
	}
	return;
}

int main(){
    fast_io;
    
    cin >> n >> q;
    for(ll i = 1; i < n; i++){
    	ll v, u;
    	cin >> v >> u;
    	g[v].pb(u);
    	g[u].pb(v);
	}
	fill(d, d + n + 10, inf);
	solve(1);
	for(pll v : vec[1]){
		d[v.F] = min(d[v.F], v.S);
	}
	while(q--){
		ll t, v;
		cin >> t >> v;
		if(t == 1){
			for(pll u : vec[v]){
				d[u.F] = min(d[u.F], u.S);
			}
		}
		else{
			ll ans = inf;
			for(pll u : vec[v]){
				ans = min(ans, d[u.F] + u.S);
			}
			cout << ans << "\n";
		}
	}
 
    return 0;
}