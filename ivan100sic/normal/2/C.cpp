#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef complex<ld> cd;
const ld pi = acos(ld(-1));

cd inf = {1e50, 1e50};

cd a[3];
ld r[3];

struct krug {
	cd a;
	ld r;
};

krug lokus(cd a, cd b, cd u, cd v) {
	cd c = (b*u + a*v) / (u+v);
	cd d = (b*u - a*v) / (u-v);

	return {(c+d)/cd(2), abs(c-d)/2};
}

pair<cd, cd> presek(cd a, cd b, ld u, ld v) {
	ld d = abs(a-b);
	if (d > u+v || d < abs(u-v))
		return {inf, inf};

	ld lo = 0, hi = pi;
	for (int step=0; step<90; step++) {
		ld mid = (lo + hi) / 2;

		cd p = a + (b-a) / abs(b-a) * u * exp(cd(0, mid));

		if (abs(p-b) >= v) {
			hi = mid;
		} else {
			lo = mid;
		}
	}

	cd p1 = a + (b-a) / abs(b-a) * u * exp(cd(0, lo));
	cd p2 = a + (b-a) / abs(b-a) * u * exp(cd(0, -lo));
	return {p1, p2};
}

cd sol = inf;
ld val = 1e44;

void ubaci(cd p) {
	ld v[3];
	for (int i=0; i<3; i++)
		v[i] = abs(p - a[i]) / r[i];
	auto [i, j] = minmax_element(v, v+3);
	if (abs(*i-*j) < 1e-5 && *i < val)
		sol = p, val = *i;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<3; i++) {
		int x, y;
		cin >> x >> y >> r[i];
		a[i] = cd(x, y);
	}

	// sva tri su ista?
	if (r[0] == r[1] && r[1] == r[2]) // stfu compiler I know what i'm doing
	{
		// circumcenter
		double ax = a[0].real();
		double bx = a[1].real();
		double cx = a[2].real();
		double ay = a[0].imag();
		double by = a[1].imag();
		double cy = a[2].imag();
 
		double dole = 2*(ay*bx-ax*by-ay*cx+by*cx+ax*cy-bx*cy);
		double gorex = ay*bx*bx - ax*ax*by - ay*ay*by + ay*by*by - ay*cx*cx + by*cx*cx
					+ ax*ax*cy + ay*ay*cy - bx*bx*cy - by*by*cy - ay*cy*cy + by*cy*cy;
 
		double gorey = ax*by*by - ay*ay*bx - ax*ax*bx + ax*bx*bx - ax*cy*cy + bx*cy*cy
					+ ay*ay*cx + ax*ax*cx - by*by*cx - bx*bx*cx - ax*cx*cx + bx*cx*cx;
 
		cout << gorex / dole << ' ' << gorey / dole << '\n';
 
		return 0;
	}

	int uq = 0;
	while (r[uq] == r[(uq+1)%3] || r[uq] == r[(uq+2)%3])
		uq++;
	int dr = (uq+1) % 3, tr = (uq+2) % 3;

	krug f = lokus(a[uq], a[dr], r[uq], r[dr]);
	krug g = lokus(a[uq], a[tr], r[uq], r[tr]);

	// presek
	auto [p1, p2] = presek(f.a, g.a, f.r, g.r);

	ubaci(p1);
	ubaci(p2);

	if (abs(sol) < 1e49) {
		cout << setprecision(20) << fixed;
		cout << sol.real() << ' ' << sol.imag() << '\n';
	}
}