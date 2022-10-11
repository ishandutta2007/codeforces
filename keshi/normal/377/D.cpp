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

ll n, a[maxn], l[maxn], r[maxn], c[maxn], f[maxn], lz[maxn];
pll seg[maxn], b[maxn];
pair<ll, pll> ans;
vector<ll> g[maxn], e[maxn];

void upd(ll id, ll s, ll e, ll sl, ll sr, ll x){
	if(sr <= s || e <= sl) return;
	if(sl <= s && e <= sr){
		seg[id].F += x;
		lz[id] += x;
		return;
	}
	ll mid = (s + e) / 2;
	seg[id * 2].F += lz[id];
	seg[id * 2 + 1].F += lz[id];
	lz[id * 2] += lz[id];
	lz[id * 2 + 1] += lz[id];
	lz[id] = 0;
	upd(id * 2, s, mid, sl, sr, x);
	upd(id * 2 + 1, mid, e, sl, sr, x);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
	return;
}
pll get(ll id, ll s, ll e, ll sl, ll sr){
	if(sr <= s || e <= sl) return Mp(-inf, -1ll);
	if(sl <= s && e <= sr) return seg[id];
	ll mid = (s + e) / 2;
	seg[id * 2].F += lz[id];
	seg[id * 2 + 1].F += lz[id];
	lz[id * 2] += lz[id];
	lz[id * 2 + 1] += lz[id];
	lz[id] = 0;
	return max(get(id * 2, s, mid, sl, sr), get(id * 2 + 1, mid, e, sl, sr));
}
void upd2(ll l, ll y){
	upd(1, 0, n, l, l + 1, y - get(1, 0, n, l, l + 1).F);
	return;
}
void bld(ll id, ll s, ll e){
	if(e - s == 1){
		seg[id] = Mp(-inf, s);
		return;
	}
	ll mid = (s + e) / 2;
	bld(id * 2, s, mid);
	bld(id * 2 + 1, mid, e);
	return;
}

int main(){
	fast_io;
	
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> l[i] >> a[i] >> r[i];
		g[a[i]].pb(i);
		e[r[i]].pb(i);
		b[i] = Mp(a[i], i);
	}
	sort(b, b + n);
	for(ll i = 0; i < n; i++){
		c[b[i].S] = i;
	}
	for(ll i = 1; i < n; i++){
		for(ll j = b[i - 1].F + 1; j <= b[i].F; j++){
			f[j] = i;
		}
	}
	bld(1, 0, n);
	for(ll i = 1; i < maxn; i++){
		for(ll j = 0; j < g[i].size(); j++){
			ll x = g[i][j];
			upd(1, 0, n, f[l[x]], c[x], 1);
			upd2(c[x], 1);
			pll p = get(1, 0, n, f[l[x]], c[x] + 1);
			ans = max(ans, Mp(p.F, Mp(b[p.S].F, a[x])));
		}
		for(ll j = 0; j < e[i].size(); j++){
			ll x = e[i][j];
			upd(1, 0, n, f[l[x]], c[x], -1);
			upd2(c[x], -inf);
		}
	}
	cout << ans.F << '\n';
	for(ll i = 0; i < n; i++){
		if(l[i] <= ans.S.F && ans.S.S <= r[i] && ans.S.F <= a[i] && a[i] <= ans.S.S){
			cout << i + 1 << " ";
		}
	}
	
	return 0;
}