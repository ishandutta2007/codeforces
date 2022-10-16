#include <bits/stdc++.h>

using namespace std;

//#define int long long


void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (s.back() != ')') {
		cout << "No\n";
		return;
	}
	int ind = s.size() - 1;
	while (ind >= 0 && s[ind - 1] == ')') {
		ind--;
	}
	int cnt = s.size() - ind;
	if (cnt * 2 > s.size()) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
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