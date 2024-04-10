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

const double eps = 1e-9;

const int MAXN = 1 << 18;
const int MOD = 1000 * 1000 * 1000 + 7;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.first + a.second < b.first + b.second;
}

int fct[MAXN], ofct[MAXN];

int bin(int x, int n) {
	if (n == 0) return 1 % MOD;
	int res = bin(x, n / 2);
	res = 1LL * res * res % MOD;
	if (n % 2 == 1) res = 1LL * res * x % MOD;
	return res;
}

int inv(int x) {
	return bin(x, MOD - 2);
}

int c(int n, int k) {
	return 1LL * fct[n] * ofct[k] % MOD * ofct[n - k] % MOD;
}

int cnt(int x, int y) {
	if (x < 0 || y < 0) return 0;
	return c(x + y, x);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	fct[0] = 1;
	ofct[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fct[i] = 1LL * fct[i - 1] * i % MOD;
		ofct[i] = 1LL * ofct[i - 1] * inv(i) % MOD;
	}

	int h, w, n;
	while (scanf("%d%d%d", &h, &w, &n) == 3) {
		vector<pair<int, int> > a(n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a[i].first, &a[i].second);
		}
		a.push_back(make_pair(h, w));
		sort(a.begin(), a.end(), cmp);

		vector<int> dp(n + 1);
		for (int i = 0; i <= n; i++) {
			dp[i] = cnt(a[i].first - 1, a[i].second - 1);
			for (int j = 0; j < i; j++) {
				dp[i] = (dp[i] - 1LL * dp[j] * cnt(a[i].first - a[j].first, a[i].second - a[j].second) % MOD + MOD) % MOD;
			}
		}
		cout << dp[n] << endl;
	}

	return 0;
}