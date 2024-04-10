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
		string s;
		cin >> s;
		int sol = 0;
		// moze naizmenicno dva razl
		for (int x=0; x<10; x++) {
			for (int y=0; y<10; y++) {
				if (x == y) continue;

				int l = 0, exp = x;

				for (char c : s) {
					c -= '0';
					if (c == exp) {
						l++;
						exp ^= x ^ y;
					}
				}

				sol = max(sol, l/2*2);
			}
		}

		// sve isti
		for (char c='0'; c<='9'; c++) {
			sol = max(sol, (int)count(begin(s), end(s), c));
		}

		cout << (int)s.size() - sol << '\n';
	}
}