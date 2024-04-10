#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int k;
ll k2_16, k2_lb;

/*
	x koordinata je bilo koji broj
	y koordinata je iste parnosti kao x koord

	"prave" koordinate centra hexagona x,y su:
	(x*3/2, y*sqrt(3)/2)

	"prave" koordinate temene se razlikuju za:
	(x+-1, y)
	(x+-1/2, y+-sqrt(3)/2)

*/

bool inside_ring_teme(ll x, ll y) {
	// x/2, y*sqrt(3)/4
	ll d2 = x*x*4 + y*y*3;
	return d2 <= k2_16;
}

bool inside_ring(int hx, int hy) {
	return inside_ring_teme(3*hx+2, 2*hy)
		&& inside_ring_teme(3*hx-2, 2*hy)
		&& inside_ring_teme(3*hx+1, 2*hy+2)
		&& inside_ring_teme(3*hx+1, 2*hy-2)
		&& inside_ring_teme(3*hx-1, 2*hy+2)
		&& inside_ring_teme(3*hx-1, 2*hy-2);
}

int resi(int x) {
	int rem = x%2;
	int l = 0, r = 4123123, o = -5;
	while (l <= r) {
		int m = (l+r) >> 1;
		int y = 2*m + rem;
		if (inside_ring(x, y)) {
			o = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	int rez = o*2 + rem + 1;
	// cerr << x << ' ' << rez << '\n';
	return rez;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> k;
	k2_16 = 16ll*k*k;

	int w = k/2;
	ll sol = 0;
	for (int x=0; x<=2*w; x++) {
		int t = max(0, resi(x));
		sol += (x == 0 ? 1 : 2) * t;
	}
	cout << sol << '\n';
}