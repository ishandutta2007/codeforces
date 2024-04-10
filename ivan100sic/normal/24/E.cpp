#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
struct atom {
	int x, v;
	bool operator< (const atom& b) const {
		return x < b.x;
	}
} a[500005];

bool ima(double t) {
	double z = -1e30;
	for (int i=0; i<n; i++) {
		if (a[i].v > 0) {
			z = max(z, a[i].v * t + a[i].x);
		} else {
			if (a[i].v * t + a[i].x < z) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i].x >> a[i].v;
	}

	sort(a, a+n);
	ld l = 0, r = 1e10;
	int steps = 100;
	while (steps--) {
		ld t = (l+r) / 2;
		if (ima(t)) {
			r = t;
		} else {
			l = t;
		}
	}

	if (l > 4e9)
		l = -1;

	cout << fixed << setprecision(20) << l << '\n';
}