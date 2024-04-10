// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	string s;
	cin >> s;

	vector<pair<int, char>> v;
	for (char c : s) {
		if (v.size() && v.back().second == c) {
			v.back().first++;
		} else {
			v.emplace_back(1, c);
		}
	}

	int k = v.size();
	if (k % 2) {
		bool ok = 1;
		for (int i=0; i<k/2; i++) {
			if (v[i].first + v[k-1-i].first == 2 || v[i].second != v[k-1-i].second) {
				ok = 0;
			}
		}

		ok &= v[k/2].first >= 2;

		if (ok) {
			cout << v[k/2].first + 1 << '\n';
			return 0;
		}
	}

	cout << "0\n";
}