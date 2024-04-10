#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

const int MOD = 1'000'000'007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	string s;
	cin >> n >> s;
	s = string(" ") + s;


	vector<vector<int>> d(n+1, vector<int>(1 << 20, 0));
	// vector<unordered_map<int, int>> d(n+1);
	
	for (int i=0; i<=n; i++) {
		d[i][0] = 1;
	}

	for (int i=1; i<=n; i++) {
		int e = 0, x = 0;
		for (int j=i; j>=1; j--) {
			// ukljuci jtu cifru
			if (s[j] == '1') {
				if (e < 10) {
					x += 1 << e;
					if (x > 20) {
						break;
					}
				} else {
					break;
				}
			}

			if (x == 0) {
				e++;
				continue;
			}

			for (int mask=0; mask < (1<<20); mask++) {
				int val = d[j-1][mask];
				if (val == 0) {
					continue;
				}
				int& z = d[i][mask | (1 << (x - 1))] += val;
				if (z >= MOD) {
					z -= MOD;
				}
			}

			e++;
		}
	}

	int sol = 0;

	for (int r=1; r<=n; r++) {
		for (int mask=1; mask<(1<<20); mask=2*mask+1) {
			sol += d[r][mask];
			if (sol >= MOD) {
				sol -= MOD;
			}
		}
	}

	cout << sol;


}