#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ld pi = 3.14159265358979323;

ll kv(ll x) {
	return x*x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cout.precision(20);
	cout << fixed;

	ll x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

	ll d2 = kv(x1-x2) + kv(y1-y2);

	if (d2 >= kv(r1 + r2)) {
		cout << "0\n";
	} else if (d2 <= kv(r1 - r2)) {
		cout << pi * kv(min(r1, r2)) << '\n';
	} else {
		ld d = sqrt(d2) / r1;
		ld r = (ld)r2 / r1;

		cerr << "rd " << r << ' ' << d << '\n';

		ld x = (1 + d*d - r*r) / (2*d);
		ld y = -1 + 2*d*d - d*d*d*d + 2*r*r + 2*d*d*r*r - r*r*r*r;

		const bool POPRAVLJAMO_Y = true;

		if (POPRAVLJAMO_Y && d-r > 0.99999999) {
			// po deficiji, d = r+1-e, tj. e = r+1-d
			// d2 = (r1 + r2)^2 - f
			cerr << "popravljam\n";
			cerr << "old y: " << y << '\n';
			ll a = r1 + r2;
			ll b = a*a - d2;
			cerr << a << ' ' << b << " (celi)\n";
			ld e = b / (ld)2 / a / r1;
			cerr << "e: " << e << '\n';
			y = 8*e*r*(1 + r) + e*e*(-4-12*r-4*r*r);
			cerr << "new y: " << y << '\n';
		}

		y = sqrt(y);
		y /= 2*d;

		cerr << "xy " << x << ' ' << y << '\n';

		ld a1 = atan2(y, x);

		ld xt = d - x;

		ld a2 = atan2(y, xt);

		cerr << a1 << ' ' << a2 << '\n';

		ld pizza1 = a1;
		ld pizza2 = a2 * r * r;

		ld tro1 = x*y;
		ld tro2 = xt*y;

		cerr << tro1 << '\n';
		cerr << tro2 << '\n';
		cerr << pizza1 << '\n';
		cerr << pizza2 << '\n';

		ld raz1 = pizza1 - tro1;

		if (abs(y/x) < 1e-5) {
			cerr << "popravljam 1\n";
			cerr << "old 1: " << raz1 << '\n';
			raz1 = y*y*y/x - y*y*y/(3*x*x*x);
			cerr << "new 1: " << raz1 << '\n';
		}

		ld raz2 = pizza2 - tro2;

		if (abs(y/xt) < 1e-5) {
			cerr << "popravljam 2\n";
			cerr << "old 2: " << raz2 << '\n';
			raz2 = (y*y*y / xt) - r*r*y*y*y/xt/xt/xt/3;
			cerr << "new 2: " << raz2 << '\n';
		}

		ld sol = raz1 + raz2;

		cout << sol * r1 * r1 << '\n';
	}
}