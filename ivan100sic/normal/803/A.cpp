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

int n, k;
vector<vector<int>> sol(n, vector<int>(n, 0));
bool ima;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	ima = false;
	for (int j=0; j<=n; j++) {
		if (j <= k && (k - j) % 2 == 0) {
			int r = k - j;
			vector<vector<int>> a(n, vector<int>(n, 0));

			for (int i=0; i<j; i++) {
				a[i][i] = 1;
			}

			for (int x=0; x<n; x++) {
				for (int y=0; y<n; y++) {
					if (a[x][y] == 0 && r > 0 && x != y) {
						a[x][y] = 1;
						a[y][x] = 1;
						r -= 2;
					}					
				}
			}

			if (r == 0 && (a > sol || !ima)) {
				// cerr << j << '\n';
				ima = true;
				sol = a;
			}
		}
	}

	if (!ima) {
		cout << -1;
		return 0;
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout << sol[i][j] << ' ';
		}
		cout << '\n';
	}

}