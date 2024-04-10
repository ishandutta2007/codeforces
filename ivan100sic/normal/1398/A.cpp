// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<int, int>> a(n);
		for (int i=0; i<n; i++) {
			cin >> a[i].first;
			a[i].second = i+1;
		}
		sort(begin(a), end(a));
		if (a[0].first + a[1].first <= a.back().first) {
			int b[3] = {a[0].second, a[1].second, a.back().second};
			sort(b, b+3);
			cout << b[0] << ' ' << b[1] << ' ' << b[2] << '\n';
		} else {
			cout << "-1\n";
		}
	}
}