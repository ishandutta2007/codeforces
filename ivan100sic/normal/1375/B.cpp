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
		int n, m, ok = 1;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				cin >> a[i][j];
				int nb = (i > 0) + (i < n-1) + (j > 0) + (j < m-1);
				if (a[i][j] > nb) {
					ok = 0;
				} else {
					a[i][j] = nb;
				}
			}
		}

		if (ok) {
			cout << "YES\n";
			for (int i=0; i<n; i++) {
				for (int j=0; j<m; j++) {
					cout << a[i][j] << ' ';
				}
				cout << '\n';
			}
		} else {
			cout << "NO\n";
		}
	}
}