// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int d[55][55];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n, m, a, b;
		cin >> n >> m >> a >> b;

		if (n*a != m*b) {
			cout << "NO\n";
			continue;
		}

		memset(d, 0, sizeof d);

		cout << "YES\n";

		int y = 0;
		for (int i=0; i<n; i++) {
			int t = a;
			while (t--) {
				d[i][y] = 1;
				y = (y+1) % m;
			}
		}

		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				cout << d[i][j];
			}
			cout << '\n';
		}

	}
}