#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 4055, mod = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll t, n, k;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		vector<ll> a(n);
		for(auto &i : a) cin >> i;
		sort(all(a));
		ll g = 0;
		for(int i = 1; i < n; i++) {
			g = __gcd(g, a[i]-a[i-1]);
		}
		int ok = (k-a[0])%g == 0;
		cout << (ok?"YES":"NO") << '\n';
	}
}