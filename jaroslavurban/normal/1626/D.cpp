#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n;
	cin >> n;
	vector<int> cnt(n + 2), pref(n + 2);
	for (int v, i = 0; i < n; ++i) {
		cin >> v;
		++cnt[v];
	}
	partial_sum(cnt.begin(), cnt.end(), pref.begin());
	auto clc = [&](int v) {
		return v ? (__builtin_popcount(v) == 1 ? 0 : (1 << (32 - __builtin_clz(v))) - v) : 1;
	};
	auto calc = [&](int a, int b, int c) {
		return clc(a) + clc(b) + clc(c);
	};
	int res = 1e9;
	for (int i = 0; i <= n; ++i) {
		for (int m = 1; m <= n; m *= 2) {
			if (m < cnt[i + 1]) continue;
			auto it = prev(upper_bound(pref.begin(), pref.end(), pref[i] + m));
			int mid = *it - pref[i];
			int last = n - pref[i] - mid;
			res = min(res, calc(pref[i], mid, last));
		}
	}
	cout << res << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}