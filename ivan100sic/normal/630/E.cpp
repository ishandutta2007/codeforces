// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	x2 -= x1;
	y2 -= y1;

	x1 = 0, y1 = 0;

	ll xo, xe, oo, ee;
	if (x1 % 2) {
		xe = (x2-x1) / 2;
		xo = xe + 1;
	} else {
		xo = (x2-x1) / 2;
		xe = xo + 1;
	}

	if (y1 % 2) {
		oo = (y2-y1) / 2 + 1;
		ee = (y2-y1) / 2;
	} else {
		oo = (y2-y1) / 2;
		ee = (y2-y1) / 2 + 1;
	}
	
	// retardi

	cout << xo*oo + xe*ee << '\n';

}