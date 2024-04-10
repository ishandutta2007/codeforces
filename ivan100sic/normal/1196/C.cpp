#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	const int w = 100000;
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int xl = -w, xr = w, yl = -w, yr = w;
		for (int i=0; i<n; i++) {
			int x, y, a, b, c, d;
			cin >> x >> y >> a >> b >> c >> d;

			int xll = x, xrr = x, yll = y, yrr = y;
			if (a) xll = -w;
			if (b) yrr = +w;
			if (c) xrr = +w;
			if (d) yll = -w;

			xl = max(xl, xll);
			xr = min(xr, xrr);
			yl = max(yl, yll);
			yr = min(yr, yrr);
		}

		if (xl <= xr && yl <= yr)
			cout << "1 " << xl << ' ' << yl << '\n';
		else
			cout << "0\n";
	}
}