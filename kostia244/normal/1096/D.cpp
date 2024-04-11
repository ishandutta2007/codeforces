#include <bits/stdc++.h>
using namespace std;

long long n, cost[100005], dp[100005][4];
string s, sk = "hard";

int main() {
	memset(cost, 0, sizeof cost);
	cin >> n;
	cin >> s;
	for(int i = 0; i < n; i++) {
		cin >>cost[i];
	}

	for(int i = 0; i <= n; i++)
		for(int j = 0; j < 4; j++)
			dp[i][j] = 100000000000000000ll;

	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;
	dp[0][3] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 4; j++) {
			if(j != 3 && s[i] == sk[j]) {
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
			}
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + (s[i] == sk[j] ? cost[i] : 0));
		}
	}

	cout << *min_element(begin(dp[n]), end(dp[n]));

	return 0;
}