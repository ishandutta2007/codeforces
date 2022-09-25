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

const int MAXN = 205;
const int MAXM = 1005;
const int MOD = 1000 * 1000 * 1000 + 7;

int dp[MAXN][MAXN][MAXM];

void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, k;
	while (cin >> n >> k) {
	//n = 200; k = 1000; {
		memset(dp, 0, sizeof(dp));
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		//for (int i = 0; i < n; i++) a[i] = rand() % 500 + 1;

		sort(a.begin(), a.end());
		a.push_back(a.back() + MAXM);

		dp[0][0][0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n; j++) {
				for (int sum = 0; sum < MAXM; sum++) {
					if (!dp[i][j][sum]) continue;
					// new, not last
					if (sum + (j + 1) * (a[i + 1] - a[i]) < MAXM) add(dp[i + 1][j + 1][sum + (j + 1) * (a[i + 1] - a[i])], dp[i][j][sum]);
					// new, last
					if (sum + j * (a[i + 1] - a[i]) < MAXM) add(dp[i + 1][j][sum + j * (a[i + 1] - a[i])], dp[i][j][sum]);

					// old, not last
					if (j && sum + j * (a[i + 1] - a[i]) < MAXM) add(dp[i + 1][j][sum + j * (a[i + 1] - a[i])], dp[i][j][sum] * 1LL * j % MOD);
					// old, last
					if (j && sum + (j - 1) * (a[i + 1] - a[i]) < MAXM) add(dp[i + 1][j - 1][sum + (j - 1) * (a[i + 1] - a[i])], dp[i][j][sum] * 1LL * j % MOD);
				}
			}
		}
		int ans = 0;
		for (int sum = 0; sum <= k; sum++) add(ans, dp[n][0][sum]);
		cout << ans << endl;
	}

	return 0;
}