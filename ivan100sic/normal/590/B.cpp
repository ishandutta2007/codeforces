#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef complex<ld> cd;

ld vmx, tch;
cd v, w, p, q;

bool moze(ld t) {
	cd c = p + v * min(t, tch) + w * max(ld(0), t - tch);
	return abs(c-q) <= t*vmx;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ld x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	p = {x1, y1};
	q = {x2, y2};
	cin >> vmx >> tch;
	cin >> x1 >> y1 >> x2 >> y2;
	v = {x1, y1};
	w = {x2, y2};

	ld l = 0, r = 1e12;
	int steps = 100;
	while (steps--) {
		ld m = (l+r) / 2;
		if (moze(m)) {
			r = m;
		} else {
			l = m;
		}
	}
	
	cout << setprecision(20) << fixed << l << '\n';
}