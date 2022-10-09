#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

long long a[105][105];
int n, m, x, y;
long long k, e;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k >> x >> y;

	if (n == 1) {
		e = k / m;
		k %= m;

		for (int j=1; j<=m; j++) {
			a[1][j] += e;
		}

	} else {
		e = k / ((2*n-2)*m);
		k %= (2*n-2)*m;

		for (int i=1; i<=n; i++) {
			for (int j=1; j<=m; j++) {
				if (1 < i && i < n) {
					a[i][j] += 2*e;
				} else {
					a[i][j] += e;
				}
			}
		}
	}
	
	int dir = 1;
	int rep = 2;

	// cerr << k << ' ' << e << '\n';

	if (n != 1) {
		for (int i=1; i<n; i++) {
			int jb = dir == 1 ? 1 : m;
			int je = dir == 1 ? m+1 : 0;
			for (int j=jb; j!=je; j+=dir) {
				if (k > 0) {
					k--;
					a[i][j]++;
				}
			}
		}

		for (int i=n; i>1; i--) {
			int jb = dir == 1 ? 1 : m;
			int je = dir == 1 ? m+1 : 0;
			for (int j=jb; j!=je; j+=dir) {
				if (k > 0) {
					k--;
					a[i][j]++;
				}
			}
		}
	} else {
		while (rep--) {
			int jb = dir == 1 ? 1 : m;
			int je = dir == 1 ? m+1 : 0;
			for (int j=jb; j!=je; j+=dir) {
				if (k > 0) {
					k--;
					a[1][j]++;
				}
			}
		}
	}

	long long mx = -2e18, mn = 2e18;

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			mx = max(mx, a[i][j]);
			mn = min(mn, a[i][j]);
		}
	}

	cout << mx << ' ' << mn << ' ' << a[x][y];

}