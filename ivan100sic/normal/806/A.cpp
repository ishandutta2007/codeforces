#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

typedef long long ll;

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

ll inverz(ll x, ll mod) {
	ll a, b;
	eea(x, mod, a, b);
	// x*a + b*mod = 1
	// x*a = 1
	// a
	a %= mod;
	if (a < 0) {
		a += mod;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		ll x, y, p, q;
		cin >> x >> y >> p >> q;

		if (q == 1) {
			if (p == 1) {
				if (x == y) {
					cout << "0\n";
				} else {
					cout << "-1\n";
				}
			} else {
				// p == 0
				if (x == 0) {
					cout << "0\n";
				} else {
					cout << "-1\n";
				}
			}
		} else {
			// q > 1, bitnije, p < q

			ll c = x*q - y*p;

			// cerr << "scale: " << c << '\n';
			

			if (c == 0) {
				cout << "0\n";
			} else if (c > 0) {
				ll a = (-c) % p * inverz(q, p) % p;
				if (a < 0) {
					a += p;
				}
				ll b = (c + a*q) / p;
				cout << b << '\n';
			} else {
				ll a = (-c) % p * inverz(q, p) % p;
				if (a < 0) {
					a += p;
				}
				ll b = (c + a*q) / p;
				// initial solution
				// cerr << "worst case, init = " << a << ' ' << b << '\n';


				// b moze biti negativno
				// dodaj da postane pozitivno
				if (a > b) {
					ll pz;
					if ((a-b) % (q-p)) {
						pz = (a-b) / (q-p) + 1;
					} else {
						pz = (a-b) / (q-p);
					}

					a += pz * p;
					b += pz * q;
				}

				cout << b << '\n';
			}
		}
	}
}