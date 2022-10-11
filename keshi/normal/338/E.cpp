//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, h, b[maxn], seg[maxn], lz[maxn], ans;
pll a[maxn], c[maxn];

Tree<pll> s;

void upd1(ll id, ll s, ll e, ll l, ll r, ll x){
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
	upd1(id * 2, s, mid, l, r, x);
	upd1(id * 2 + 1, mid, e, l, r, x);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
	return;
}

void upd2(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[id] = x;
		return;
	}
	ll mid = (s + e) / 2;
	seg[id * 2] += lz[id];
	seg[id * 2 + 1] += lz[id];
	lz[id * 2] += lz[id];
	lz[id * 2 + 1] += lz[id];
	lz[id] = 0;
	upd2(id * 2, s, mid, l, r, x);
	upd2(id * 2 + 1, mid, e, l, r, x);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
	return;
}

int main(){
	fast_io;
	fill(seg, seg + maxn, -inf);
	
	cin >> n >> m >> h;
	
	for(ll i = 0; i < m; i++){
		cin >> b[i];
		b[i] = h - b[i];
	}
	sort(b, b + m);
	for(ll i = 0; i < n; i++){
		cin >> a[i].F;
		a[i].S = i;
	}
	sort(a, a + n);
	for(ll i = 0; i < n; i++){
		c[a[i].S].F = a[i].F;
		c[a[i].S].S = i;
	}
	
	for(ll i = 0; i < n; i++){
		upd1(1, 0, n, c[i].S, n, 1);
		upd2(1, 0, n, c[i].S, c[i].S + 1, (ll)s.order_of_key(c[i]) - ll(upper_bound(b, b + m, c[i].F) - b) + 1);
		s.insert(c[i]);
		if(i >= m - 1){
			if(seg[1] <= 0) ans++;
			upd1(1, 0, n, c[i - m + 1].S, n, -1);
			upd2(1, 0, n, c[i - m + 1].S, c[i - m + 1].S + 1, -inf);
			s.erase(c[i - m + 1]);
		}
	}
	
	cout << ans;
	
	return 0;
}