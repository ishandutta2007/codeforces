#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

basic_string<pair<char, int>> resi(string s) {
	basic_string<pair<char, int>> t;
	for (char x : s) {
		if (t.size() == 0) {
			t += {x, 1};
		} else if (t.back().first == x) {
			t.back().second++;
		} else {
			t += {x, 1};
		}
	}
	return t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		auto c = resi(a);
		auto d = resi(b);
		bool ok = true;
		if (c.size() == d.size()) {
			for (int i=0; i<(int)c.size(); i++) {
				if (c[i].first != d[i].first) {
					ok = false;
				}
				if (c[i].second > d[i].second) {
					ok = false;
				}
			}
		} else {
			ok = false;
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
}