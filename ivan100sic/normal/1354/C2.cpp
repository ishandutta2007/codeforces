// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double ld;



typedef complex<ld> cd;
const ld pi = acos(ld(-1));
const ld inf = 1e30;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cout << setprecision(20) << fixed;

	int t;
	cin >> t;

	map<int, double> cache;

	while (t--) {
		int n;
		cin >> n;
		n *= 2;

		if (cache.count(n)) {
			cout << cache[n] << "\n";
			continue;
		}

		cd a = {1, 0};
		cd b = exp(cd(0, 2*pi / n));
		ld scale = 1 / abs(b-a);

		const int factor = 4*n;
		ld sol = inf;
		for (int rem=0; rem<factor; rem++) {
			ld xl=inf, xr=-inf, yl=inf, yr=-inf;
			for (int i=0; i<n; i++) {
				cd v = scale * exp(cd(0, 2*pi / n * (factor*i+rem) / factor));
				ld x = v.real();
				ld y = v.imag();

				xl = min(xl, x);
				xr = max(xr, x);

				yl = min(yl, y);
				yr = max(yr, y);
			}

			sol = min(sol, max(xr-xl, yr-yl));
		}

		cout << sol << "\n";
		cache[n] = sol;
	}
}