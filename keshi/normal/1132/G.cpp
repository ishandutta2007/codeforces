//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, a[maxn], b[maxn], h[maxn], c[maxn], par[maxn], seg[8 * maxn], lz[8 * maxn];
vector<pll> vec;
vector<ll> g[maxn];

void bld(ll id, ll s, ll e){
	if(e - s == 1){
		seg[id] = h[s];
		return;
	}
	ll mid = (s + e) / 2;
	bld(id * 2, s, mid);
	bld(id * 2 + 1, mid, e);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
	return;
}
void upd(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[id] += x;
		lz[id] += x;
		return;
	}
	ll mid = (s + e) / 2;
	seg[id * 2] += lz[id];
	lz[id * 2] += lz[id];
	seg[id * 2 + 1] += lz[id];
	lz[id * 2 + 1] += lz[id];
	lz[id] = 0;
	upd(id * 2, s, mid, l, r, x);
	upd(id * 2 + 1, mid, e, l, r, x);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
	return;
}
ll get(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return 0;
	if(l <= s && e <= r) return seg[id];
	ll mid = (s + e) / 2;
	seg[id * 2] += lz[id];
	lz[id * 2] += lz[id];
	seg[id * 2 + 1] += lz[id];
	lz[id * 2 + 1] += lz[id];
	lz[id] = 0;
	return max(get(id * 2, s, mid, l, r), get(id * 2 + 1, mid, e, l, r));
}

int main(){
	fast_io;
	
	cin >> n >> k;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	vec.pb(Mp(inf, n));
	for(ll i = n; i--;){
		while(a[i] >= vec.back().F) vec.pop_back();
		par[i] = vec.back().S;
		h[i] = h[par[i]] + 1;
		vec.pb(Mp(a[i], i));
	}
	bld(1, 0, n);
	vec.clear();
	vec.pb(Mp(inf, -1));
	for(ll i = 0; i < n; i++){
		while(a[i] > vec.back().F) vec.pop_back();
		c[i] = vec.back().S;
		vec.pb(Mp(a[i], i));
	}
	for(ll i = n; i--;){
		if(i + k < n) upd(1, 0, n, c[i + k] + 1, n, -1);
		b[i] = get(1, 0, n, i, i + k);
	}
	for(ll i = 0; i < n - k + 1; i++){
		cout << b[i] << " ";
	}
	
	return 0;
}