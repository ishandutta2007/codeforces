#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s, p;

	map<char, char> m;

	cin >> s >> p;
	int c = 0;

	bool bad = false;

	for (int i=0; i<s.size(); i++) {
		if (s[i] == p[i]) {
			if (!m[s[i]]) {
				m[s[i]] = s[i];
			} else if (m[s[i]] != s[i]) {
				bad = true;
			}			
		} else {
			if (!m[s[i]] && !m[p[i]]) {
				m[s[i]] = p[i];
				m[p[i]] = s[i];
				c++;
			} else if (m[s[i]] != p[i] || m[p[i]] != s[i]) {
				bad = true;
			}
		}
	}

	if (bad) {
		c = -1;
	}

	cout << c << '\n';

	if (c >= 0) {
		for (auto p : m) {
			if (p.first < p.second) {
				cout << p.first << ' ' << p.second << '\n';
			}
		}
	}

}