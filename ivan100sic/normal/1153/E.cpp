#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int ask(int x1, int y1, int x2, int y2) {
	cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' '
		 << y2 << '\n' << flush;
	cin >> x1;
	return x1 % 2;
}

void ans(int x1, int y1, int x2, int y2) {
	cout << "! " << x1 << ' ' << y1 << ' ' << x2 << ' '
		 << y2 << '\n' << flush;
	exit(0);
}

int n, h[1005], v[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;

	for (int i=1; i<n; i++) {
		h[i] = ask(1, 1, n, i);
		v[i] = ask(1, 1, i, n);
	}

	// h se razlikuje?
	int l = -1, r = -1;
	for (int i=1; i<n; i++) {
		if (h[i]) {
			r = i;
			if (l == -1)
				l = i;
		}
	}

	if (l != -1) {
		int y1 = l;
		int y2 = r+1;
		int l = 1, r = n, o = -1;

		while (l <= r) {
			int m = (l+r) >> 1;
			if (ask(1, 1, m, y1)) {
				o = m;
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		int x1 = o;

		l = 1, r = n, o = -1;
		while (l <= r) {
			int m = (l+r) >> 1;
			if (ask(m, y2, n, n)) {
				o = m;
				l = m + 1;
			} else {
				r = m - 1;
			}
		}
		int x2 = o;

		ans(x1, y1, x2, y2);
	}

	l = -1, r = -1;
	for (int i=1; i<n; i++) {
		if (v[i]) {
			r = i;
			if (l == -1)
				l = i;
		}
	}

	if (l != -1) {
		int x1 = l;
		int x2 = r+1;
		int l = 1, r = n, o = -1;

		while (l <= r) {
			int m = (l+r) >> 1;
			if (ask(1, 1, x1, m)) {
				o = m;
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		int y1 = o;

		l = 1, r = n, o = -1;
		while (l <= r) {
			int m = (l+r) >> 1;
			if (ask(x2, m, n, n)) {
				o = m;
				l = m + 1;
			} else {
				r = m - 1;
			}
		}
		int y2 = o;

		ans(x1, y1, x2, y2);
	}
}