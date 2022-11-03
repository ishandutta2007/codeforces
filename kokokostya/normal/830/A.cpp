#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>

using namespace std;

const long long INF = 1e18;

int main() {
	ios_base::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k, p;
	cin >> n >> k >> p;
	vector<long long> a(n), b(k);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < k; i++)
		cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	vector< vector<long long> > dp(n + 1, vector<long long>(k + 1, INF));
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			if(i != n)
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], max(dp[i][j], abs(a[i] - b[j]) + abs(b[j] - p)));
			dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
		}
	}
	cout << dp[n][k];
	return 0;
}