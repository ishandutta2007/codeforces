#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif
const ld eps = 1e-8;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> p(n);
	forn(i, 0, n) cin >> p[i];
	string s;
	cin >> s;
	ll sum_a = 0, sum_b = 0, sum_a_all = 0, sum_b_all = 0;
	forn(i, 0, n) {
		if (s[i] == 'A') sum_a_all += p[i];
		else sum_b_all += p[i];
	}
	ll ans = sum_b_all;
	forn(i, 0, n) {
		if (s[i] == 'A') sum_a += p[i];
		else sum_b += p[i];
		ans = max(ans, sum_a - sum_b + sum_b_all);
	}
	sum_a = 0, sum_b = 0;
	for(int i = n - 1; i >= 0; --i) {
		if (s[i] == 'A') sum_a += p[i];
		else sum_b += p[i];
		ans = max(ans, sum_a - sum_b + sum_b_all);
	}
	cout << ans << '\n';
	return 0;
}