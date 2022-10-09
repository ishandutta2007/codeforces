// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

map<array<int, 5>, int> winner;

int rek(int c0, int c1, int w0, int w1, int pl) {
	auto& r = winner[{c0, c1, w0, w1, pl}];
	if (r) return r;

	if (c0 == 0 && c1 == 0) {
		r = w0 ? 1 : 2;
		return r;
	}

	if (pl == 1) {
		if (c0 && rek(c0-1, c1, w0, w1, 2) == 1) {
			return r = 1;
		} else if (c1 && rek(c0, c1-1, w0^1, w1, 2) == 1) {
			return r = 1;
		} else {
			return r = 2;
		}
	} else {
		if (c0 && rek(c0-1, c1, w0, w1, 1) == 2) {
			return r = 2;
		} else if (c1 && rek(c0, c1-1, w0, w1^1, 1) == 2) {
			return r = 2;
		} else {
			return r = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	// for (int e=0; e<=10; e++) {
	// 	for (int o=1; o<=19; o+=2) {
	// 		cerr << rek(e, o, 0, 0, 1);
	// 	}
	// 	cerr << '\n';
	// }

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}

		bool ok = false;

		for (int b=29; b>=0; b--) {
			int c = 0;
			for (int j=0; j<n; j++) {
				c += (a[j] >> b) & 1;
			}

			if (c % 2 == 0) continue;

			ok = true;
			int d = n - c;

			if (d % 2 == 0 && c % 4 == 3) {
				cout << "LOSE\n";
			} else {
				cout << "WIN\n";
			}

			break;
		}

		if (!ok) {
			cout << "DRAW\n";
		}
	}
}