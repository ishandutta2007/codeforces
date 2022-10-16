#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	vector<int> arr(3);
	cin >> arr[0] >> arr[1] >> arr[2];
	sort(arr.begin(), arr.end());
	int sum = arr[0] + arr[1] + arr[2];
	if (sum % 9 != 0) {
		cout << "No\n";
		return;
	}
	if (arr[0] * 9 < sum) {
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
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