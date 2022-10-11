//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e5 + 100;
const ll mod = 95542721;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, a[maxn], seg[maxn][48], lz[maxn];

void bld(ll id, ll s, ll e){
	if(e - s == 1){
		seg[id][0] = a[s];
		for(ll i = 1; i < 48; i++){
			seg[id][i] = (((seg[id][i - 1] * seg[id][i - 1]) % mod) * seg[id][i - 1]) % mod;
		}
		return;
	}
	ll mid = (s + e) / 2;
	bld(id * 2, s, mid);
	bld(id * 2 + 1, mid, e);
	for(ll i = 0; i < 48; i++){
		seg[id][i] = seg[id * 2][i] + seg[id * 2 + 1][i];
		if(seg[id][i] >= mod) seg[id][i] -= mod;
	}
	return;
}
void upd(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		lz[id]++;
		rotate(seg[id], seg[id] + 1, seg[id] + 48);
		return;
	}
	ll mid = (s + e) / 2;
	lz[id * 2] += lz[id];
	rotate(seg[id * 2], seg[id * 2] + lz[id] % 48, seg[id * 2] + 48);
	lz[id * 2 + 1] += lz[id];
	rotate(seg[id * 2 + 1], seg[id * 2 + 1] + lz[id] % 48, seg[id * 2 + 1] + 48);
	lz[id] = 0;
	upd(id * 2, s, mid, l, r);
	upd(id * 2 + 1, mid, e, l, r);
	for(ll i = 0; i < 48; i++){
		seg[id][i] = seg[id * 2][i] + seg[id * 2 + 1][i];
		if(seg[id][i] >= mod) seg[id][i] -= mod;
	}
	return;
}

ll get(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return 0;
	if(l <= s && e <= r) return seg[id][0];
	ll mid = (s + e) / 2;
	lz[id * 2] += lz[id];
	rotate(seg[id * 2], seg[id * 2] + lz[id] % 48, seg[id * 2] + 48);
	lz[id * 2 + 1] += lz[id];
	rotate(seg[id * 2 + 1], seg[id * 2 + 1] + lz[id] % 48, seg[id * 2 + 1] + 48);
	lz[id] = 0;
	return (get(id * 2, s, mid, l, r) + get(id * 2 + 1, mid, e, l, r)) % mod;
}

int main(){
	fast_io;
	ll t, l, r;
	
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	bld(1, 0, n);
	cin >> m;
	for(ll i = 0; i < m; i++){
		cin >> t >> l >> r;
		if(t == 1) cout << get(1, 0, n, l - 1, r) << '\n';
		else upd(1, 0, n, l - 1, r);
	}
	
	return 0;
}