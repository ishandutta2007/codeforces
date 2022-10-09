#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 998244353;

struct mint {
	int x;

	mint(int x = 0) : x(x) {}

	void operator+= (const mint& o) {
		x += o.x;
		if (x >= MOD) {
			x -= MOD;
		}
	}
};

int n, k;
mint dp[1005][2][2005];

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	dp[1][0][1] = 2;
	dp[1][1][2] = 2;

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			// bili isti
			dp[i + 1][0][j] += dp[i][0][j];

			dp[i + 1][1][j + 1] += dp[i][0][j];
			dp[i + 1][1][j + 1] += dp[i][0][j];

			dp[i + 1][0][j + 1] += dp[i][0][j];

			// bili razliciti
			dp[i + 1][1][j] += dp[i][1][j];

			dp[i + 1][0][j] += dp[i][1][j];
			dp[i + 1][0][j] += dp[i][1][j];

			dp[i + 1][1][j + 2] += dp[i][1][j];
		}
	}

	mint x(0);
	x += dp[n][0][k];
	x += dp[n][1][k];

	cout << x.x << '\n';

}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}