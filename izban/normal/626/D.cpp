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

const int MAXN = 5 * 1024;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

int cnt[MAXN];
ll dp[4][MAXN * 6 + 1];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (cin >> n) {
	//n = 2000; {
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		//for (int i = 0; i < n; i++) a[i] = rand() % 5000 + 1;


		memset(cnt, 0, sizeof(cnt));
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) cnt[abs(a[i] - a[j])]++;

		dp[0][MAXN * 3] = 1;
		for (int it = 0; it < 3; it++) {
			for (int dif = -MAXN * 3; dif <= MAXN * 3; dif++) {
				if (!dp[it][dif + 3 * MAXN]) continue;
				for (int ndif = 1; ndif < MAXN; ndif++) if (cnt[ndif]) {
					if (it == 2) dp[it + 1][dif + ndif + MAXN * 3] += dp[it][dif + 3 * MAXN] * cnt[ndif];
					if (it < 2) dp[it + 1][dif - ndif + MAXN * 3] += dp[it][dif + 3 * MAXN] * cnt[ndif];
				}
			}
		}
		ll sum = 0;
		for (int dif = 1; dif <= MAXN * 3; dif++) {
			sum += dp[3][dif + 3 * MAXN];
		}
		ll all = 0;
		for (int dif = -3 * MAXN; dif <= 3 * MAXN; dif++) all += dp[3][dif + 3 * MAXN];
		double ans = sum / (double)all;
		printf("%.15f\n", ans);
	}

	return 0;
}