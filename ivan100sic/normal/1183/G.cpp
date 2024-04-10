#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void solve() {
	int n;
	cin >> n;
	map<int, pair<int, int>> bf;
	for (int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		auto& it = bf[x];
		it.first++;
		it.second += y;
	}
	multiset<int> xd;
	map<int, multiset<int>> ms;
	for (auto [x, p] : bf)
		ms[p.first].insert(p.second);
	int candies = 0, fsum = 0;
	for (int i=n; i>=1; i--) {
		for (int x : ms[i])
			xd.insert(x);

		if (xd.size()) {
			candies += i;
			fsum += min(i, *prev(xd.end()));
			xd.erase(prev(xd.end()));
		}
	}
	cout << candies << ' ' << fsum << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}