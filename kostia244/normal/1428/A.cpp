#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define apply fuckstl
#define int long long
using namespace std;
using ll = int64_t;
const int maxn = 303, mod = 1000000007;
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc, x, y, s, t;
	cin >> tc;
	while(tc--) {
		cin >> x >> y >> s >> t;
		ll ans = abs(x-s) + abs(t-y) + 2;
		if(x == s || y == t) ans -= 2;
		cout << ans << '\n';
	}
}