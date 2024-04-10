#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
double x[100005], y[100005];

pair<double, double> parabola(double x, double y, double h) {
	double koren = 2*h*y - y*y;
	if (koren < 0)
		return {0, -1};
	koren = sqrt(koren);
	return {x - koren, x + koren};
}

bool moze(double h) {
	double lo = -1e50, hi = 1e50;
	for (int i=0; i<n; i++) {
		auto p = parabola(x[i], y[i], h);

		// cerr << h << ' ' << i << ' ' << p.first << ' ' << p.second << '\n';

		lo = max(lo, p.first);
		hi = min(hi, p.second);
	}
	return lo <= hi;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x[i] >> y[i];
	}

	// ima? sredi
	int pos = 0, neg = 0;
	for (int i=0; i<n; i++) {
		if (y[i] > 0)
			pos++;
		else {
			y[i] *= -1;
			neg++;
		}
	}

	if (pos && neg) {
		cout << -1;
		return 0;
	}

	double lo = 0, hi = 1e16;
	int steps = 75;
	while (steps--) {
		double mid = (lo + hi) / 2;
		if (moze(mid)) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	cout.precision(20);
	cout << fixed;
	cout << lo << '\n';


}