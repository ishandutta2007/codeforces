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

const int MAXN = 105;
const int MAXM = 3 * MAXN;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

int n, T;
int a[MAXN];
int dp[MAXN][MAXM];
int b[MAXM][MAXM];

int to[MAXM][MAXM];
int from[MAXM][MAXM];


int fastsolve() {
	for (int start = 0; start < MAXM; start++) {
		memset(dp, -1, sizeof(dp));
		dp[0][start] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < MAXM; j++) {
				if (dp[i][j] == -1) continue;
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
				if (j + 1 < MAXM) dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
				if (a[i] == j) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + 1);
			}
		}
		for (int i = 0; i < MAXM; i++) b[start][i] = dp[n][i];
	}

	memset(to, -1, sizeof(to));
	memset(from, -1, sizeof(from));
	for (int i = 0; i < MAXM; i++) to[i][0] = 0;
	for (int i = 0; i < MAXM; i++) {
		for (int j = i + 1; j < MAXM; j++) {
			if (b[i][j] == -1) continue;
			for (int k = 0; k < MAXM - 1; k++) {
				if (to[i][k] == -1) continue;
				to[j][k + 1] = max(to[j][k + 1], to[i][k] + b[i][j]);
			}
		}
	}
	for (int i = 0; i < MAXM; i++) from[i][0] = 0;
	for (int j = MAXM - 1; j >= 0; j--) {
		for (int i = j - 1; i >= 0; i--) {
			if (b[i][j] == -1) continue;
			for (int k = 0; k < MAXM - 1; k++) {
				if (from[j][k] == -1) continue;
				from[i][k + 1] = max(from[i][k + 1], from[j][k] + b[i][j]);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < MAXM; i++) {
		for (int j = 0; j < MAXM; j++) {
			for (int k = 0; k < MAXM; k++) {
				if (j + k <= T && to[i][j] != -1 && from[i][k] != -1 && b[i][i] != -1) {
					ans = max(ans, to[i][j] + from[i][k] + b[i][i] * (T - j - k));
				}
			}
		}
	}

	return ans;
}

void gen() {
	n = rand() % 10 + 1;
	T = rand() % 10 + 1;
	for (int i = 0; i < n; i++) a[i] = rand() % 2 + 1;
}

int slowsolve() {
	vector<int> dp(n * T, 1);
	int ans = -1;
	for (int i = 0; i < n * T; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i % n] >= a[j % n]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}
	return ans;
}

void stress() {
	for (int it = 0;; it++) {
		cerr << it << endl;
		gen();
		int ans1 = fastsolve();
		int ans2 = slowsolve();
		if (ans1 != ans2) {
			cout << ans1 << " instead of " << ans2 << endl;
			cout << n << " " << T << endl;
			for (int i = 0; i < n; i++) cout << a[i] << " \n"[i + 1 == n];
			fastsolve();
			slowsolve();
			exit(0);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	//stress();

	while (scanf("%d%d", &n, &T) == 2) {
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);

		cout << fastsolve() << endl;
	}

	return 0;
}