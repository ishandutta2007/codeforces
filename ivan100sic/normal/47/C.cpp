// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

string s[6];
string a[100];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	for (int i=0; i<6; i++) {
		cin >> s[i];
	}

	vector<string> ans;

	sort(s, s+6);

	do {
		for (int i=0; i<100; i++) a[i] = string(100, '.');
		if (s[0].size() + s[2].size() != s[1].size() + 1) {
			continue;
		}

		if (s[3].size() + s[5].size() != s[4].size() + 1) {
			continue;
		}

		bool ok = 1;
		int u = 0, v = 0;

		auto st = [&](string t, int x, int y, int dx, int dy) {
			for (int i=0; i<(int)t.size(); i++) {
				char& c = a[x+i*dx][y+i*dy];
				if (c != '.' && c != t[i]) {
					ok = 0;
					return;
				} else {
					u = max(u, x+i*dx);
					v = max(v, y+i*dy);
					c = t[i];
				}
			}
		};

		st(s[0], 0, 0, 0, 1);
		st(s[1], s[3].size() - 1, 0, 0, 1);
		st(s[2], s[4].size() - 1, s[0].size() - 1, 0, 1);
		st(s[3], 0, 0, 1, 0);
		st(s[4], 0, s[0].size() - 1, 1, 0);
		st(s[5], s[3].size() - 1, s[1].size() - 1, 1, 0);

		if (!ok) continue;

		u++, v++;
		vector<string> sol;
		for (int i=0; i<u; i++) {
			sol.push_back(a[i].substr(0, v));
		}

		if (ans.empty() || sol < ans) ans = sol;
	} while (next_permutation(s, s+6));

	if (ans.empty()) {
		cout << "Impossible\n";
	} else {
		for (auto s : ans) cout << s << '\n';
	}
}