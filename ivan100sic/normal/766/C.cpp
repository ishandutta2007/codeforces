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
int s[1005];
int a[256];

int ways[1005];
int maxlen[1005];
int minnum[1005];

int z[30][1005];

bool valid(int l, int r) {
	for (int x=1; x<=26; x++) {
		if (z[x][r] - z[x][l] > 0) {
			if (r-l > a[x]) {
				return false;
			}
		}
	}
	return true;
}

const int MOD = 1'000'000'007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string p;
	cin >> n >> p;
	for (int i=1; i<=26; i++) {
		cin >> a[i];
	}
	for (int i=1; i<=n; i++) {
		s[i] = p[i-1] - 'a' + 1;

		z[s[i]][i]++;
	}

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=26; j++) {
			z[j][i] += z[j][i-1];
		}
	}

	ways[0] = 1;

	for (int i=1; i<=n; i++) {
		minnum[i] = 1e9;
		for (int j=0; j<i; j++) {
			if (valid(j, i)) {
				ways[i] += ways[j];
				if (ways[i] >= MOD) {
					ways[i] -= MOD;
				}
				maxlen[i] = max(maxlen[i], max(maxlen[j], i-j));
				minnum[i] = min(minnum[i], minnum[j] + 1);
			}
		}
	}

	cout << ways[n] << '\n';
	cout << maxlen[n] << '\n';
	cout << minnum[n] << '\n';


}