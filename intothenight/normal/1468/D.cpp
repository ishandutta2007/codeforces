#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;

	vector<int> s(m);
	for (int i = 0; i < m; i++) {
		cin >> s[i];
	}
	sort(s.begin(), s.end());

	// how many crackers can i lit?
	int lit = min(m, abs(a - b) - 1);
	while (s.size() > lit) s.pop_back();
	m = s.size();

	// how long can I hold up?
	int duration;
	if (a < b) {
		duration = b-1;
	} else {
		duration = n-b;
	}

	// say, I crack K times, then it's optimal to crack from largest s[i] first
	// binary search
	int lo = 0, hi = m;
	while (lo < hi) {
		int mid = (lo + hi + 1)/2;

		bool ok = 1;
		for (int i = mid-1, j = 1; i >= 0; i--, j++) {
			int pop_time = s[i] + j;
			if (pop_time > duration) ok = 0;
		}

		if (ok) {
			lo = mid;
		} else {
			hi = mid-1;
		}
	}
	cout << lo << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}