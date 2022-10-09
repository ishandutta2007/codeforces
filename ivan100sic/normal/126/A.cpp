#include <bits/stdc++.h>
using namespace std;

#define x1 pafkpoaskfpsapkdf
#define y1 gfwfwofeoioi

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll t1, t2, x1, x2, t0;
ll sol_y1 = -1, sol_y2 = -1;

void snimi(ll y1, ll y2) {

	if (y1 == 0) {
		y2 = x2;
	}

	if (y2 == 0) {
		y1 = x1;
	}

	if (sol_y1 == -1) {
		sol_y1 = y1;
		sol_y2 = y2;
		return;
	}

	// ostali slucajevi...

	if ((t1 * sol_y1 + t2 * sol_y2) * (y1 + y2) > (t1 * y1 + t2 * y2) * (sol_y1 + sol_y2)) {
		sol_y1 = y1;
		sol_y2 = y2;
		return;
	}

	if ((t1 * sol_y1 + t2 * sol_y2) * (y1 + y2) == (t1 * y1 + t2 * y2) * (sol_y1 + sol_y2)) {
		if (y1 + y2 > sol_y1 + sol_y2) {
			sol_y1 = y1;
			sol_y2 = y2;
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> t1 >> t2 >> x1 >> x2 >> t0;

	if (t1 == t2) {
		cout << x1 << ' ' << x2 << '\n';
		return 0;
	}

	for (ll y1 = 0; y1 <= x1; y1++) {

		ll lo = 0, hi = x2, opt = x2 + 1;

		if (y1 == 0) {
			lo = 1;
		}

		while (lo <= hi) {
			ll mid = (lo + hi) >> 1;
			if (t1 * y1 + t2 * mid >= (y1 + mid) * t0) {
				opt = mid;
				hi = mid - 1;
			}
			else {
				lo = mid + 1;
			}
		}

		if (opt <= x2) {
			snimi(y1, opt);
		}
	}

	cout << sol_y1 << ' ' << sol_y2 << '\n';
}