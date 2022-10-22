#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve(ll start, ll n) {
	ll r = start;
	ll m = 0;
	if (start == 0) {
		m = n / 8 * 8;
	} else {
		if (n >= 2) {
			m = (n - 2) / 8 * 8 + 2;
			r = 0;
		}
	}
	assert(m <= n);
	for (ll i = m + 1; i <= n; ++i) {
		if (r % 2 == 0) {
			r -= i;
		} else {
			r += i;
		}
	}
	return r;
}

int main()
{
#ifdef _MSC_VER
	freopen("b.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	for (cin >> t; t > 0; --t) {
		ll x0, n;
		cin >> x0 >> n;
		ll ret = 0;
		if (x0 % 2 == 0) {
			ret = x0 + solve(0, n);
		} else {
			ret = (x0 - 1) + solve(1, n);
		}
		cout << ret << endl;
	}
	return 0;
}