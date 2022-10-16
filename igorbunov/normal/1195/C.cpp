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
 
#pragma GCC_OPTIMAZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"

signed main() {
	int n;
	cin >> n;
	vector<int> arr1(n);
	vector<int> arr2(n);

	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}

	for (int j = 0; j < n; j++) {
		cin >> arr2[j];
	}

	vector<vector<int>> dp(n, vector<int>(2, 0));

	dp[0][0] = arr1[0];
	dp[0][1] = arr2[0];

	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);

		dp[i][0] = max(dp[i][0], dp[i - 1][1] + arr1[i]);
		dp[i][1] = max(dp[i][1], dp[i - 1][0] + arr2[i]);
	}

	cout << max(dp[n - 1][0], dp[n - 1][1]);
}