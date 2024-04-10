// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

typedef complex<ld> cd;
const ld pi = acos(ld(-1));
const ld inf = 1e30;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cout << setprecision(20) << fixed;

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		n *= 2;

		cd a = {1, 0};
		cd b = exp(cd(0, 2*pi / n));
		ld scale = 1 / abs(b-a);

		ld xl=inf, xr=-inf, yl=inf, yr=-inf;
		for (int i=0; i<n; i++) {
			cd v = scale * exp(cd(0, 2*pi / n * (2*i+1) / 2));
			ld x = v.real();
			ld y = v.imag();

			xl = min(xl, x);
			xr = max(xr, x);

			yl = min(yl, y);
			yr = max(yr, y);
		}

		cout << max(xl, xr) * 2 << "\n";
	}
}