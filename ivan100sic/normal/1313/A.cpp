// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int a, b, c, z = 0;
		cin >> a >> b >> c;

		for (int m=2; m<256; m+=2) {
			int ua=0, ub=0, uc=0;
			for (int t=1; t<8; t++) {
				if (m & (1 << t)) {
					if (t & 1) ua++;
					if (t & 2) ub++;
					if (t & 4) uc++;
				}
			}

			if (ua <= a && ub <= b && uc <= c) {
				z = max(z, __builtin_popcount(m));
			}
		}

		cout << z << '\n';
	}
}