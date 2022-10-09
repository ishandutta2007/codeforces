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

int a[505][505];
int d[505][505];
int n, m, k, q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k >> q;

	memset(a, 63, sizeof(a));

	while (q--) {
		int x, y, t;
		cin >> x >> y >> t;
		a[x][y] = t;
	}

	int l = 0, r = 1'000'000'000, o = -1;

	while (l <= r) {
		int mid = (l + r) / 2;
		bool ima = false;

		memset(d, 0, sizeof(d));
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=m; j++) {
				d[i][j] = 1 + min(d[i-1][j], min(d[i][j-1], d[i-1][j-1]));
				if (a[i][j] > mid) {
					d[i][j] = 0;
				}
				if (d[i][j] >= k) {
					ima = true;
				}
			}
		}

		if (ima) {
			o = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	cout << o;
}