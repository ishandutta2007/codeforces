#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// govno od zadatka, sorry

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll t, a, b, sol = 0;
	cin >> t >> a >> b;

	if (a == 1) {
		// a = 1 sledi p(x) = x^n, n >= 0
		// odakle sledi b = 1
		if (b != 1) {
			cout << "0\n";
			return 0;
		}

		if (t == 1) {
			// bilo koji od ovih gore radi
			cout << "inf\n";
		} else {
			// samo p(x) = 1
			cout << "1\n";
		}

		return 0;
	}

	vector<ll> v;
	for (ll x = b; x; x /= a)
		v.push_back(x % a);

	ld tr = 0;
	ull ti = 0;

	for (int i=v.size()-1; i>=0; i--) {
		tr = tr * t + v[i];
		ti = ti * t + v[i];
	}

	if (tr < 2e18 && (ll)ti == a)
		sol++;

	if (t == 1) {
		ll q = b;
		while (q % a == 0)
			q /= a;
		if (q == 1 && b > 1)
			sol++;
	} else if (a == b)
		sol++;

	cout << sol << '\n';
}