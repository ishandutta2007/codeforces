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

	string s;
	getline(cin, s);
	s += ' ';

	int state = 0;
	string p;
	for (char x : s) {
		if (state == 0) {
			if (x == '"') {
				state = 2;
			} else if (x == ' ') {
				// nista
			} else {
				state = 1;
				p += x;
			}
		} else if (state == 2) {
			if (x == '"') {
				cout << "<" << p << ">\n";
				state = 0;
				p = "";
			} else {
				p += x;
			}
		} else if (state == 1) {
			if (x == '"') {
				cout << "<" << p << ">\n";
				state = 2;
				p = "";
			} else if (x == ' ') {
				cout << "<" << p << ">\n";
				state = 0;
				p = "";
			} else {
				p += x;
			}
		}
	}
}