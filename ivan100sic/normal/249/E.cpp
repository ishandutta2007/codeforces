// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128 lll;

lll resi(lll x, lll y) {
	if (y > x) {
		return x*(x*x*x+x*(3*y-1)+y*(4+y*(2*y-3))) / 6;
	} else {
		return y*(x*(4+x*(3+2*x))-(1+3*x)*y+y*y*y) / 6;
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		a--, b--;

		lll f = resi(a, b) + resi(c, d) - resi(a, d) - resi(c, b);

		if (f >= 10'000'000'000) {
			ll x = f % 10'000'000'000;
			string s = to_string(x);
			while (s.size() < 10) {
				s = string("0") + s;
			}

			cout << "..." << s << '\n';
		} else {
			cout << ll(f) << '\n';
		}
	}
}