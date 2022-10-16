#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	vector<int> was(n + 1);
	was[0] = 0;
	int need = 0;
	int need_time = 0;
	int time1 = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].first >= need_time) {
			was[i] = need;
			need_time = abs(need - arr[i].second) + arr[i].first;
			need = arr[i].second;
		} else {
			if (was[i - 1] < need) {
				was[i] = was[i - 1] + arr[i].first - arr[i - 1].first;
			} else {
				was[i] = was[i - 1] - arr[i].first + arr[i - 1].first;
			}
		}
	}
	was[n] = need;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (abs(was[i] - was[i + 1]) == (abs(was[i] - arr[i].second) + abs(was[i + 1] - arr[i].second)));
	}
	cout << ans << endl;

}

signed main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}