/*#include <string>
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <set>//*/
#include <bits/stdc++.h>

using namespace std;

vector<long long> c;
vector<string> v;


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
	cout << fixed;

	int N;
	cin >> N;
	c = vector<long long>(N+1, 0);
	for (int i = 0; i < N; i++) cin >> c[i+1];
	v = vector<string>(N+1, "");
	for (int i = 0; i < N; i++) cin >> v[i+1];

	vector<vector<long long >> dp(N + 1, vector<long long>(2, 0));

	for (int i = 1; i <= N; i++) {
		string na = v[i - 1];
		string nn = v[i];
		string va(na.rbegin(), na.rend());
		string vn(nn.rbegin(), nn.rend());
		
		long long be_normal = LLONG_MAX;
		long long be_ver = LLONG_MAX;
		if (dp[i - 1][0] != LLONG_MAX) {
			if (na <= nn) {
				be_normal = min(be_normal, dp[i - 1][0]);
			}
			if (na <= vn) {
				be_ver = min(be_ver, dp[i - 1][0] + c[i]);
			}
		}
		if (dp[i - 1][1] != LLONG_MAX) {
			if (va <= nn) {
				be_normal = min(be_normal, dp[i - 1][1]);
			}
			if (va <= vn) {
				be_ver = min(be_ver, dp[i - 1][1] + c[i]);
			}
		}
		dp[i][0] = be_normal;
		dp[i][1] = be_ver;

	}

	long long result = min(dp.back()[0], dp.back()[1]);
	if (result == LLONG_MAX)
		cout << -1 << endl;
	else
		cout << result << endl;
}