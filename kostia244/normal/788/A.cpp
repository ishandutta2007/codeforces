#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<20, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, a[maxn];
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i < n; i++) {
		a[i] = abs(a[i]-a[i+1]);
	}
	for(int i = 2; i < n; i+=2) a[i] *= -1;
	for(int i = 1; i < n; i++) a[i] += a[i-1];
	ll mn = (1ll<<60);
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		if(i%2 == 0) mn = min(mn, a[i]);
		ans = max(ans, a[i] - mn);
	}
	mn = (1ll<<60);
	for(int i = n; i > 0; i--) a[i] -= a[i-1];
	for(int i = 0; i < n; i++) a[i] *= -1;
	for(int i = 1; i < n; i++) a[i] += a[i-1];
	for(int i = 1; i < n; i++) {
		if(i%2 == 1) mn = min(mn, a[i]);
		ans = max(ans, (a[i] - mn));
	}
	cout << ans << endl;
}