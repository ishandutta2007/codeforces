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

	int t;
	cin >> t;
	while (t--) {
		int c, m, x;
		cin >> c >> m >> x;
		int t = min({c, m, x});
		c -= t;
		m -= t;
		x -= t;
		if (x == 0) {
			if (c < m)
				swap(c, m);
			// mesani ccm/cmm timovi
			if (c > 2*m) {
				t += m;
			} else {
				int q = c-m;
				c -= 2*q;
				m -= q;
				t += q;
				// m = c
				t += (2*m)/3;
			}
		} else {
			// c ili m je 0, gotovo
		}
		cout << t << '\n';
	}
}