#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;

const ld pi = acos(ld(-1));

int n;
ld xx, yy, v, t;

vector<pair<ld, int>> e;

void dodaj(ld a, ld b) {

	// cerr << "dodajem " << a << ' ' << b << '\n';
	if (a < -pi) {
		e.emplace_back(a+2*pi, 1);
		e.emplace_back(pi, -1);
		a = -pi;
	}

	if (b > pi) {
		e.emplace_back(-pi, 1);
		e.emplace_back(b-2*pi, -1);
		b = pi;
	}

	e.emplace_back(a, +1);
	e.emplace_back(b, -1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> xx >> yy >> v >> t;
	t *= v;
	cin >> n;
	if (t == 0) {
		for (int i=0; i<n; i++) {
			ld x, y, r;
			cin >> x >> y >> r;
			x -= xx;
			y -= yy;
			if (x*x + y*y <= r*r) {
				cout << "1\n";
				return 0;
			}
		}
		cout << "0\n";
		return 0;
	}

	for (int i=0; i<n; i++) {
		ld x, y, r;
		cin >> x >> y >> r;
		x -= xx;
		y -= yy;
		x /= t;
		y /= t;
		r /= t;
		ld d = sqrt(x*x+y*y);
		if (d <= r) {
			cout << "1\n";
			return 0;
		}

		ld angtang = asin(r/d);

		if (r + d <= 1) {
			// nema preseka, krug je ceo unutra
			ld centar = atan2(y, x);
			dodaj(centar - angtang, centar + angtang);
			continue;
		}

		// cerr << "d = " << d << '\n';
		// cerr << "r = " << r << '\n';

		ld xu = (1+d*d-r*r) / 2 / d;

		// cerr << "xu = " << xu << '\n';

		if (xu*xu > 1)
			continue; // nema preseka, krug je spolja
		ld yu = sqrt(1 - xu*xu);

		ld angsec = atan2(yu, xu);
		ld tpd = d*d-r*r, ang;
		if (tpd > 1)
			ang = angsec;
		else
			ang = angtang;
		ld cent = atan2(y, x);
		dodaj(cent - ang, cent + ang);
	}

	auto& v = e;
	sort(v.begin(), v.end());
	int s = 0;
	ld ee = 0;
	for (int i=0; i<(int)v.size(); i++) {
		s += v[i].second;
		if (i < (int)v.size()-1 && s > 0) {
			ld l = v[i].first;
			ld r = v[i+1].first;
			ee += r-l;
		}
	}

	cout << fixed << setprecision(20) << ee/2/pi << '\n';
}