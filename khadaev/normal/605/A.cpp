#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		--t;
		a[i] = {t, i};
	}
	sort(a.begin(), a.end());
	int cnt = 1, maxcnt = cnt;
	for (int i = 1; i < n; ++i) {
		if (a[i].second > a[i - 1].second) ++cnt;
		else {
			maxcnt = max(cnt, maxcnt);
			cnt = 1;
		}
	}
	maxcnt = max(cnt, maxcnt);
	cout << n - maxcnt << '\n';
}