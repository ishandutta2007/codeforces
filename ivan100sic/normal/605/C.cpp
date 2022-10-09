#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	double x, y;
	int id;
	bool operator< (const pt& o) const {
		if (x != o.x)
			return x < o.x;
		return y < o.y;
	}
	bool operator== (const pt& o) const {
		return x == o.x && y == o.y;
	}
};

double det(pt a, pt b, pt c) {
	return a.x*b.y + b.x*c.y + c.x*a.y
		- a.y*b.x - b.y*c.x - c.y*a.x;
}

int n, h, x, y;
pt a[100005];
pt b[100005];
pt c[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> x >> y;
	for (int i=0; i<n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	sort(a, a+n);
	n = unique(a, a+n) - a;
	for (int i=0; i<n; i++)
		a[i].id = i;
	double lo = 1e-6, hi = 1e6;
	int steps = 60;
	while (steps--) {
		double mid = (lo + hi) / 2;
		copy(a, a+n, b);
		b[n] = {x / mid, y / mid, n};
		sort(b, b+n+1);
		h = 0;
		for (int i=0; i<=n; i++) {
			while (1) {
				int ima = 0;
				if (h >= 2 && det(c[h-2], c[h-1], b[i]) >= 0)
					h--, ima = 1;
				if (h >= 1 && c[h-1].x <= b[i].x && c[h-1].y <= b[i].y)
					h--, ima = 1;
				if (!ima)
					break;
			}
			c[h++] = b[i];
		}
		int f = 0;
		for (int i=0; i<h; i++) {
			if (c[i].id == n)
				f = 1;
		}
		if (f) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout.precision(20);
	cout << fixed;
	cout << hi << '\n';
}