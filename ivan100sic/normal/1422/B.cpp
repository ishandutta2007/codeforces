// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
int a[105][105];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				cin >> a[i][j];
			}
		}

		ll sol = 0;

		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				int x = n-1-i;
				int y = m-1-j;

				if (i > x || j > y) continue;

				basic_string<int> b;

				b += a[i][j];
				if (i < x) b += a[x][j];
				if (j < y) b += a[i][y];
				if (i < x && j < y) b += a[x][y];

				sort(begin(b), end(b));
				int m = b[b.size()/2];
				for (int c : b)
					sol += abs(c-m);
			}
		}

		cout << sol << '\n';
	}
}