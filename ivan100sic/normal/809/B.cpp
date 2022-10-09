#include <bits/stdc++.h>
using namespace std;

int n, k;

map<pair<int, int>, bool> cache;

int ask(int x, int y) {
	auto it = cache.find({x, y});
	if (it != cache.end()) {
		return it->second;
	}

	cout << "1 " << x << ' ' << y << '\n';
	cout << flush;

	string resp;
	cin >> resp;
	return cache[{x, y}] = (resp == "TAK");
}

void ans(int x, int y) {
	cout << "2 " << x << ' ' << y << '\n';
	cout << flush;

	exit(0);
}

int nadji(int l, int r) {
	while (l < r) {
		int pos = (l+r) / 2;
		bool resp = ask(pos, pos+1);
		if (resp) {
			r = pos;
		} else {
			l = pos+1;
		}
	}
	return l;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;

	if (n == 3) {
		if (k == 3) {
			ans(1, 2);
		}

		bool x = ask(1, 2);
		bool y = ask(2, 3);

		if (x && !y) {
			ans(1, 3);
		}
		if (x && y) {
			ans(1, 2);
		}
		ans(2, 3);
	}

	int b = nadji(1, n);

	cerr << "bp1: " << b << '\n';

	// probaj da nadjes nesto u [1, bp1-1] i nesto u [bp1+1, n]
	if (b == 1) {
		ans(1, nadji(2, n));
	}
	if (b == n) {
		ans(n, nadji(1, n-1));
	}

	int l = nadji(1, b-1);
	int r = nadji(b+1, n);

	if (l == b-1) {
		// nesigurno, proveri
		if (ask(l, l+1)) {
			// ok ima stvarno
			ans(l, l+1);
		} else {
			ans(b, r);
		}
	} else {
		ans(b, l);
	}

}