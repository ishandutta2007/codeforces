// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n;
	cin >> n;
	vector<pair<int, int>> v;
	set<int> s;
	int l = 1;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		if (s.count(x)) {
			v.push_back({l, i});
			s = {};
			l = i + 1;
		} else {
			s.insert(x);
		}
	}

	if (v.size() == 0) {
		cout << "-1\n";
	} else {
		v.back().second = n;
		cout << v.size() << '\n';
		for (auto [l, r] : v)
			cout << l << ' ' << r << '\n';
	}
}