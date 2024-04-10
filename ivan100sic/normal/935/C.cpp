#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll sq(ll x) {
	return x*x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cout.precision(20);
	cout << fixed;

	ll R, x1, y1, x2, y2;
	cin >> R >> x1 >> y1 >> x2 >> y2;

	// ako je spolja
	if (sq(x1-x2) + sq(y1-y2) >= R*R) {
		cout << x1 << ' ' << y1 << ' ' << R << '\n';
	} else if (sq(x1-x2) + sq(y1-y2) == 0) {
		cout << x1+R/2.0 << ' ' << y1 << ' ' << R/2.0 << '\n';
	} else {
		ld r = sqrt((ld)sq(x1-x2) + sq(y1-y2));
		ld xc = (x2*(r-R) + x1*(r+R)) / (2*r);
		ld yc = (y2*(r-R) + y1*(r+R)) / (2*r);

		ld rc = (r+R) / 2.0;

		cout << xc << ' ' <<  yc << ' ' << rc << '\n';

	}
}