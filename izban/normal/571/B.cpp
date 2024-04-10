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

const int MAXN = 300100;
const int MAXK = 5010;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

int n, k;
int a[MAXN];
int dp[MAXK][MAXK];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d%d", &n, &k) == 2) {
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		sort(a, a + n);

		int blocks = k;
		int len = n / k;
		int cntBiggerBlocks = n % k;

		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		for (int i = 0; i < blocks; i++) {
			for (int j = 0; j <= i; j++) {
				if (dp[i][j] == -1) continue;
				int pos = i * len + j;
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + (pos ? a[pos] - a[pos - 1] : 0));
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + (pos ? a[pos] - a[pos - 1] : 0));
			}
		}
		int ans = (a[n - 1] - a[0]) - dp[k][cntBiggerBlocks];
		cout << ans << endl;
	}

	return 0;
}