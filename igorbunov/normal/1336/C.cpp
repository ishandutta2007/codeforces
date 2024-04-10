#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
 
using namespace std;

#define s second
#define f first
#define push_back emplace_back
#define endl "\n"

int P = 998244353;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s, t;
	cin >> s >> t;
	int n = s.size();
	int m = t.size();
	vector<vector<int>> dp(n, vector<int>(m + 1));
	for (int i = 0; i < m; i++) {
		if (t[i] == s[0]) {
			dp[0][i] = 1;
		}
	}
	dp[0][m] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i] == t[j]) {
				dp[i][j] += dp[i - 1][j + 1];
			}
			if (j + i >= m || s[i] == t[i + j]) {
				dp[i][j] += dp[i - 1][j];
			}
			if (dp[i][j] >= P) {
				dp[i][j] -= P;
			}
		}
		dp[i][m] = dp[i - 1][m] * 2;
		if (dp[i][m] >= P) {
			dp[i][m] -= P;
		}
	}
	int ans = 0;
	for (int i = m - 1; i < n; i++) {
		ans += dp[i][0];
		if (ans >= P) {
			ans -= P;
		}
	}
	cout << (ans * 2) % P;
}