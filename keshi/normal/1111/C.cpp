//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 998244353;
const ll inf = 8e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, a, b, h[maxn];

ll cnt(ll l, ll r){
	return upper_bound(h, h + k, r) - lower_bound(h, h + k, l);
}

ll solve(ll l, ll r){
	ll s = inf, d = a, m = (l + r) / 2, t = cnt(l, r);
	if(r != l && t) s = solve(l, m) + solve(m + 1, r);
	if(t) d = b * t * (r - l + 1);
	return min(s, d);
}

int main(){
	fast_io;
	
	cin >> n >> k >> a >> b;
	for(ll i = 0; i < k; i++){
		cin >> h[i];
	}
	sort(h, h + k);
	cout << solve(1, (1 << n));
	
	return 0;
}