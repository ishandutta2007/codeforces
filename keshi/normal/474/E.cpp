//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, d, a[maxn], c[maxn], ans;

pll b[maxn], dp[maxn], seg[maxn];

void upd(ll id, ll s, ll e, ll l, ll r, pll p){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[id] = p;
		return;
	}
	ll mid = (s + e) / 2;
	upd(id * 2, s, mid, l, r, p);
	upd(id * 2 + 1, mid, e, l, r, p);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
	return;
}

pll get(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return make_pair(0ll, 0ll);
	if(l <= s && e <= r) return seg[id];
	ll mid = (s + e) / 2;
	return max(get(id * 2, s, mid, l, r), get(id * 2 + 1, mid, e, l, r));
}

int main(){
	ll l, r;
	fast_io;
	
	cin >> n >> d;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		b[i].F = a[i];
		b[i].S = i;
	}
	
	sort(b, b + n);
	
	for(ll i = 0; i < n; i++){
		c[b[i].S] = i;
	}
	
	ans = n;
	
	for(ll i = n - 1; i > -1; i--){
		l = upper_bound(b, b + n, make_pair(a[i] - d, n)) - b;
		r = lower_bound(b, b + n, make_pair(a[i] + d, -1ll)) - b;
		if(l > 0) dp[i] = max(dp[i], get(1, 0, n, 0, l));
		if(r < n) dp[i] = max(dp[i], get(1, 0, n, r, n));
		dp[i].F++;
		if(dp[i].F > dp[ans - 1].F) ans = i + 1;
		upd(1, 0, n, c[i], c[i] + 1, make_pair(dp[i].F, i + 1));
	}
	
	cout << dp[ans - 1].F << '\n';
	
	while(ans){
		cout << ans << " ";
		ans = dp[ans - 1].S;
	}
	
	
	return 0;
}