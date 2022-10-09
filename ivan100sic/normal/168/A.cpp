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

	int n, x, y;
	cin >> n >> x >> y;

	// (x + k) / n >= y / 100
	int l = 0, r = 1e9, o = 0;
	while (l <= r) {
		int m = (l+r) >> 1;
		if ((x + m) * 100ll >= n * 1ll * y) {
			o = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	cout << o << '\n';
}