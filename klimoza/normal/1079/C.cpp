#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>
#include <deque>
#include <algorithm>

using namespace std;

typedef long long int ll;


int main() {
	int n;
	cin >> n;
	vector<vector<pair<bool, int>>> dp(n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i].resize(5);
		if (i == 0) {
			for (int j = 0; j < 5; j++) {
				dp[i][j] = { true, -1 };
			}
		}
		else {
			for (int j = 0; j < 5; j++) {
				pair<bool, int> nu = { false, -1 };
				for (int k = 0; k < 5; k++) {
					if (a[i] > a[i - 1] && j > k && dp[i - 1][k].first) {
						nu = { true, k };
						break;
					}
					else if (a[i] < a[i - 1] && j < k && dp[i - 1][k].first) {
						nu = { true, k };
						break;
					}
					else if (a[i] == a[i - 1] && j != k && dp[i - 1][k].first) {
						nu = { true, k };
						break;
					}
				}
				dp[i][j] = nu;
			}
		}
	}
	vector<int> ans(n);
	bool fl = false;
	int nxt = 0;
	for (int i = 0; i < 5; i++) {
		if (dp[n - 1][i].first) {
			fl = true;
			nxt = dp[n - 1][i].second;
			ans[n - 1] = i + 1;
			break;
		}
	}
	int cur = n - 2;
	if (!fl) {
		cout << -1 << "\n";
		return 0;
	}
	while (cur >= 0) {
		ans[cur] = nxt + 1;
		nxt = dp[cur][nxt].second;
		cur--;
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	//system("pause");  
	return 0;
}