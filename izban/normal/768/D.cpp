#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXK = -1;
const int MAXN = -1;
const int MOD = 0; // 1000 * 1000 * 1000 + 7;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int k, q;
	while (cin >> k >> q) {
		const int N = 9000;
		vector<vector<double> > dp(N, vector<double>(k + 1, 0));
		dp[0][0] = 1;
		for (int i = 0; i < N - 1; i++) {
			double sum = 0;
			for (int j = 0; j <= k; j++) {
				if (dp[i][j] < 1e-50) {
					dp[i][j] = 0;
					continue;
				}
				sum += dp[i][j];
			}
			for (int j = 0; j <= k; j++) {
				dp[i][j] /= sum;
				if (j < k) dp[i + 1][j + 1] += dp[i][j] * (k - j) / k;
				if (j > 0) dp[i + 1][j] += dp[i][j] * j / k;
			}
		}
		//cout << dp[N - 1][k] << endl;

		for (int i = 0; i < q; i++) {
			int o;
			cin >> o;
			double p = (o - 1e-7) / 2000;
			int L = 0, R = N - 1;
			while (R - L > 1) {
				int M = (L + R) / 2;
				if (dp[M][k] >= p) R = M;
				else L = M;
			}
			printf("%d\n", R);
		}
	}

	return 0;
}