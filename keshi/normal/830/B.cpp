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

ll n, cnt[maxn], ans;

pll mn[maxn];

void upd(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		mn[id].F = x;
		mn[id].S = l;
		cnt[id] = 0;
		if(x < inf) cnt[id] = 1;
		return;
	}
	ll mid = (s + e) / 2;
	upd(id * 2, s, mid, l, r, x);
	upd(id * 2 + 1, mid, e, l, r, x);
	cnt[id] = cnt[id * 2] + cnt[id * 2 + 1];
	mn[id] = min(mn[id * 2], mn[id * 2 + 1]);
	return;
}

pll get1(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return make_pair(inf, inf);
	if(l <= s && e <= r) return mn[id];
	ll mid = (s + e) / 2;
	return min(get1(id * 2, s, mid, l, r), get1(id * 2 + 1, mid, e, l, r));
}

ll get2(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return 0;
	if(l <= s && e <= r) return cnt[id];
	ll mid = (s + e) / 2;
	return get2(id * 2, s, mid, l, r) + get2(id * 2 + 1, mid, e, l, r);
}

int main(){
	ll l, r;
	fast_io;
	
	fill(mn, mn + maxn, make_pair(inf, inf));
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> l;
		upd(1, 0, 2 * n, i, i + 1, l);
		upd(1, 0, 2 * n, i + n, i + n + 1, l);
	}
	
	l = 0;
	
	for(ll i = 0; i < n; i++){
		r = get1(1, 0, n * 2, l, l + n).S;
		ans += get2(1, 0, n * 2, l, r + 1);
		if(r >= n) r -= n;
		upd(1, 0, n * 2, r, r + 1, inf);
		upd(1, 0, n * 2, r + n, r + n + 1, inf);
		l = r;
	}
	
	cout << ans;
	
	return 0;
}