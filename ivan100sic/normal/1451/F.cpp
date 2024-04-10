// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m, c[205];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	// Nice task, I love it

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		memset(c, 0, sizeof c);
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				int x;
				cin >> x;
				c[i+j] ^= x;
			}
		}
		int f = 0;
		for (int i=0; i<n+m; i++) {
			if (c[i]) {
				f = 1;
				cout << "Ashish\n";
				break;
			}
		}
		if (!f) {
			cout << "Jeel\n";
		}
	}
}