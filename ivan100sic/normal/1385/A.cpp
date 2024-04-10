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
		int x, y, z;
		cin >> x >> y >> z;

		int ok = 0;
		for (int a : {x, y, z}) {
			for (int b : {x, y, z}) {
				for (int c : {x, y, z}) {
					if (!ok && x == max(a, b) && y == max(a, c) && z == max(b, c)) {
						cout << "YES\n" << a << ' ' << b << ' ' << c << '\n';
						ok = 1;
						break;
					}
				}
			}
		}

		if (!ok) {
			cout << "NO\n";
		}
	}
}