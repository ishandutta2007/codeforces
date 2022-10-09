#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[505][505];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin >> a[i][j];

	// jedan red ima dva razlicita broja
	for (int i=0; i<n; i++) {
		set<int> s(a[i], a[i]+m);
		if (s.size() > 1) {
			int j1 = find(a[i], a[i]+m, *s.begin()) - a[i];
			int j2 = find(a[i], a[i]+m, *++s.begin()) - a[i];

			int xr = 0;
			for (int r=0; r<n; r++) {
				if (r == i) {
					xr ^= a[r][j1];
				} else {
					xr ^= a[r][0];
				}
			}
			if (xr == 0) {
				swap(j1, j2);
			}
			cout << "TAK\n";
			for (int r=0; r<n; r++) {
				cout << (r == i ? j1 : 0) + 1 << " \n"[r == n-1];
			}
			return 0;
		}
	}

	// mozda je resenje bilo sta?
	{
		int xr = 0;
		for (int r=0; r<n; r++) {
			xr ^= a[r][0];
		}
		if (xr) {
			cout << "TAK\n";
			for (int r=0; r<n; r++) {
				cout << 1 << " \n"[r == n-1];
			}
			return 0;
		}
	}

	cout << "NIE\n";
}