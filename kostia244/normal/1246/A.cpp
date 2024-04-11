#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define apply fuckstl
using namespace std;
using ll = int64_t;
const int maxn = 303, mod = 1000000007;
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, p;
	cin >> n >> p;
	int ans = 1<<30;
	for(int t = 1; n-p*t > 0 && t <= 30; t++) {
		int lo = __builtin_popcount(n-p*t);
		int hi = n-p*t;
		if(lo <= t && t <= hi) ans = min(ans, t);
	}
	if(ans == 1<<30) ans = -1;
	cout << ans << '\n';
}