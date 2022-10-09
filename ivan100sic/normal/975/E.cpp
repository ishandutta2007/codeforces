#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <complex>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef complex<ld> cc;

struct affinet {
	// a = f(00)
	// b = pravac vektora (1, 0) nakon rotacije
	cc a, b;

	affinet(cc a, cc b) : a(a), b(b) {}

	affinet() {
		a = { 0, 0 };
		b = { 1, 0 };
	}

	cc apply(cc d) {
		return a + b * d;
	}

	affinet operator+ (affinet d) const {
		affinet tmp;
		tmp.a = d.a + d.b * a;
		tmp.b = b * d.b;
		return tmp;
	}
};

affinet freefall(cc oslonac, cc teziste) {
	affinet a0 = { -oslonac, cc(1) };
	affinet a2 = { +oslonac, cc(1) };

	cc r = teziste - oslonac;
	r /= abs(r);

	affinet a1 = { 0, conj(r * cc(0, 1)) };

	return a0 + a1 + a2;
}

int n, t1, t2;
cc a[200005];
cc teziste;
affinet trans;

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		ld x, y;
		cin >> x >> y;
		a[i] = { x, y };
	}

	ld area = 0;

	a[0] = a[n];

	cc s = a[0], tez = 0;

	for (int i = 0; i <= n; i++) {
		a[i] -= s;
	}

	for (int i = 0; i < n; i++) {
		ld thing = a[i].real() * a[i + 1].imag() - a[i + 1].real() * a[i].imag();
		area += thing;
		tez += (a[i] + a[i + 1]) * thing;
	}

	tez /= 3 * area;

	t1 = 1;
	t2 = 2;

	cout.precision(18);

	while (q--) {
		int tip;
		cin >> tip;
		if (tip == 1) {
			int f, t;
			cin >> f >> t;
			if (t1 == f) {
				trans = trans + freefall(trans.apply(a[t2]), trans.apply(tez));
				t1 = t;
			}
			else {
				trans = trans + freefall(trans.apply(a[t1]), trans.apply(tez));
				t2 = t;
			}
		}
		else {
			int x;
			cin >> x;
			cc p = trans.apply(a[x]) + s;
			cout << fixed;
			cout << p.real() << ' ' << p.imag() << '\n';
		}
	}
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}