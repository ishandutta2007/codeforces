// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

bool moze(string s, string w) {
	string p[2];
	p[0] = s.substr(0, 13);
	p[1] = s.substr(13);
	reverse(begin(p[1]), end(p[1]));

	auto nadji = [&](char c) -> pair<int, int> {
		for (int i=0; i<2; i++) {
			for (int j=0; j<13; j++) {
				if (p[i][j] == c) {
					return {i, j};
				}
			}
		}
		return {-1, -1};
	};

	auto [x, y] = nadji(w[0]);
	for (int i=1; i<27; i++) {
		auto [x1, y1] = nadji(w[i]);
		if (abs(x1-x) <= 1 && abs(y1-y) <= 1 && (x != x1 || y != y1)) {
			x = x1;
			y = y1;
		} else {
			return false;
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	map<char, basic_string<int>> e;

	string s;
	cin >> s;

	string q;

	set<char> u;
	for (char c : s) {
		if (u.count(c)) {
			continue;
		}
		u.insert(c);
		q += c;
	}

	for (int i=0; i<26; i++) {
		rotate(begin(q), begin(q)+1, end(q));
		if (moze(q, s)) {
			string p[2];
			p[0] = q.substr(0, 13);
			p[1] = q.substr(13);
			reverse(begin(p[1]), end(p[1]));
			cout << p[0] << '\n' << p[1] << '\n';
			return 0;
		}
	}

	cout << "Impossible\n";

}