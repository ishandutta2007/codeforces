#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll f(ll n, ll m) {
	ll lo = -1;
	ll hi = n + 1;
	while (hi - lo > 1) {
		ll mi = (lo + hi) / 2;
		ll val = (mi / m) * 2 * m + m + (mi % m);
		if (val <= n) {
			lo = mi;
		} else {
			hi = mi;
		}
	}
	return hi;
}
int main()
{
#ifdef _MSC_VER
	freopen("b.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int l;
		int r;
		cin >> l >> r;
		int ret = 0;
		for (int p2 = 1; p2 <= r; p2 *= 2) {
			ret = max<ll>(ret, f(r, p2) - f(l - 1, p2));
		}
		ret = (r - l + 1) - ret;
		printf("%d\n", ret);
	}
	return 0;
}