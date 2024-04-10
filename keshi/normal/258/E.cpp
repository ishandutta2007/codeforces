//In the name of God
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()
#define lc (id << 1)
#define rc (lc | 1)

ll n, m, st[maxn], ft[maxn], t, vis[maxn], ans[maxn];
pll seg[maxn << 2];
ll lz[maxn << 2];
vector<pll> vec[maxn << 2];
vector<ll> g[maxn];

void dfs(ll v){
	vis[v] = 1;
	st[v] = t++;
	for(ll u : g[v]){
		if(!vis[u]) dfs(u);
	}
	ft[v] = t;
	return;
}
void upd(ll id, ll s, ll e, ll l, ll r, pll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		vec[id].pb(x);
		return;
	}
	ll mid = (s + e) >> 1;
	upd(lc, s, mid, l, r, x);
	upd(rc, mid, e, l, r, x);
	return;
}
void bld(ll id, ll s, ll e){
	seg[id] = Mp(0, e - s);
	if(e - s == 1) return;
	ll mid = (s + e) >> 1;
	bld(lc, s, mid);
	bld(rc, mid, e);
	return;
}
void upd2(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[id].F += x;
		lz[id] += x;
		return;
	}
	ll mid = (s + e) >> 1;
	seg[lc].F += lz[id];
	lz[lc] += lz[id];
	seg[rc].F += lz[id];
	lz[rc] += lz[id];
	lz[id] = 0;
	upd2(lc, s, mid, l, r, x);
	upd2(rc, mid, e, l, r, x);
	seg[id].F = min(seg[lc].F, seg[rc].F);
	seg[id].S = 0;
	if(seg[id].F == seg[lc].F) seg[id].S += seg[lc].S;
	if(seg[id].F == seg[rc].F) seg[id].S += seg[rc].S;
	return;
}
void solve(ll id, ll s, ll e){
	for(pll i : vec[id]){
		upd2(1, 0, n, i.F, i.S, 1);
	}
	if(e - s == 1){
		ans[s] = n - seg[1].S;
		if(seg[1].F) ans[s] = n;
	}
	else{
		ll mid = (s + e) >> 1;
		solve(lc, s, mid);
		solve(rc, mid, e);
	}
	for(pll i : vec[id]){
		upd2(1, 0, n, i.F, i.S, -1);
	}
	return;
}

int main(){
    fast_io;
    
    cin >> n >> m;
    for(ll i = 1; i < n; i++){
    	ll v, u;
    	cin >> v >> u;
    	g[v].pb(u);
    	g[u].pb(v);
	}
	dfs(1);
	bld(1, 0, n);
	for(ll i = 0; i < m; i++){
		ll v, u;
		cin >> v >> u;
		upd(1, 0, n, st[v], ft[v], Mp(st[u], ft[u]));
		upd(1, 0, n, st[v], ft[v], Mp(st[v], ft[v]));
		upd(1, 0, n, st[u], ft[u], Mp(st[u], ft[u]));
		upd(1, 0, n, st[u], ft[u], Mp(st[v], ft[v]));
	}
	solve(1, 0, n);
	for(ll i = 1; i <= n; i++){
		if(ans[st[i]]) ans[st[i]]--;
		cout << ans[st[i]] << " ";
	}
 
    return 0;
}