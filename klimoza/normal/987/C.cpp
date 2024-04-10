#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


long long int INF = 1000000000000000;

int main() {
	int n;
	cin >> n;
	vector<int> size(n);
	vector<int> cost(n);
	vector<vector<long long int>> dp(n);
	for (int i = 0; i < n; i++) {
		cin >> size[i];
		dp[i].assign(3, INF);
	}
	for (int i = 0; i < n; i++) cin >> cost[i];
	long long int ans = INF;
	for (int i = 0; i < n; i++) {
		dp[i][0] = cost[i];
		long long int min_2 = INF;
		long long int min_3 = INF;
		for (int j = 0; j < i; j++) {
			if (size[j] < size[i] and dp[j][0] < min_2) min_2 = dp[j][0];
			if (size[j] < size[i] and dp[j][1] < min_3) min_3 = dp[j][1];
		}
		dp[i][1] = min_2 + cost[i];
		dp[i][2] = min_3 + cost[i];
		ans = min(ans, dp[i][2]);
	}
	if (ans == INF) {
		cout << -1 << "\n";
	}
	else {
		cout << ans << "\n";
	}
	//system("pause");
	return 0;
}