#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt;
ll det(pt a, pt b);

struct pt {
	ll x, y, w;

	int section() const {
		return y > 0 || (y == 0 && x > 0);
	}

	bool operator< (const pt& b) const {
		int s = section();
		int bs = b.section();
		if (s != bs)
			return s < bs;
		return det(*this, b) < 0;
	}

} a[400005];

pt b[400005];

int n, c, d, m;

ll det(pt a, pt b) {
	return a.x*b.y - a.y*b.x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> c >> d;
	for (int i=0; i<n; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].x -= c;
		a[i].y -= d;
	}

	sort(a, a+n);
	b[0] = a[0];
	b[0].w = 1;
	int m = 1;
	for (int i=1; i<n; i++) {
		if (b[m-1] < a[i]) {
			b[m] = a[i];
			b[m].w = 1;
			m++;
		} else {
			b[m-1].w++;
		}
	}

	// for (int i=0; i<m; i++)
	// 	cerr << b[i].x << ' ' << b[i].y << ' ' << b[i].w << '\n';

	ll sol = 0;
	int r = 0, w = b[0].w;
	for (int l=0; l<m; l++) {
		while (1) {
			int rr = (r+1) % m;
			if (det(b[l], b[rr]) <= 0 && rr != l) {
				r = rr;
				w += b[rr].w;
			} else {
				break;
			}
		}

		// cerr << "R " << l << ' ' << r << ": " << w << ' ' << b[l].w << '\n';

		sol += b[l].w * (2 + b[l].w*b[l].w - 3*b[l].w*(w-1) + 3*(w-2ll)*w) / 6;
		w -= b[l].w;
		if (l == r) {
			r++;
			w += b[r].w;
		}
	}

	cerr << "do ovde sol: " << sol << '\n';

	// vrati ove sto su kontra
	r = 0;
	for (int l=0; l<m; l++) {
		while (1) {
			int rr = (r+1) % m;
			if (det(b[l], b[rr]) <= 0 && rr != l) {
				r = rr;
			} else {
				break;
			}
		}

		if (b[l].section() && !b[r].section() && det(b[l], b[r]) == 0)
			sol -= b[l].w * b[r].w * (b[l].w + b[r].w - 2) / 2;
		if (l == r)
			r++;
	}

	cout << n*(n-1ll)*(n-2)/6 - sol << '\n';
}