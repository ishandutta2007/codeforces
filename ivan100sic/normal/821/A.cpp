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

int n;
int a[55][55];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			cin >> a[i][j];
		}
	}

	bool sol = true;

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {

			bool ok = false;

			if (a[i][j] == 1) {
				continue;
			}

			for (int x=1; x<=n; x++) {
				for (int y=1; y<=n; y++) {
					if (a[i][j] == a[x][j] + a[i][y]) {
						ok = true;
						break;
					}
				}
			}

			if (!ok) {
				sol = false;
			}

		}
	}

	cout << (sol ? "Yes" : "No");
}