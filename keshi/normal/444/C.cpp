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

ll n, m, seg[maxn], c[maxn];

pll lz[maxn];

void upd(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r && c[id] != -1){
		lz[id].F += abs(c[id] - x);
		lz[id].S = x;
		seg[id] += (e - s) * abs(c[id] - x);
		c[id] = x;
		return;
	}
	ll mid = (s + e) / 2;
	if(lz[id].F){
		seg[id * 2 + 1] += (e - mid) * lz[id].F;
		seg[id * 2] += (mid - s) * lz[id].F;
		c[id * 2] = lz[id].S;
		c[id * 2 + 1] = lz[id].S;
		lz[id * 2].F += lz[id].F;
		lz[id * 2 + 1].F += lz[id].F;
		lz[id * 2].S = lz[id].S;
		lz[id * 2 + 1].S = lz[id].S;
	}
	lz[id].F = 0;
	lz[id].S = -1;
	upd(id * 2, s, mid, l, r, x);
	upd(id * 2 + 1, mid, e, l, r, x);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
	if(c[id * 2] == c[id * 2 + 1]) c[id] = c[id * 2];
	else c[id] = -1;
	return;
}

ll get(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return 0;
	if(l <= s && e <= r) return seg[id];
	ll mid = (s + e) / 2;
	if(lz[id].F){
		seg[id * 2 + 1] += (e - mid) * lz[id].F;
		seg[id * 2] += (mid - s) * lz[id].F;
		c[id * 2] = lz[id].S;
		c[id * 2 + 1] = lz[id].S;
		lz[id * 2].F += lz[id].F;
		lz[id * 2 + 1].F += lz[id].F;
		lz[id * 2].S = lz[id].S;
		lz[id * 2 + 1].S = lz[id].S;
	}
	lz[id].F = 0;
	lz[id].S = -1;
	return get(id * 2, s, mid, l, r) + get(id * 2 + 1, mid, e, l, r);
}

int main(){
	ll l, r, x;
	fast_io;
	
	fill(c, c + maxn, 0);
	
	cin >> n >> m;
	
	for(ll i = 1; i <= n; i++){
		upd(1, 0, n, i - 1, i, i);
	}
	
	fill(seg, seg + maxn, 0);
	
	for(ll i = 0; i < m; i++){
		cin >> x >> l >> r;
		if(x == 1){
			cin >> x;
			upd(1, 0, n, l - 1, r, x);
		}
		else cout << get(1, 0, n, l - 1, r) << '\n';
	}
	
	return 0;
}