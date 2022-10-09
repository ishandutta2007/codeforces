#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
vector<vector<int>> a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	a.assign(n, vector<int>(m, 0));
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin >> a[i][j];

	for (int x=0; x<m; x++)
		for (int y=0; y<m; y++) {
			auto b = a;
			for (int i=0; i<n; i++)
				swap(b[i][x], b[i][y]);

			int ok = 1;
			for (int i=0; i<n; i++) {
				int lose = 0;
				for (int j=0; j<m; j++) {
					if (b[i][j] != j+1) {
						lose++;
					}
				}
				if (lose > 2) {
					ok = 0;
					break;
				}
			}

			if (ok) {
				cout << "YES\n";
				return 0;
			}
		}
	cout << "NO\n";
}