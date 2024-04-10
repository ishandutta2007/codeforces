#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
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

void solve() {
	int n;
	cin >> n;
	vector<int> arr1(n);
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	int m;
	cin >> m;
	vector<int> arr2(m);
	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}
	vector<int> ans;
	vector<vector<int>> dp(n, vector<int>(m));

	dp[n - 1][m - 1] = max(arr1[n - 1] + arr2[m - 1], max(arr1[n - 1], arr2[m - 1]));
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			int now = n - i + m - j;
			if (i == n - 1 && j == m - 1) {
				continue;
			}
			if (i == n - 1) {
				dp[i][j] = max(max(dp[i][j + 1] + arr2[j], arr2[j]), arr1[i]);
				continue;
			}
			if (j == m - 1) {
				dp[i][j] = max(max(dp[i + 1][j] + arr1[i], arr1[i]), arr2[j]);
				continue;
			}
			dp[i][j] = max(max(arr2[j], arr1[i]), max(dp[i][j + 1] + arr2[j], dp[i + 1][j] + arr1[i]));
		}
	}
	cout << max(0, dp[0][0]) << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}