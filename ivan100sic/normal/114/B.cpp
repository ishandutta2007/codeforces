#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string a[16];
int n, m;
int adj[16][16];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	while (m--) {
		string x, y;
		cin >> x >> y;
		int i = lower_bound(a, a+n, x) - a;
		int j = lower_bound(a, a+n, y) - a;
		adj[i][j] = adj[j][i] = 1;
	}

	int bb = -1, mm = 0;

	for (int mask=0; mask<(1<<n); mask++) {
		int ok = 1;
		for (int i=0; i<n; i++) if (mask & (1 << i))
			for (int j=0; j<n; j++) if (mask & (1 << j))
				if (adj[i][j])
					ok = 0;
		if (ok) {
			int b = __builtin_popcount(mask);
			if (b > bb) {
				bb = b;
				mm = mask;
			}
		}
	}

	cout << bb << '\n';
	for (int i=0; i<n; i++) if (mm & (1 << i))
		cout << a[i] << '\n';
}