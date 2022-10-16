#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int l = 0;
	set<int> ost;
	for (int i = 1; i <= 2 * n; i++) {
		ost.insert(i);
	}
	for (int i = 0; i < n; i++) {
		ost.erase(arr[i]);
	}
	for (int i = 0; i < n; i++) {
		while (ost.size() && *(ost.begin()) < arr[i]) {
			ost.erase(ost.begin());
		}
		if (ost.size() == 0) {
			break;
		}
		ost.erase(ost.begin());
		l++;
	}
	ost.clear();
	for (int i = 1; i <= 2 * n; i++) {
		ost.insert(-i);
	}
	for (int i = 0; i < n; i++) {
		ost.erase(-arr[i]);
	}
	int r = 0;
	for (int i = n - 1; i >= 0; i--) {
		while (ost.size() && (*(ost.begin())) * -1 > arr[i]) {
			ost.erase(ost.begin());
		}
		if (ost.size() == 0) {
			break;
		}
		ost.erase(ost.begin());
		r++;
	}
	cout << abs(r + l - n) + 1 << endl;
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