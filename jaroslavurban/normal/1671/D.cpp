#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n, x; cin >> n >> x;
	vector<int> a(n);
	ll mn = INT_MAX, mx = INT_MIN;
	for (int& v : a) cin >> v, mn = min(mn, (ll)v), mx = max(mx, (ll)v);
	ll f = a[0], l = a.back();
	ll res = 0;
	for (int i = 0; i < n - 1; ++i) res += abs(a[i] - a[i + 1]);
	if (mn <= 1 && mx >= x) cout << res << "\n";
	else if (mn <= 1) {
		ll add = min({2 * (x - mx), x - f, x - l});
		cout << res + add << "\n";
	} else if (mx >= x) {
		ll add = min({2 * (mn - 1), f - 1, l - 1});
		cout << res + add << "\n";
	} else {
		ll add = 2 * (mn - 1 + x - mx);
		add = min(add, 2 * (mn - 1) + x - f);
		add = min(add, 2 * (mn - 1) + x - l);
		add = min(add, 2 * (x - mx) + f - 1);
		add = min(add, 2 * (x - mx) + l - 1);
		add = min(add, l - 1 + x - f);
		add = min(add, f - 1 + x - l);
		add = min(add, x - 1 + f - 1);
		add = min(add, x - 1 + l - 1);
		add = min(add, x - 1 + x - f);
		add = min(add, x - 1 + x - l);
		cout << res + add << "\n";
	}

}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}