//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, dsu[maxn], t, st[maxn], ft[maxn], seg[maxn], ans;

vector<pll> e[maxn];

vector<ll> g[maxn];

void init(){
	for(ll i = 1; i <= n; i++){
		dsu[i] = i;
	}
}

ll par(ll v){
	if(dsu[v] != v) dsu[v] = par(dsu[v]);
	return dsu[v];
}

void dfs(ll v){
	st[v] = t++;
	for(ll i = 0; i < g[v].size(); i++){
		dfs(g[v][i]);
	}
	ft[v] = t;
}

void upd(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[id] += x;
		return;
	}
	ll mid = (s + e) / 2;
	upd(id * 2, s, mid, l, r, x);
	upd(id * 2 + 1, mid, e, l, r, x);
	return;
}

ll get(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return 0;
	if(l <= s && e <= r) return seg[id];
	ll mid = (s + e) / 2;
	return get(id * 2, s, mid, l, r) + get(id * 2 + 1, mid, e, l, r) + seg[id];
}

int main(){
	ll v, u, x;
	fast_io;
	
	cin >> n;
	
	init();
	
	for(ll i = 1; i <= n; i++){
		cin >> k;
		for(ll j = 0; j < k; j++){
			cin >> v >> u;
			e[i].pb({v, u});
			g[i].pb(par(v));
			dsu[par(v)] = i;
		}
	}
	
	for(ll i = 1; i <= n; i++){
		if(dsu[i] == i) dfs(i);
	}
	
	init();
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j < e[i].size(); j++){
			v = e[i][j].F;
			u = e[i][j].S;
			x = get(1, 0, n, st[v], st[v] + 1);
			v = par(v);
			upd(1, 0, n, st[v], ft[v], (x + u) % mod);
			ans += (x + u) % mod;
			ans %= mod;
			dsu[v] = i;
		}
	}
	
	cout << (ans + mod) % mod;
	
	return 0;
}