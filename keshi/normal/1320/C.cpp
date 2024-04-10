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

ll n, m, p, ptr, seg[maxn], lz[maxn], ans;

pll a[maxn], b[maxn];

pair<pll, ll> c[maxn];

void upd(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[id] += x;
		lz[id] += x;
		return;
	}
	ll mid = (s + e) / 2;
	seg[id * 2] += lz[id];
	seg[id * 2 + 1] += lz[id];
	lz[id * 2] += lz[id];
	lz[id * 2 + 1] += lz[id];
	lz[id] = 0;
	upd(id * 2, s, mid, l, r, x);
	upd(id * 2 + 1, mid, e, l, r, x);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
	return;
}

int main(){
	fast_io;
	
	cin >> n >> m >> p;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i].F >> a[i].S;
	}
	
	for(ll i = 0; i < m; i++){
		cin >> b[i].F >> b[i].S;
	}
	
	for(ll i = 0; i < p; i++){
		cin >> c[i].F.F >> c[i].F.S >> c[i].S;
	}
	
	sort(a, a + n);
	sort(b, b + m);
	sort(c, c + p);
	
	for(ll i = 0; i < m; i++){
		upd(1, 0, m, i, i + 1, -b[i].S);
	}
	
	ans = -inf;
	
	for(ll i = 0; i < n; i++){
		while(ptr < p && c[ptr].F.F < a[i].F){
			upd(1, 0, m, upper_bound(b, b + m, make_pair(c[ptr].F.S, inf)) - b, m, c[ptr].S);
			ptr++;
		}
		ans = max(ans, seg[1] - a[i].S);
	}
	
	cout << ans;
	
	return 0;
}