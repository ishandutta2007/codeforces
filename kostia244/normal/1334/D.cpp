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
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<17, mod = 998244353 , lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	ll n, l, r;
	cin >> n >> l >> r;
	ll x = 0;
	if(r == n*(n-1) + 1) x = 1, --r;
	ll b = 1, bs = 1, be = 2ll*(n-1);
	vi ans;
	while(l <= r) {
		while(l > be) {
			bs = be+1;
			b++;
			be += 2*(n-b);
		}
		ll t = l - bs;
		if(t&1) ans.pb(b + (1 + t)/2);
		else ans.pb(b);
		l++;
	}
	if(x) ans.pb(1);
	for(auto i : ans) cout << i << " "; cout << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}