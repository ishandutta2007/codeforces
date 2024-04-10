#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ll x, y;
};

struct krug {
	pt c() const {
		return {x, y};
	}

	ll x, y, r;
};

ll sq(ll x) {
	return x*x;
}

ll d2(pt a, pt b) {
	return sq(a.x-b.x) + sq(a.y-b.y);
}

bool spolja(krug a, krug b) {
	return d2(a.c(), b.c()) >= sq(a.r + b.r);
}

bool unutar(krug a, krug b) {
	return a.r < b.r && d2(a.c(), b.c()) <= sq(a.r - b.r);
}

bool sek(krug a, krug b) {
	// spolja van
	if (d2(a.c(), b.c()) >= sq(a.r + b.r))
		return false;
	// bla
	if (d2(a.c(), b.c()) <= sq(a.r - b.r))
		return false;

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// koliko ima krugova koje ne sece nijedan drugi krug?
	basic_string<krug> v;
	for (int i=0; i<2; i++) {
		ll x, y, r, R;
		cin >> x >> y >> r >> R;
		v += {x, y, r};
		v += {x, y, R};
	}

	int z = 0;

	for (int i=0; i<4; i++) {
		int ok = 1;
		for (int j=0; j<4; j++) {
			if (i == j)
				continue;
			if (sek(v[i], v[j]))
				ok = 0;
		}

		// treba da ne bude u drugom prstenu
		int lo = i < 2 ? 2 : 0;
		int hi = i < 2 ? 3 : 1;

		if (unutar(v[i], v[hi]) && (unutar(v[lo], v[i]) || spolja(v[lo], v[i])))
			ok = 0;

		z += ok;
	}
	cout << z << '\n';
}