#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define apply fuckstl
#define int long long
using namespace std;
using ll = int64_t;
const int maxn = 1<<18, mod = 1000000007;
ll ans = 0, n, k, a[maxn], cnt[maxn];
priority_queue<array<ll, 2>> q;
ll cut(ll x, ll y) {
	ll base = x/y;
	ll t = x%y;
	return base*base*(y-t) + t*(base+1)*(base+1);
}
ll cost(ll x, ll y) {
	return -cut(x, y)+cut(x, y+1);
}
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	k -= n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[i] = 1;
		ans += a[i]*a[i];
		q.push({-cost(a[i], 1), i});
	}
	while(k--) {
		auto [cst, i] = q.top();
		ans -= cst;
		q.pop();
		q.push({-cost(a[i], ++cnt[i]), i});
	}
	cout << ans << '\n';
}