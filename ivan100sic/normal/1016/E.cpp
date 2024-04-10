#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct seg {
	double l, r;
	bool operator< (const seg& other) const {
		return r < other.r;
	}
};

int n;
seg c[200005];
double totlen[200005], sy, a, b;

double rd() {
	int x;
	cin >> x;
	return x;
}

double f(double x) {
	auto it = lower_bound(c+1, c+n+1, seg{x, x}) - c;
	if (it == n+1)
		return totlen[n];
	return totlen[it-1] + max(x - c[it].l, 0.0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	sy = rd();
	a = rd();
	b = rd();
	cin >> n;
	for (int i=1; i<=n; i++) {
		c[i].l = rd();
		c[i].r = rd();
		totlen[i] = totlen[i-1] + c[i].r - c[i].l;
	}

	int q;
	cin >> q;

	cout.precision(20);
	cout << fixed;

	while (q--) {
		double x = rd(), y = rd();

		double ux = (sy*x - a*y) / (sy - y);
		double vx = (sy*x - b*y) / (sy - y);

		double shade = f(vx) - f(ux);
		double all = vx - ux;

		// cerr << ux << ' ' << vx << ' ' << shade << ' ' << all << '\n';

		cout << (b-a) * shade / all << '\n';
	}
}