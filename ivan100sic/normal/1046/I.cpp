#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int sol, rd = 1, first = 1;
ld d1, d2;

void run(ld x) {
	if (x <= d1 && rd) {
		sol++;
		rd = 0;
	} else if (x > d2) {
		rd = 1;
	}
}

void addseg(ld a, ld b) {
	if (first)
		run(a);
	first = 0;
	run(b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n >> d1 >> d2;
	d1 *= d1;
	d2 *= d2;

	ld x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	for (int i=1; i<n; i++) {
		ld x3, y3, x4, y4;
		cin >> x3 >> y3 >> x4 >> y4;

		ld xa = x1-x2;
		ld ya = y1-y2;
		ld xb = x3-x4;
		ld yb = y3-y4;

		ld sp1 = (xb-xa)*xb + (yb-ya)*yb;
		ld sp2 = (xa-xb)*xa + (ya-yb)*ya;

		if (sp1 > 0 && sp2 > 0) {
			// podeli na dva dela
			ld area2 = (xa*yb - xb*ya) * (xa*yb - xb*ya);
			ld len2 = (xb-xa)*(xb-xa) + (yb-ya)*(yb-ya);

			addseg(xa*xa+ya*ya, area2 / len2);
			addseg(area2 / len2, xb*xb+yb*yb);
		} else {
			// ne moras
			addseg(xa*xa+ya*ya, xb*xb+yb*yb);
		}

		x1 = x3;
		y1 = y3;
		x2 = x4;
		y2 = y4;
	}

	cout << sol << '\n';
}