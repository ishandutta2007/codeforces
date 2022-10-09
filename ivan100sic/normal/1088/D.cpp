#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<pair<int, int>, int> cache;

int ask(int x, int y) {
	if (cache.count({x, y}))
		return cache[{x, y}];
	cout << "? " << x << ' ' << y << '\n' << flush;
	cin >> cache[{x, y}];
	return cache[{x, y}];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	const int maxn = 30;

	int c = 0, d = 0;

	for (int i=maxn-1; i>=0; i--) {
		int w = 1 << i;
		int r = ask(c, d);
		if (r == 0) {
			int z = ask(c ^ w, d);
			if (z == -1) {
				c ^= w;
				d ^= w;
			}
		} else if (r == -1) {
			int z = ask(c ^ w, d ^ w);
			if (z == -1) {
				// 00 ili 11
				// odredi koji je
				int t = ask(c ^ w, d);
				if (t == -1) {
					c ^= w;
					d ^= w;
				} else {
					// nista
				}
			} else if (z == 1) {
				d ^= w;
			} else {
				d ^= w;
			}
		} else {
			int z = ask(c ^ w, d ^ w);
			if (z == 1) {
				// 00 ili 11
				// odredi koji je
				int t = ask(c, d ^ w);
				if (t == 1) {
					c ^= w;
					d ^= w;
				} else {
					// nista
				}
			} else if (z == -1) {
				c ^= w;
			} else {
				c ^= w;
			}
		}
	}

	cout << "! " << c << ' ' << d << '\n' << flush;
}