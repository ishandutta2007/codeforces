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

void fail() {
	cout << "0\n";
	exit(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ull s, x;
	cin >> s >> x;
	if (s % 2 != x % 2) fail();
	if (s < x) fail();
	ull an = (s - x) / 2;
	ll ans = 1;
	ull old_x = x;
	while (an || x) {
		if (an % 2) {
			if (x % 2) fail();
		} else {
			if (x % 2) ans *= 2;
		}
		x /= 2;
		an /= 2;
	}
	if (s == old_x) ans -= 2;
	cout << ans << '\n';
	
	return 0;
}