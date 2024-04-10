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

ll n, m, a[maxn], p[maxn], f[maxn], la[maxn], ans[maxn], seg[maxn];
vector<pll> q[maxn], b[maxn];

ll pw(ll pa, ll pb){
	if(pb == 0) return 1;
	ll pc = pw(pa, pb >> 1);
	pc = (pc * pc) % mod;
	if(pb & 1) pc = (pc * pa) % mod;
	return pc;
}
void upd(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[id] = (seg[id] * x) % mod;
		return;
	}
	ll mid = (s + e) / 2;
	upd(id * 2, s, mid, l, r, x);
	upd(id * 2 + 1, mid, e, l, r, x);
	seg[id] = (seg[id * 2] * seg[id * 2 + 1]) % mod;
	return;
}
ll get(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return 1;
	if(l <= s && e <= r) return seg[id];
	ll mid = (s + e) / 2;
	return (get(id * 2, s, mid, l, r) * get(id * 2 + 1, mid, e, l, r)) % mod;
}


int main(){
	fast_io;
	ll l, r;
	
	fill(seg, seg + maxn, 1);
	for(ll i = 2; i < maxn; i++){
		if(p[i]) continue;
		f[i] = ((i - 1) * pw(i, mod - 2)) % mod;
		p[i] = i;
		for(ll j = i * i; j < maxn; j += i){
			p[j] = i;
		}
	}
	cin >> n;
	fill(la, la + maxn, n);
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		upd(1, 0, n, i, i + 1, a[i]);
	}
	for(ll i = n; i--;){
		while(a[i] != 1){
			l = p[a[i]];
			while(a[i] % l == 0) a[i] /= l;
			b[i].pb(Mp(f[l], la[l]));
			la[l] = i;
		}
	}
	cin >> m;
	for(ll i = 0; i < m; i++){
		cin >> l >> r;
		q[l - 1].pb(Mp(r, i));
	}
	for(ll i = 2; i < maxn; i++){
		if(la[i] != n) upd(1, 0, n, la[i], la[i] + 1, f[i]);
	}
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < q[i].size(); j++){
			ans[q[i][j].S] = get(1, 0, n, i, q[i][j].F);
		}
		for(ll j = 0; j < b[i].size(); j++){
			upd(1, 0, n, b[i][j].S, b[i][j].S + 1, b[i][j].F);
		}
	}
	for(ll i = 0; i < m; i++){
		cout << ans[i] << '\n';
	}
	
	return 0;
}