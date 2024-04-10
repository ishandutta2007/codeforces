#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <cmath>

using namespace std;



int main() {
	int n, k;
	cin >> n >> k;
	vector<char> bee(n);
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		bee[i] = s[i];
	}
	sort(bee.begin(), bee.end());
	/*for (int i = 0; i < n; i++) {
		cout << bee[i];
	}
	vector<pair<int, int>> dp(n);
	for (int i = n - 1; i >= 0; i--) {
		dp[i].first = bee[i] - 96;
		dp[i].second = 1;
		for (int j = n - 1; j > i; j--) {
			if (dp[j].second < k and bee[j] - bee[i] > 1 and dp[j].first + bee[i] - 96 > dp[i].first) {
				dp[i].first = dp[j].first + bee[i] - 96;
				dp[i].second = dp[j].second + 1;
			}
		}
	}*/
	int last = (int)bee[0];
	int ans = (int)bee[0] - 96;
	int cur = 1;
	for (int i = 1; i < n; i++) {
		if (cur == k) break;
		if ((int)bee[i] - last > 1) {
			last = (int)bee[i];
			ans += last - 96;
			cur++;
		}
	}
	if (cur != k) {
		cout << -1 << "\n";
	}
	else {
		cout << ans << "\n";
	}
	//system("pause");
	return 0;
}