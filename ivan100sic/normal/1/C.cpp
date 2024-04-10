#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// this is NOT how you're supposed to set geometry problems but ok
typedef complex<ld> cd;

ld gadeg(cd a, cd b, cd c) {
	c -= b;
	a -= b;
	c /= a;
	ld t = atan2(c.imag(), c.real());
	if (t < 0)
		t = -t;
	if (t > acos(-1))
		t = 2*acos(-1) - t;
	return t * 180 / acos(-1);
}

ld area(cd a, cd b, cd c) {
	return a.real() * b.imag() + b.real() * c.imag() + c.real() * a.imag()
		- a.imag() * b.real() - b.imag() * c.real() - c.imag() * a.real();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ld ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;

	cd a(ax, ay), b(bx, by), c(cx, cy);

	basic_string<ld> angs;
	angs += gadeg(a, b, c);
	angs += gadeg(b, c, a);
	angs += gadeg(c, a, b);

	for (ld x : angs)
		cerr << x << "!\n";

	int m = 0;

	for (int n=3; n<=100; n++) {
		ld valja = 0;

		for (ld ang : angs) {
			ld xd = 1e50;
			for (int i=1; i<=n-2; i++) {
				ld t = ld(180) * i / n;
				xd = min(xd, abs(t - ang));
			}
			valja = max(valja, xd);
		}

		if (valja < 0.01) {
			m = n;
			break;
		}
	}

	// sad samo nadji opisan krug
	ld R = abs(a-b) * abs(b-c) * abs(c-a) / abs(area(a, b, c)) / 2;

	cout << setprecision(20) << fixed << R*R*m*sin(2*acos(-1) / m)/2 << '\n';
}