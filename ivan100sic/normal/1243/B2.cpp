#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		map<char, int> mp;

		for (char c : (a+b))
			mp[c]++;
		bool ok = 1;
		for (auto [c, f] : mp)
			if (f % 2) {
				cout << "No\n";
				ok = 0;
				break;
			}
		if (!ok)
			continue;

		cout << "Yes\n";
		vector<pair<int, int>> sol;
		auto z = [&](int i, int j) {
			sol.emplace_back(i+1, j+1);
			swap(a[i], b[j]);
		};

		for (int i=0; i<n; i++) {
			if (a[i] == b[i])
				continue;

			int j = find(b.begin()+i+1, b.end(), b[i]) - b.begin();
			if (j != n) {
				z(i, j);
			} else {
				j = find(a.begin()+i+1, a.end(), b[i]) - a.begin();
				z(j, j);
				z(i, j);
			}
		}

		cout << sol.size() << '\n';
		for (auto [x, y] : sol)
			cout << x << ' ' << y << '\n';
	}
}