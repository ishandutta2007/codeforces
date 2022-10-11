//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e5 + 100;
const ll level = 21;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, seg[level][maxn], lz[level][maxn];

ll upd(ll f, ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return 0;
	if(l <= s && e <= r){
		ll p = seg[f][id];
		seg[f][id] = e - s - seg[f][id];
		lz[f][id]++;
		return seg[f][id] - p;
	}
	ll mid = (s + e) / 2;
	if(lz[f][id] % 2){
		seg[f][id * 2] = mid - s - seg[f][id * 2];
		lz[f][id * 2]++;
		seg[f][id * 2 + 1] = e - mid - seg[f][id * 2 + 1];
		lz[f][id * 2 + 1]++;
	}
	lz[f][id] = 0;
	ll p1, p2;
	p1 = upd(f, id * 2, s, mid, l, r);
	p2 = upd(f, id * 2 + 1, mid, e, l, r);
	seg[f][id] += p1 + p2;
	return p1 + p2;
}

ll get(ll f, ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return 0;
	if(l <= s && e <= r){
		return seg[f][id];
	}
	ll mid = (s + e) / 2;
	if(lz[f][id] % 2){
		seg[f][id * 2] = mid - s - seg[f][id * 2];
		lz[f][id * 2]++;
		seg[f][id * 2 + 1] = e - mid - seg[f][id * 2 + 1];
		lz[f][id * 2 + 1]++;
	}
	lz[f][id] = 0;
	return get(f, id * 2, s, mid, l, r) + get(f, id * 2 + 1, mid, e, l, r);
}

int main(){
	ll l, r, t, x;
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> x;
		for(ll j = 0; j < level; j++){
			if((x >> j) & 1){
				upd(j, 1, 0, n, i, i + 1);
			}
		}
	}
	
	cin >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> t >> l >> r;
		if(t == 1){
			x = 0;
			for(ll j = 0; j < level; j++){
				x += get(j, 1, 0, n, l - 1, r) * (1 << j);
			}
			cout << x << '\n';
		}
		else{
			cin >> x;
			for(ll j = 0; j < level; j++){
				if((x >> j) & 1){
					upd(j, 1, 0, n, l - 1, r);
				}
			}
		}
	}
	
	return 0;
}