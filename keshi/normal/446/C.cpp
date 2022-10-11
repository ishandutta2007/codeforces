//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 3e5 + 100;
const ll mod = 1e9 + 9;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, m, seg[maxn * 4], f[maxn], a[maxn];
pll lz[maxn * 4];

ll cals(pll x, ll t){
	return ((f[t + 1] - 1) * x.F + (f[t + 2] - 1) * x.S) % mod;
}
pll caln(pll x, ll t){
	return Mp((f[t - 1] * x.F + f[t] * x.S) % mod, (f[t] * x.F + f[t + 1] * x.S) % mod);
}

void bld(ll id, ll s, ll e){
	if(e - s == 1){
		seg[id] = a[s];
		return;
	}
	ll mid = (s + e) / 2;
	bld(id * 2, s, mid);
	bld(id * 2 + 1, mid, e);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
	if(seg[id] >= mod) seg[id] -= mod;
	return;
}

void upd(ll id, ll s, ll e, ll l, ll r, pll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		x = caln(x, s - l);
		seg[id] = (seg[id] + cals(x, e - s)) % mod;
		lz[id].F = (lz[id].F + x.F) % mod;
		lz[id].S = (lz[id].S + x.S) % mod;
		return;
	}
	ll mid = (s + e) / 2;
	seg[id * 2] = (seg[id * 2] + cals(lz[id], mid - s)) % mod;
	lz[id * 2].F = (lz[id * 2].F + lz[id].F) % mod;
	lz[id * 2].S = (lz[id * 2].S + lz[id].S) % mod;
	lz[id] = caln(lz[id], mid - s);
	seg[id * 2 + 1] = (seg[id * 2 + 1] + cals(lz[id], e - mid)) % mod;
	lz[id * 2 + 1].F = (lz[id * 2 + 1].F + lz[id].F) % mod;
	lz[id * 2 + 1].S = (lz[id * 2 + 1].S + lz[id].S) % mod;
	lz[id] = Mp(0ll, 0ll);
	upd(id * 2, s, mid, l, r, x);
	upd(id * 2 + 1, mid, e, l, r, x);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
	if(seg[id] >= mod) seg[id] -= mod;
	return;
}

ll get(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return 0;
	if(l <= s && e <= r) return seg[id];
	ll mid = (s + e) / 2;
	seg[id * 2] = (seg[id * 2] + cals(lz[id], mid - s)) % mod;
	lz[id * 2].F = (lz[id * 2].F + lz[id].F) % mod;
	lz[id * 2].S = (lz[id * 2].S + lz[id].S) % mod;
	lz[id] = caln(lz[id], mid - s);
	seg[id * 2 + 1] = (seg[id * 2 + 1] + cals(lz[id], e - mid)) % mod;
	lz[id * 2 + 1].F = (lz[id * 2 + 1].F + lz[id].F) % mod;
	lz[id * 2 + 1].S = (lz[id * 2 + 1].S + lz[id].S) % mod;
	lz[id] = Mp(0ll, 0ll);
	ll x = get(id * 2, s, mid, l, r) + get(id * 2 + 1, mid, e, l, r);
	if(x >= mod) x -= mod;
	return x;
}

int main(){
	fast_io;
	ll t, l, r;
	
	f[1] = 1;
	for(ll i = 2; i < maxn; i++){
		f[i] = f[i - 1] + f[i - 2];
		if(f[i] >= mod) f[i] -= mod;
	}
	cin >> n >> m;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	bld(1, 0, n);
	for(ll i = 0; i < m; i++){
		cin >> t >> l >> r;
		if(t == 2) cout << get(1, 0, n, l - 1, r) << '\n';
		else upd(1, 0, n, l - 1, r, Mp(0, 1));
	}
	
	return 0;
}