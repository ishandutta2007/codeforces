#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T>
T eea(T a, T b, T& x, T& y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}

	T x1, y1;
	T g = eea(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return g;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll c3=0, c4=0, c5=0;
	ll n, s;
	cin >> n >> s;
	while (n--) {
		int x;
		cin >> x;
		if (x == 3) c3++;
		else if (x == 4) c4++;
		else if (x == 5) c5++;
	}

	auto cost = [&](ll k3, ll k4, ll k5) {
		return abs(c3*k3 - c4*k4) + abs(c4*k4 - c5*k5);
	};

	ll sol = 123123123123123123ll;

	ll opt_k3 = -1;
	ll opt_k4 = -1;
	ll opt_k5 = -1;

	for (ll k3=0; k3<=s/(c3+c4+c5); k3++) {
		ll k4_init, k5_init;
		ll g = eea(c4, c5, k4_init, k5_init);
		if ((s - c3*k3) % g)
			continue;

		k4_init *= (s - c3*k3) / g;
		k5_init *= (s - c3*k3) / g;

		// k4_init * c4 + k5_init * c5 == g
		// (k4_init + c5 / g) * c4 + (k5_init - c4 / g) * c5 == g

		ll q_lo = (k3 - k4_init) / (c5 / g);
		ll k4_lo = k4_init + (q_lo - 2) * (c5 / g);
		while (k4_lo < k3)
			k4_lo += c5 / g;

		ll k4_hi = (s - c3 * k3) / (c4 + c5);
		k4_hi -= ((k4_hi - k4_lo) % (c5 / g) + (c5 / g)) % (c5 / g);

		// cerr << "k4 vals with k3 = " << k3 << ": " << k4_lo << ' ' << k4_hi
		// 	<< " init = " << k4_init << '\n';

		if (k4_lo > k4_hi)
			continue;

		auto findk5 = [&](ll k4) {
			return (s - c3*k3 - c4*k4) / c5;
		};

		while (k4_hi - k4_lo > 3 * (c5 / g)) {
			ll k4_mid1 = k4_lo + ((k4_hi - k4_lo) / (c5 / g)) / 2 * (c5 / g);
			ll k4_mid2 = k4_mid1 + c5 / g;

			ll k5_mid1 = findk5(k4_mid1);
			ll k5_mid2 = findk5(k4_mid2);

			if (cost(k3, k4_mid1, k5_mid1) <= cost(k3, k4_mid2, k5_mid2)) {
				k4_hi = k4_mid2;
			} else {
				k4_lo = k4_mid1;
			}
		}

		for (ll k4 = k4_lo; k4 <= k4_hi; k4 += c5 / g) {
			ll k5 = findk5(k4);
			ll new_sol = cost(k3, k4, k5);

			// cerr << "evo ga " << k3 << ' ' << k4 << ' ' << k5 << ": " << new_sol << '\n';

			if (new_sol < sol) {
				opt_k3 = k3;
				opt_k4 = k4;
				opt_k5 = k5;
				sol = new_sol;
			}
		}
	}

	if (sol == 123123123123123123ll) {
		cout << "-1\n";
		return 0;
	}

	cout << opt_k3 << ' ' << opt_k4 << ' ' << opt_k5 << '\n';
}