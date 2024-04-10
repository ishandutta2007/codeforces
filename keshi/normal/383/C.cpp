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

ll n, m, d[maxn], st[2][maxn], ft[2][maxn], t0, t1, seg0[maxn], seg1[maxn], a[maxn];

bool vis[maxn];

vector<ll> g[maxn];

void dfs(ll v){
	ll u;
	vis[v] = 1;
	st[0][v] = t0;
	st[1][v] = t1;
	if(d[v] % 2) t1++;
	else t0++;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]){
			d[u] = d[v] + 1;
			dfs(u);
		}
	}
	ft[0][v] = t0;
	ft[1][v] = t1;
	return;
}

void upd0(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg0[id] += x;
		return;
	}
	ll mid = (s + e) / 2;
	upd0(id * 2, s, mid, l, r, x);
	upd0(id * 2 + 1, mid, e, l, r, x);
	return;
}

void upd1(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg1[id] += x;
		return;
	}
	ll mid = (s + e) / 2;
	upd1(id * 2, s, mid, l, r, x);
	upd1(id * 2 + 1, mid, e, l, r, x);
	return;
}

ll get0(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return 0;
	if(l <= s && e <= r) return seg0[id];
	ll mid = (s + e) / 2;
	return get0(id * 2, s, mid, l, r) + get0(id * 2 + 1, mid, e, l, r) + seg0[id];
}

ll get1(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return 0;
	if(l <= s && e <= r) return seg1[id];
	ll mid = (s + e) / 2;
	return get1(id * 2, s, mid, l, r) + get1(id * 2 + 1, mid, e, l, r) + seg1[id];
}

int main(){
	ll v, u, x;
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(ll i = 1; i < n; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	dfs(1);
	
	for(ll i = 0; i < m; i++){
		cin >> x >> v;
		if(x == 1){
			cin >> x;
			if(d[v] % 2){
				upd0(1, 0, n, st[0][v], ft[0][v], -x);
				upd1(1, 0, n, st[1][v], ft[1][v], x);
			}
			else{
				upd0(1, 0, n, st[0][v], ft[0][v], x);
				upd1(1, 0, n, st[1][v], ft[1][v], -x);
			}
		}
		else{
			if(d[v] % 2) cout << get1(1, 0, n, st[1][v], st[1][v] + 1) + a[v] << '\n';
			else cout << get0(1, 0, n, st[0][v], st[0][v] + 1) + a[v] << '\n';
		}
	}
	return 0;
}