#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;


void ProGamerMove() {
	int n; cin >> n;
	vector<int> a(n);
	for (int& v : a) cin >> v;
	sort(a.begin(), a.end());
	auto calc = [&] (ll one, ll two) {
		return one < 0 || two < 0 ? LLONG_MAX : (one <= two ? 2 * two : 2 * one - 1);
	};
	auto tr = [&] (vector<int> a, int h) {
		ll one = 0, two = 0;
		for (int& v : a) one += abs(h - v) & 1, two += abs(h - v) / 2;
		if (one >= two) return calc(one, two);
		ll x = (two - one) / 3;
		ll res = LLONG_MAX;
		for (int d = 0; d < 3; ++d, ++x) res = min(res, calc(one + 2 * x, two - x));
		return res;
	};
	ll res = LLONG_MAX;
	for (int d = 0, h = a.back(); d < 4; ++d, ++h) res = min(res, tr(a, h));
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