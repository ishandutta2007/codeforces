#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;

int ask(int x1, int y1, int x2, int y2) {
	cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n' << flush;
	int x;
	cin >> x;
	return x;
}

void ans(vector<int> v) {
	cout << '!';
	for (int x : v)
		cout << ' ' << x;
	cout << '\n' << flush;
	exit(0);
}

vector<int> resi(int x1, int y1, int x2, int y2) {
	int ax, bx, ay, by, l, r, m, o;
	ax = bx = ay = by = -1;

	l = x1;
	r = x2;
	o = -1;
	while (l <= r) {
		m = (l+r) / 2;
		if (ask(m, y1, x2, y2)) {
			l = m+1;
			o = m;
		} else {
			r = m-1;
		}
	}
	ax = o;

	l = x1;
	r = x2;
	o = -1;
	while (l <= r) {
		m = (l+r) / 2;
		if (ask(x1, y1, m, y2)) {
			r = m-1;
			o = m;
		} else {
			l = m+1;
		}
	}
	bx = o;

	// Y

	l = y1;
	r = y2;
	o = -1;
	while (l <= r) {
		m = (l+r) / 2;
		if (ask(x1, m, x2, y2)) {
			l = m+1;
			o = m;
		} else {
			r = m-1;
		}
	}
	ay = o;

	l = y1;
	r = y2;
	o = -1;
	while (l <= r) {
		m = (l+r) / 2;
		if (ask(x1, y1, x2, m)) {
			r = m-1;
			o = m;
		} else {
			l = m+1;
		}
	}
	by = o;

	return {ax, ay, bx, by};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	{
		int l = 1, r = n, o = -1;
		while (l <= r) {
			int m = (l+r) / 2;
			if (ask(1, 1, n, m)) {
				o = m;
				r = m-1;
			} else {
				l = m+1;
			}
		}

		if (ask(1, 1, n, o) == 1 && ask(1, o+1, n, n) == 1) {
			// super
			vector<int> v1 = resi(1, 1, n, o);
			vector<int> v2 = resi(1, o+1, n, n);
			copy(v2.begin(), v2.end(), back_inserter(v1));
			ans(v1);
		}
	}

	{
		int l = 1, r = n, o = -1;
		while (l <= r) {
			int m = (l+r) / 2;
			if (ask(1, 1, m, n)) {
				o = m;
				r = m-1;
			} else {
				l = m+1;
			}
		}

		{
			vector<int> v1 = resi(1, 1, o, n);
			vector<int> v2 = resi(o+1, 1, n, n);
			copy(v2.begin(), v2.end(), back_inserter(v1));
			ans(v1);
		}
	}


}