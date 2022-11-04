#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n, a, b; cin >> n >> a >> b;
	vector<ll> x(n + 1), pref(n + 1);
	for (int i = 1; i <= n; ++i) cin >> x[i];
	partial_sum(x.begin(), x.end(), pref.begin());
	ll cur = 0, res = LLONG_MAX;
	for (int i = 0; i <= n; ++i) {
		res = min(res, cur + b * (pref.back() - pref[i] - (n - i) * x[i]));
		if (i == n) break;
		cur += (a + b) * (x[i + 1] - x[i]);
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