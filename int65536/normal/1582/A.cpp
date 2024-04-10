#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve(ll c1, ll c2, ll c3) {
	ll r = (c3 % 2) * 3;
	while (r >= 2 && c2 > 0) {
		r = abs(r - 2);
		--c2;
	}
	if (c2 % 2 == 1) {
		r = abs(r - 2);
	}
	while (r >= 1 && c1 > 0) {
		r = abs(r - 1);
		--c1;
	}
	if (c1 % 2 == 1) {
		r = abs(r - 1);
	}
	return r;
}

int main()
{
#ifdef _MSC_VER
	freopen("a.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		ll c1, c2, c3;
		cin >> c1 >> c2 >> c3;
		cout << solve(c1, c2, c3) << endl;
	}
	return 0;
}