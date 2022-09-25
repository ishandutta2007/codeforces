#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 12, maxk = 1 << 10;
const int inf = 1000000007;
const int mod = 1000000007;

int n, k;
char a[maxn][maxn];
int sum[maxn][maxn];
int dp[maxk][maxn], opt[maxk][maxn];

void reading() {
	scanf("%d%d", &n, &k); getchar();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = getchar() - '0';
			getchar();
		}
	}
}

int cost(int l, int r) {
	return sum[r][r] - sum[l - 1][r] - sum[r][l - 1] + sum[l - 1][l - 1];
}

void compute(int d, int l, int r, int optL, int optR) {
	if (l > r) return;
	if (l == r) {
		for (int i = optL; i <= optR; i++) 
			dp[d][l] = min(dp[d][l], dp[d - 1][i] + cost(i + 1, l));
		return;
	}

	int m = (l + r) >> 1, opt = -1;
	for (int i = optL; i <= optR; i++) {
		if (dp[d][m] > dp[d - 1][i] + cost(i + 1, m)) {
			dp[d][m] = dp[d - 1][i] + cost(i + 1, m);
			opt = i;
		}
	}

	compute(d, l, m - 1, optL, opt);
	compute(d, m + 1, r, opt, optR);
}

int slowsolve() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
		}
	}

	for (int i = 0; i <= k; i++) for (int j = 0; j <= n; j++) dp[i][j] = inf;
	dp[0][0] = 0;
	for (int i = 1; i <= k; i++) {
		compute(i, 1, n, 0, n - 1);
	}
	assert(!(dp[k][n] % 2));
	return dp[k][n] / 2;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	reading();
	cout << slowsolve() << endl;

	return 0;
}