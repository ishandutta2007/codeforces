#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n, m; cin >> n >> m;
	vector<ll> p(n), x(m), pref(n + 1);
	for (auto& v : p) cin >> v;
	for (auto& v : x) cin >> v, ++v;
	partial_sum(p.begin(), p.end(), pref.begin() + 1);
	auto query = [&] (int l, int r) { return pref[r] - pref[l]; };
	sort(x.begin(), x.end());
	m = x.size();
	int mx = 0;
	ll res = 0;
	for (int p = 1; p <= 100 * (n - 1) + 2; ++p) {
		while (mx < m && x[mx] < p) ++mx;
		int l = mx ? (x[mx - 1] + p + 1) / 2 : 1;
		int r = mx == m ? (n - 1) * 100 + 2 : min(100 * ll(n - 1) + 2, (p + x[mx] + 1) / 2);
		res = max(res, query((l + 98) / 100, (r + 98) / 100));
	}
	cout << res << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
//	cin >> tc;
	while (tc--) ProGamerMove();
}