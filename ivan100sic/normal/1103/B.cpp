#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool ask(int x, int y) {
	cout << "? " << x << ' ' << y << '\n' << flush;
	char z;
	cin >> z;
	return z == 'y';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	while (1) {
		string s;
		cin >> s;
		if (s == "start") {
			if (!ask(0, 1)) {
				cout << "! 1\n" << flush;
				continue;
			}

			int p = 1, q = 2;
			while (ask(p, q)) {
				p <<= 1;
				q <<= 1;
			}

			int l = p+1, r = q, o = -1;
			while (l <= r) {
				int m = (0ll+l+r) >> 1;
				if (ask(p, m)) {
					l = m + 1;
				} else {
					o = m;
					r = m - 1;
				}
			}

			cout << "! " << o << '\n' << flush;

		} else return 0;
	}
		
}