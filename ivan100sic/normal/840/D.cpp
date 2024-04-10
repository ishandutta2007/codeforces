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

int n, q, sqn;
int a[300005];
int c[300005]; // scratchpad

vector<vector<short>> occ;
vector<vector<int>> bas_occ;

vector<int> cesti;
vector<int> bas_cesti;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		c[a[i]]++;
	}

	for (int i=1; i<=n; i++) {
		if (c[i] > 400 && c[i] < 32000) {
			cesti.push_back(i);
		} else if (c[i] > 32000) {
			bas_cesti.push_back(i);
		}
	}

	memset(c, 0, sizeof(c));

	// 
	occ.resize(cesti.size());

	for (int i=0; i<cesti.size(); i++) {
		occ[i].resize(n+1, 0);
		int x = cesti[i];
		for (int j=1; j<=n; j++) {
			occ[i][j] = occ[i][j-1] + (a[j] == x);
		}
	}
	//
	bas_occ.resize(bas_cesti.size());

	for (int i=0; i<bas_cesti.size(); i++) {
		bas_occ[i].resize(n+1, 0);
		int x = bas_cesti[i];
		for (int j=1; j<=n; j++) {
			bas_occ[i][j] = bas_occ[i][j-1] + (a[j] == x);
		}
	}
	//

	for (int i=1; i<=q; i++) {
		int l, r, k;
		cin >> l >> r >> k;

		if (r - l + 1 <= 2000) {
			int best = -1;
			for (int i=l; i<=r; i++) {
				c[a[i]]++;
				if (c[a[i]] * k > r-l+1) {
					if (best == -1 || a[i] < best) {
						best = a[i];
					}
				}
			}

			cout << best << '\n';

			for (int i=l; i<=r; i++) {
				c[a[i]] = 0;
			}
		} else {
			int best = -1;

			for (int i=0; i<cesti.size(); i++) {
				int x = cesti[i];

				int v = occ[i][r] - occ[i][l-1];

				if (v*k > r-l+1) {
					if (best == -1 || x < best) {
						best = x;
					}
				}
			}

			for (int i=0; i<bas_cesti.size(); i++) {
				int x = bas_cesti[i];

				int v = bas_occ[i][r] - bas_occ[i][l-1];

				if (v*k > r-l+1) {
					if (best == -1 || x < best) {
						best = x;
					}
				}
			}

			cout << best << '\n';
		}
	}

}