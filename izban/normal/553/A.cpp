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

const int MAXN = 1024;
const int MOD = 1000 * 1000 * 1000 + 7;

int dp[MAXN][MAXN];
int c[MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	c[0][0] = 1;
	for (int i = 0; i < MAXN - 1; i++) {
		for (int j = 0; j <= i; j++) {
			c[i + 1][j] = (c[i + 1][j] + c[i][j]) % MOD;
			c[i + 1][j + 1] = (c[i + 1][j + 1] + c[i][j]) % MOD;
		}
	}

	int k;
	while (cin >> k) {
		vector<int> a(k);
		for (int i = 0; i < k; i++) cin >> a[i];

		int ans = 1;
		int sum = 0;
		for (int i = 0; i < k; i++) sum += a[i];

		for (int i = k - 1; i >= 0; i--) {
			ans = 1LL * ans * c[sum - 1][a[i] - 1] % MOD;
			sum -= a[i];
		}
		cout << ans << endl;
	}
	return 0;
}