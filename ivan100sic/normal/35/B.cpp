// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m, k;
string a[33][33];

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");

	cin >> n >> m >> k;

	while (k--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, y;
			string id;
			cin >> x >> y >> id;

			while (x <= n) {
				if (a[x][y].empty()) {
					a[x][y] = id;
					x = n+1;
					break;
				} else {
					y++;
					if (y == m+1) {
						y = 1;
						x++;
					}
				}
			}
		} else {
			string id;
			cin >> id;
			for (int i=1; i<=n; i++) {
				for (int j=1; j<=m; j++) {
					if (a[i][j] == id) {
						cout << i << ' ' << j << '\n';
						a[i][j] = "";
						id = "";
						i = 1123123;
						break;
					}
				}
			}

			if (id.size()) {
				cout << "-1 -1\n";
			}
		}
	}

}