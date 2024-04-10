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

	int t;
	cin >> t;
	while (t--) {
		map<char, set<char>> mp;
		string s;
		cin >> s;
		int n = s.size();
		for (int i=1; i<n; i++) {
			char u = s[i-1], v = s[i];
			mp[u].insert(v);
			mp[v].insert(u);
		}

		string kec, sol;
		int ok = 1;
		for (auto [x, v] : mp) {
			if (v.size() > 2) {
				ok = 0;
			} else if (v.size() == 1) {
				kec += x;
			}
		}

		set<char> vis;

		for (char c : kec) {
			if (vis.count(c))
				continue;
			vis.insert(c);
			string q;
			q += c;
			size_t qs = 0;
			while (qs != q.size()) {
				char x = q[qs++];
				sol += x;
				for (char y : mp[x]) {
					if (!vis.count(y)) {
						vis.insert(y);
						q += y;
					}
				}
			}
		}

		for (char c='a'; c<='z'; c++)
			if (!mp.count(c) && !vis.count(c))
				sol += c;

		if (ok && sol.size() == 26) {
			cout << "YES\n";
			cout << sol << '\n';
		} else {
			cout << "NO\n";
		}
	}
}