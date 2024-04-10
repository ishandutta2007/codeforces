#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<string> s;

bool eq(char a, char b, char c, char d) {
	return a == b && b == c && c == d;
}

int winner(vector<string> ss, char a, char b) {
	string s = ss[0] + ss[1] + ss[2];
	if (eq(s[0], s[1], s[2], a)) return 1;
	if (eq(s[3], s[4], s[5], a)) return 1;
	if (eq(s[6], s[7], s[8], a)) return 1;
	if (eq(s[0], s[3], s[6], a)) return 1;
	if (eq(s[1], s[4], s[7], a)) return 1;
	if (eq(s[2], s[5], s[8], a)) return 1;
	if (eq(s[0], s[4], s[8], a)) return 1;
	if (eq(s[2], s[4], s[6], a)) return 1;

	if (eq(s[0], s[1], s[2], b)) return 2;
	if (eq(s[3], s[4], s[5], b)) return 2;
	if (eq(s[6], s[7], s[8], b)) return 2;
	if (eq(s[0], s[3], s[6], b)) return 2;
	if (eq(s[1], s[4], s[7], b)) return 2;
	if (eq(s[2], s[5], s[8], b)) return 2;
	if (eq(s[0], s[4], s[8], b)) return 2;
	if (eq(s[2], s[4], s[6], b)) return 2;

	return 0;
}

bool cirek(vector<string> c, vector<string> s, char a, char b) {
	if (c == s)
		return true;
	if (winner(c, a, b) != 0)
		return false;
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			if (c[i][j] == '.') {
				auto c2 = c;
				c2[i][j] = a;
				if (cirek(c2, s, b, a))
					return true;
			}
		}
	}
	return false;
}

bool check_legal(vector<string> s, char a, char b) {
	return cirek({"...", "...", "..."}, s, a, b);
}

int cnt(vector<string> s) {
	int c = 0;
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			c += s[i][j] != '.';
		}
	}
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	s.resize(3);
	for (string& x : s)
		cin >> x;

	bool ok = false;
	ok |= check_legal(s, 'X', '0');
	// ok |= check_legal(s, '0', 'X');

	if (!ok)
		cout << "illegal\n";
	else if (winner(s, 'X', '0') == 1)
		cout << "the first player won\n";
	else if (winner(s, 'X', '0') == 2)
		cout << "the second player won\n";
	else if (cnt(s) == 9)
		cout << "draw\n";
	else
		cout << (cnt(s) % 2 ? "second\n" : "first\n");
}