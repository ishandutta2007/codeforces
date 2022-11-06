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
	ll n;
	cin >> n;
	n %= 360;
	if (n <= 0) n *= -1;
	else n = 360 - n;
	ll opt = 400, ans;
	forn(i, 0, 4) {
		ll val = min(n, 360 - n);
		if (val < opt) {
			opt = val;
			ans = i;
		}
		n = (n + 90) % 360;
	}
	cout << ans << '\n';
	return 0;
}