#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n, x; cin >> n >> x;
	vector<int> a(n), pref(n);
	for (int& v : a) cin >> v;
	sort(a.begin(), a.end());
	partial_sum(a.begin(), a.end(), pref.begin());
	ll res = 0, t = 0, mx = 0;
	while (mx < n && pref[mx] <= x) ++mx;
	while (mx > 0) {
		int l = 1, r = x + 1;
		while (l < r) {
			int m = (l + r) / 2;
			if ((m - 1 + t) * mx + pref[mx - 1] <= x) l = m + 1;
			else r = m;
		}
		--l;
		res += l * mx;
		t += l;
		while (mx > 0 && pref[mx - 1] + t * mx > x) --mx;
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