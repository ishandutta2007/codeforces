#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
	int n;
	ll m;
	cin >> n >> m;
	vector<ll> x(n), y(n), s(n), t(n), w(n);
	ll sum = 0;
	ll total_s = 0;
	ll total_t = 0;
	vector<ll> ps, pt;
	ps.push_back(0);
	pt.push_back(0);
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		x[i] = a;
		y[i] = b;
		ll m2 = a + b - m;
		s[i] = max<ll>(0, m2 - b);
		t[i] = min<ll>(a, m2);
		w[i] = m2;
		total_s += s[i];
		total_t += t[i];
		ps.push_back(total_s);
		pt.push_back(total_t);
		sum += m2;
	}
	ll target;
	if (total_s * 2 >= sum) {
		target = total_s;
	} else if (total_t * 2 <= sum) {
		target = total_t;
	} else {
		target = sum / 2;
		assert(target >= total_s && target <= total_t);
	}
	printf("%lld\n", abs(sum - 2 * target));
	vector<ll> ret(n);
	for (int i = n - 1; i >= 0; --i) {
		ll x = max<ll>(target - pt[i], s[i]);
		assert(x >= s[i] && x <= t[i]);
		ret[i] = x;
		target -= x;
	}
	assert(target == 0);
	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", (int)(x[i] - ret[i]), (int)(y[i] - (w[i] - ret[i])));
	}
}

int main()
{
#ifdef _MSC_VER
	freopen("g.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	for (cin >> t; t > 0; --t) {
		solve();
	}
	return 0;
}