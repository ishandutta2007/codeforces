#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ll x, y;

	pt operator- (const pt& o) const {
		return {x - o.x, y - o.y};
	}
};

int n;
pt a[100005];

ll sq(ll x) {
	return x*x;
}

ll sp(pt a, pt b) {
	return a.x*b.x + a.y*b.y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll x0, y0;
	cin >> n >> x0 >> y0;

	for (int i=0; i<n; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].x -= x0;
		a[i].y -= y0;
	}

	// najdalja
	ld hi = 0;
	for (int i=0; i<n; i++) {
		hi = max(hi, (ld)sq(a[i].x) + sq(a[i].y));
	}
	hi = sqrt(hi);

	ld lo = 1e30;

	a[n] = a[0];

	for (int i=0; i<n; i++) {
		lo = min(lo, sqrt((ld)sq(a[i].x) + sq(a[i].y)));
		// ako su oba ugla ostra
		pt a = ::a[i];
		pt b = ::a[i+1];
		if (sp(a, a-b) > 0 && sp(b, b-a) > 0) {
			ld p = (ld)abs(a.y*b.x - a.x*b.y);
			p /= sqrt(sq(a.x-b.x) + sq(a.y - b.y));
			lo = min(p, lo);
		}
	}

	cerr << lo << ' ' << hi << '\n';

	cout.precision(20);
	cout << fixed;
	cout << (hi*hi - lo*lo) * 3.14159265358979323 << '\n';
}