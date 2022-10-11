//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 35e3 + 100;
const ll maxk = 55;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, a[maxn], c[maxn], dp[maxk][maxn], seg[maxk][maxn * 4], lz[maxk][maxn * 4];

void upd(ll fl, ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[fl][id] += x;
		lz[fl][id] += x;
		return;
	}
	ll mid = (s + e) / 2;
	seg[fl][id * 2] += lz[fl][id];
	seg[fl][id * 2 + 1] += lz[fl][id];
	lz[fl][id * 2] += lz[fl][id];
	lz[fl][id * 2 + 1] += lz[fl][id];
	lz[fl][id] = 0;
	upd(fl, id * 2, s, mid, l, r, x);
	upd(fl, id * 2 + 1, mid, e, l, r, x);
	seg[fl][id] = max(seg[fl][id * 2], seg[fl][id * 2 + 1]);
	return;
}

ll get(ll fl, ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return 0;
	if(l <= s && e <= r) return seg[fl][id];
	ll mid = (s + e) / 2;
	seg[fl][id * 2] += lz[fl][id];
	seg[fl][id * 2 + 1] += lz[fl][id];
	lz[fl][id * 2] += lz[fl][id];
	lz[fl][id * 2 + 1] += lz[fl][id];
	lz[fl][id] = 0;
	return max(get(fl, id * 2, s, mid, l, r), get(fl, id * 2 + 1, mid, e, l, r));
}

int main(){
	fast_io;
	
	cin >> n >> k;
	n++;
	
	for(ll i = 1; i < n; i++){
		cin >> a[i];
		for(ll j = 0; j <= k; j++){
			upd(j, 1, 0, n, c[a[i]] + 1, i + 1, 1);
		}
		for(ll j = 1; j <= k; j++){
			dp[j][i] = get(j - 1, 1, 0, n, 0, i + 1);
			if(i + 2 <= n) upd(j, 1, 0, n, i + 1, i + 2, dp[j][i]);
		}
		c[a[i]] = i;
	}
	
	cout << dp[k][n - 1];
	
	return 0;
}