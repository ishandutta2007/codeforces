#include <iostream>
#include <string>
using namespace std;

string good, pattern;
string lefts, rights;
bool star;
bool gg[256];
int n;

bool match(string a, string p) {
	for (int i=0; i<(int)a.size(); i++) {
		if (a[i] != p[i]) {
			if (p[i] != '?') {
				return false;
			}
			if (!gg[(int)a[i]]) {
				return false;
			}
		}
	}
	return true;
}

bool all_bad(string s) {
	for (int x : s) {
		if (gg[x]) {
			return false;
		}
	}
	return true;
}

int main() {
	cin >> good >> pattern >> n;
	for (int x : good) {
		gg[x] = true;
	}
	star = false;
	for (int i=0; i<(int)pattern.size(); i++) {
		if (pattern[i] == '*') {
			lefts = pattern.substr(0, i);
			rights = pattern.substr(i+1);
			star = true;
		}
	}
	//cerr << '\n';
	//cerr << lefts << ' ' << rights << '\n';
	while (n--) {
		if (star) {
			string s;
			cin >> s;
			if (s.size() < lefts.size() + rights.size()) {
				cout << "NO\n";
				continue;
			}
			string sl = s.substr(0, lefts.size());
			string sr = s.substr(s.size() - rights.size());
			string sm = s.substr(lefts.size(), s.size() - lefts.size() - rights.size());

			//cerr << sl << ' ' << sr << ' ' << sm << '\n';

			if (!match(sl, lefts)) {
				cout << "NO\n";
				continue;
			}

			if (!match(sr, rights)) {
				cout << "NO\n";
				continue;
			}

			if (!all_bad(sm)) {
				cout << "NO\n";
				continue;
			}

			cout << "YES\n";
		} else {
			string s;
			cin >> s;
			if (s.size() == pattern.size() && match(s, pattern)) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}
}