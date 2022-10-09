#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bitset<4096> b[100055];
int n, k, q;
int a[12][100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> q;
	for (int i=0; i<k; i++)
		for (int j=0; j<n; j++)
			cin >> a[i][j];

	for (int i=0; i<k; i++)
		for (int j=0; j<(1<<k); j++)
			b[i][j] = j & (1 << i);
	int u = k;

	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;
		x--, y--;
		if (t == 1) {
			b[u++] = b[x] | b[y];
		} else if (t == 2) {
			b[u++] = b[x] & b[y];
		} else {
			vector<pair<int, int>> c(k);
			for (int i=0; i<k; i++)
				c[i] = {a[i][y], i};
			sort(c.begin(), c.end(), greater<pair<int, int>>());
			int mask = 0;
			for (auto [v, i] : c) {
				mask |= 1 << i;
				if (b[x][mask]) {
					cout << v << '\n';
					break;
				}
			}
		}
	}
}