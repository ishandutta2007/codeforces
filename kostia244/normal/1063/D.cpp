#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,popcnt,sse4.1,sse4.2,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 105, mod = 1e9 + 7;
const ld tau = 6.28318530717958647692;
const ld A = 2.5*tau - 20.;
const ld B = 5.0*tau - 20.;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll ceil(ll x, ll y) {
	if(x >= 0) return (x+y-1)/y;
	return x/y;
}
ll floor(ll x, ll y) {
	if(x <= 0) return (x-y+1)/y;
	return x/y;
}
ll solve(ll n, ll k, ll d, ll f) {
	ll ans = -1;
	if(k < d+f) return -1;
	if(k <= 2*d) ans = k-d + (n-d);
	ll l = n, r, c, q = 0;
	if(f&&d==0) swap(f, q);
	while(l <= 2*n && l <= k) {
		c = k/l;
		r = k/c;
		
		ll A = max({0ll, l-n, ceil((k-2*d-n*c), c), ceil(-d+k-n*c, c+1)});
		ll B = min({n, r-n, floor(k-f-d-n*c, c), floor(n - 2*d + k - n*c, c+1)});
		if(B >= A) ans = max(ans, B);
		
		l = r+1;
	}
	if(q && ans == 0) ans = -1;
	return ans;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, k, l, r;
	cin >> n >> l >> r >> k;
	ll d = (n+r-l+1)%n;
	cout << max(solve(n, k, d, 0), solve(n, k+1, d, 1));
}