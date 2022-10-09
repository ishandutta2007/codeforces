#include <bits/stdc++.h>
using namespace std;

int n, r;
int x[1005];
double y[1005];

inline double kv(double x) {
	return x*x;
}

bool sece(int xkurac, double ykurac, int x, double y) {
	if (x > xkurac + 2*r || x < xkurac - 2*r) {
		return false;
	}

	if (y < ykurac) {
		return true;
	}

	return kv(xkurac - x) + kv(ykurac - y) < 4*r*r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> r;
	for (int i=1; i<=n; i++) {
		cin >> x[i];
	}

	for (int i=1; i<=n; i++) {

		double lo = r;
		double hi = 3e6;

		int steps = 60;

		while (steps--) {
			double mid = (lo + hi) / 2;

			bool secem = false;

			for (int j=1; j<i; j++) {
				if (sece(x[j], y[j], x[i], mid)) {
					secem = true;
					break;
				}
			}

			if (secem) {
				lo = mid;
			} else {
				hi = mid;
			}
		}

		y[i] = (lo + hi) / 2;
	}

	cout.precision(20);

	for (int i=1; i<=n; i++) {
		cout << fixed << y[i] << ' ';
	}


}