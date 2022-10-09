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
	map<string, set<string>> mp;
	while (t--) {
		string s;
		cin >> s;
		int q;
		cin >> q;
		while (q--) {
			string p;
			cin >> p;
			mp[s].insert(p);
		}
	}
	cout << mp.size() << '\n';
	for (auto [x, y] : mp) {
		set<string> ok;
		cout << x;
		for (string s : y) {
			bool k = 1;
			for (string t : y) {
				if (s.size() < t.size() && t.substr(t.size()-s.size()) == s)
					k = 0;
			}
			if (k)
				ok.insert(s);
		}
		cout << ' ' << ok.size();
		for (string s : ok)
			cout << ' ' << s;
		cout << '\n';
	}
}