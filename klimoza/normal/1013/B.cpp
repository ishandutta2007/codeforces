#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <cmath>

using namespace std;


int main() {
	int	n, x;
	cin >> n >> x;
	vector<int> dp(100001, -1);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int ans = 1000000000;
	for (int i = 0; i < n; i++) {
		int last = 0;
		int t = 0;
		while (last != a[i]) {
			if (last == 0) {
				last = a[i];
			}
			if (dp[a[i]] != -1) {
				ans = min(ans, t + dp[a[i]]);
			}
			dp[a[i]] = t;
			last = a[i];
			a[i] = a[i] & x;
			t++;
		}
	}
	if (ans == 1000000000) {
		cout << -1 << "\n";
	} else	cout << ans << "\n";
	//system("pause");
	return 0;
}