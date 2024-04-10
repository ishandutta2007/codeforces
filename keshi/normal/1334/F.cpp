//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxm = 4e6 + 100;
const ll maxn = 5e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, a[maxn], c[maxn], b[maxn], d[maxn], e[maxn], seg[maxm], lz[maxm], lm[maxn], rm[maxn];
pll ap[maxn];

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
	seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
	return;
}

ll get(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return inf + inf;
	if(l <= s && e <= r) return seg[id];
	ll mid = (s + e) / 2;
	seg[id * 2] += lz[id];
	seg[id * 2 + 1] += lz[id];
	lz[id * 2] += lz[id];
	lz[id * 2 + 1] += lz[id];
	lz[id] = 0;
	return min(get(id * 2, s, mid, l, r), get(id * 2 + 1, mid, e, l, r));
}

int main(){
	ll x;
	fast_io;
	
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		ap[i] = Mp(a[i], i);
	}
	for(ll i = 0; i < n; i++){
		cin >> c[i];
	}
	cin >> m;
	for(ll i = 1; i <= m; i++){
		cin >> b[i];
		e[b[i]] = i;
	}
	ll p = 1;
	for(ll i = 0; i < n; i++){
		if(p <= m && a[i] == b[p]) p++;
	}
	if(p <= m){
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	sort(ap, ap + n);
	for(ll i = 0; i < n; i++){
		d[ap[i].S] = i + 1;
		if(lm[ap[i].F] == 0) lm[ap[i].F] = i + 1;
		rm[ap[i].F] = i + 1;
	}
	upd(1, 0, n + 1, 1, n + 1, inf);
	for(ll i = 0; i < n; i++){
		if(e[a[i]]) upd(1, 0, n + 1, d[i], d[i] + 1, get(1, 0, n + 1, lm[b[e[a[i]] - 1]], rm[b[e[a[i]] - 1]] + 1) - get(1, 0, n + 1, d[i], d[i] + 1));
		if(c[i] < 0) {
			upd(1, 0, n + 1, 0, n + 1, c[i]);
			if(d[i] < n + 1) upd(1, 0, n + 1, d[i], d[i] + 1, -c[i]);
		}
		else{
			x = lower_bound(ap, ap + n, Mp(a[i], -1ll)) - ap + 1;
			upd(1, 0, n + 1, 0, x, c[i]);
			if(d[i] < x) upd(1, 0, n + 1, d[i], d[i] + 1, -c[i]);
		}
	}
	cout << get(1, 0, n + 1, lm[b[m]], rm[b[m]] + 1);
	
	return 0;
}