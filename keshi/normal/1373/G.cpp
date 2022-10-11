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

ll n, k, m, seg[4 * maxn], lz[4 * maxn];
map<ll, ll> vis[maxn];
set<pll> s;

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

ll solve(ll id, ll s, ll e, ll x){
	if(e - s == 1) return e;
	ll mid = (s + e) / 2;
	seg[id * 2] += lz[id];
	seg[id * 2 + 1] += lz[id];
	lz[id * 2] += lz[id];
	lz[id * 2 + 1] += lz[id];
	lz[id] = 0;
	if(max(x, seg[id * 2]) <= mid) return solve(id * 2, s, mid, x);
	return solve(id * 2 + 1, mid, e, max(x, seg[id * 2]));
}

int main(){
	ll x, y;
	fast_io;
	
	for(ll i = 0; i < maxn; i++){
		upd(1, 0, maxn - 1, i, i + 1, i);
	}
	
	cin >> n >> k >> m;
	s.insert(Mp(-n, 0ll));
	for(ll i = 1; i <= m; i++){
		cin >> x >> y;
		if(vis[x][y]) upd(1, 0, maxn - 1, 0, y + abs(x - k), -1), s.erase(Mp(-y - abs(x - k), vis[x][y])), vis[x][y] = 0;
		else upd(1, 0, maxn - 1, 0, y + abs(x - k), 1), vis[x][y] = i, s.insert(Mp(-y - abs(x - k), i));
		cout << solve(1, 0, maxn - 1, -s.begin() -> F) - n << '\n';
	}
	
	return 0;
}