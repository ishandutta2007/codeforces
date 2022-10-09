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
		int x;
		cin >> x;
		if (x == 0) {
			cout << "1 1\n";
			continue;
		}

		int found = 0;

		for (int n=1; n<=39500; n++) {
			int l = 1, r = n, o = -1;
			while (l <= r) {
				int m = (l+r) >> 1;
				int y = n*n - (n/m)*(n/m);
				if (y > x) {
					r = m-1;
				} else if (y < x) {
					l = m+1;
				} else {
					o = m;
					break;
				}
			}

			if (o != -1) {
				cout << n << ' ' << o << '\n';
				found = 1;
				break;
			}
		}

		if (!found) {
			cout << "-1\n";
		}
	}
}