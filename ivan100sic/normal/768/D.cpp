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

double dp[10005][1005];
int ans[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int k, q, d;

	cin >> k >> q;
	d = 10*k;

	dp[1][1] = 1.0;

	for (int i=2; i<=d; i++) {
		for (int j=1; j<=k; j++) {
			// ili si juce imao j pa ti se pao isti
			dp[i][j] += dp[i-1][j] * j / k;
			// ili si juce imao j-1 pa ti se pao razliciti
			dp[i][j] += dp[i-1][j-1] * (k - (j - 1)) / k;
		}
	}

	cerr << dp[d][k] << '\n';

	for (int i=1; i<=1000; i++) {
		double p = i / 2000.0;
		ans[i] = ans[i-1];
		while (dp[ans[i]][k] < p) {
			ans[i]++;
		}
	}

	while (q--) {
		int p;
		cin >> p;
		cout << ans[p] << '\n';
	}

}