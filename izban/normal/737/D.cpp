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

const int MAXN = 4020;
const int MAXD = 66;
const int MAXS = 93;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;
int INF;

int dp[MAXN][MAXD * 2 + 1][MAXS][2];

int n;
int a[MAXN];
int s[MAXN];

int getSum(int l, int r) {
	return s[r + 1] - s[l];
}

int getdp(int i, int d, int s, int t) {
	if (dp[i][d + MAXD][s][t] != INF) {
		return dp[i][d + MAXD][s][t];
	}

	int left = i;
	int right = left + d;
	dp[i][d + MAXD][s][t] = -2e9;


	if (t == 0) {
		if (left + right + s <= n) {
			dp[i][d + MAXD][s][t] = max(dp[i][d + MAXD][s][t], -getdp(i + s, d - s, s, t ^ 1) + getSum(left, left + s - 1));
		}
		else dp[i][d + MAXD][s][t] = 0;
		if (left + right + s + 1 <= n) {
			dp[i][d + MAXD][s][t] = max(dp[i][d + MAXD][s][t], -getdp(i + s + 1, d - s - 1, s + 1, t ^ 1) + getSum(left, left + s));
		}
	}
	if (t == 1) {
		if (left + right + s <= n) {
			dp[i][d + MAXD][s][t] = max(dp[i][d + MAXD][s][t], -getdp(i, d + s, s, t ^ 1) + getSum(n - 1 - right - s + 1, n - 1 - right));
		}
		else dp[i][d + MAXD][s][t] = 0;
		if (left + right + s + 1 <= n) {
			dp[i][d + MAXD][s][t] = max(dp[i][d + MAXD][s][t], -getdp(i, d + s + 1, s + 1, t ^ 1) + getSum(n - 1 - right - s, n - 1 - right));
		}
	}
	return dp[i][d + MAXD][s][t];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (cin >> n) {
		for (int i = 0; i < n; i++) cin >> a[i];

		//n = 4000;
		//for (int i = 0; i < n; i++) a[i] = (rand() + rand() - rand()) % (int)(1e5);

		for (int i = 0; i < n; i++) s[i + 1] = s[i] + a[i];
		memset(dp, 63, sizeof(dp));
		INF = dp[0][0][0][0];

		cout << getdp(0, 0, 1, 0) << endl;
	}
	return 0;
}