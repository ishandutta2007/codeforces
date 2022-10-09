#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s, p;
	getline(cin, s);
	for (char x : s) {
		if (x == ' ') {
			if (p.size() && p.back() == ' ') {
				//
			} else {
				p += ' ';
			}
		} else if (isalpha(x)) {
			p += x;
		} else {
			if (p.size() && p.back() == ' ') {
				p.pop_back();
			}
			p += x;
			p += ' ';
		}
	}
	if (p.size() && p.back() == ' ') {
		p.pop_back();
	}
	cout << p << '\n';
}