//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

struct node{
	ll s, mn, mx, lz;
	node(){
		s = mn = mx = 0;
		lz = -1;
	}
};

ll t, n, m, k;
vector<pll> q[maxn];
node seg[maxn];

void Do(ll id, ll s, ll e, ll x){
	if(x == -1) return;
	seg[id].mn = x;
	seg[id].mx = x;
	seg[id].lz = x;
	seg[id].s = (e - s) * x;
	return;
}
void upd(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l || seg[id].mx <= x) return;
	if(l <= s && e <= r && seg[id].mn >= x){
		Do(id, s, e, x);
		return;
	}
	ll mid = (s + e) >> 1;
	Do(id << 1, s, mid, seg[id].lz);
	Do(id << 1 | 1, mid, e, seg[id].lz);
	seg[id].lz = -1;
	upd(id << 1, s, mid, l, r, x);
	upd(id << 1 | 1, mid, e, l, r, x);
	seg[id].mn = min(seg[id << 1].mn, seg[id << 1 | 1].mn);
	seg[id].mx = max(seg[id << 1].mx, seg[id << 1 | 1].mx);
	seg[id].s = seg[id << 1].s + seg[id << 1 | 1].s;
	return;
}

int main(){
	fast_io;
	
	cin >> t >> n >> m >> k;
	for(ll i = 0; i < t; i++){
		ll x, y, z;
		cin >> x >> y >> z;
		q[m].pb(Mp(x, k - z));
		q[y].pb(Mp(n, k - z));
		q[y].pb(Mp(x, 0));
	}
	Do(1, 0, n, k);
	ll ans = 0;
	for(ll i = m; i > 0; i--){
		for(ll j = 0; j < q[i].size(); j++){
			upd(1, 0, n, 0, q[i][j].F, q[i][j].S);
		}
		ans += seg[1].s;
	}
	cout << ans;
	
	return 0;
}