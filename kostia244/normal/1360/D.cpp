#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,popcnt")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 5050, mod = 1e9 + 7, i2 = (mod+1)/2;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		ll n, k;
		cin >> n >> k;
		ll ans = 1<<30;
		for(ll d = 1; d*d <= n; d++) {
			if(n%d) continue;
			if(d <= k) ans = min(ans, n/d);
			if(n/d <= k) ans = min(ans, d);
		}
		cout << ans << '\n';
	}
	return 0;
}