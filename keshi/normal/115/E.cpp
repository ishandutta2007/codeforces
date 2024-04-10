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
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, ans, a[maxn], dp[maxn], seg[maxn], lz[maxn];

vector<pll> g[maxn];

void pushlz(ll id){
	seg[id * 2] += lz[id];
	seg[id * 2 + 1] += lz[id];
	lz[id * 2] += lz[id];
	lz[id * 2 + 1] += lz[id];
	lz[id] = 0;
}

void upd(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[id] += x;
		lz[id] += x;
		return;
	}
	ll mid = (s + e) / 2;
	pushlz(id);
	upd(id * 2, s, mid, l, r, x);
	upd(id * 2 + 1, mid, e, l, r, x);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
	return;
}

ll get(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return 0;
	if(l <= s && e <= r) return seg[id];
	ll mid = (s + e) / 2;
	pushlz(id);
	return max(get(id * 2, s, mid, l, r), get(id * 2 + 1, mid, e, l, r));
}
int main(){
	ll l, r, c, s = 0;
	fast_io;
	
	cin >> n >> m;
	n++;
	for(ll i = 1; i < n; i++){
		cin >> a[i];
		s += a[i];
	}
	
	for(ll i = 0; i < m; i++){
		cin >> l >> r >> c;
		g[r].pb(Mp(l, c));
	}
	
	for(ll i = 1; i < n; i++){
		dp[i] = get(1, 0, n, 0, i) + a[i];
		upd(1, 0, n, i, i + 1, dp[i]);
		for(ll j = 0; j < g[i].size(); j++){
			upd(1, 0, n, 0, g[i][j].F, g[i][j].S);
		}
	}
	
	cout << get(1, 0, n, 0, n) - s;
	
	return 0;
}