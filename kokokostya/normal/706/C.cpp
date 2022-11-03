#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <queue>

using namespace std;

const long long INF = 1000000000000000;

int main() {
	int n;
	cin >> n;
	vector<int> c(n);
	for (int i = 0; i < n; i++)
		cin >> c[i];
	vector< pair<long long, long long> > dp(n, {INF, INF});
	vector<string> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	dp[0] = { 0, c[0] };
	for (int i = 1; i < n; i++) {
		int is = 0;
		for (int j = 0; j < min(arr[i].length(), arr[i - 1].length()); j++)
			if (!is) {
				if (arr[i][j] < arr[i - 1][j])
					is = -1;
				if (arr[i][j] > arr[i - 1][j])
					is = 1;
			}
		if (!is)
			if (arr[i].length() >= arr[i - 1].length())
				is = 1;
		if (is == 1) {
			dp[i].first = min(dp[i].first, dp[i - 1].first);
		}
		reverse(arr[i].begin(), arr[i].end());
		is = 0;
		for (int j = 0; j < min(arr[i].length(), arr[i - 1].length()); j++)
			if (!is) {
				if (arr[i][j] < arr[i - 1][j])
					is = -1;
				if (arr[i][j] > arr[i - 1][j])
					is = 1;
			}
		if (!is)
			if (arr[i].length() >= arr[i - 1].length())
				is = 1;
		if (is == 1) {
			dp[i].second = min(dp[i].second, dp[i - 1].first + c[i]);
		}
		reverse(arr[i - 1].begin(), arr[i - 1].end());
		is = 0;
		for (int j = 0; j < min(arr[i].length(), arr[i - 1].length()); j++)
			if (!is) {
				if (arr[i][j] < arr[i - 1][j])
					is = -1;
				if (arr[i][j] > arr[i - 1][j])
					is = 1;
			}
		if (!is)
			if (arr[i].length() >= arr[i - 1].length())
				is = 1;
		if (is == 1) {
			dp[i].second = min(dp[i].second, dp[i - 1].second + c[i]);
		}
		reverse(arr[i].begin(), arr[i].end());
		is = 0;
		for (int j = 0; j < min(arr[i].length(), arr[i - 1].length()); j++)
			if (!is) {
				if (arr[i][j] < arr[i - 1][j])
					is = -1;
				if (arr[i][j] > arr[i - 1][j])
					is = 1;
			}
		if (!is)
			if (arr[i].length() >= arr[i - 1].length())
				is = 1;
		if (is == 1) {
			dp[i].first = min(dp[i].first, dp[i - 1].second);
		}
	}
	if (min(dp[n - 1].first, dp[n - 1].second) != INF)
		cout << min(dp[n - 1].first, dp[n - 1].second);
	else
		cout << -1;
	return 0;
}