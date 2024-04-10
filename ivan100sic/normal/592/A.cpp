#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string s[8];
basic_string<int> w[8], b[8];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<8; i++)
		cin >> s[i];

	for (int i=0; i<8; i++) {
		for (int j=0; j<8; j++) {
			if (s[i][j] == 'W')
				w[j] += i;
			else if (s[i][j] == 'B')
				b[j] += i;
		}
	}

	int wd = 11, bd = 11;
	for (int i=0; i<8; i++) {
		if (w[i].size()) {
			if (b[i].size() == 0 || w[i][0] < b[i][0])
				wd = min(wd, w[i][0]);
		}

		if (b[i].size()) {
			if (w[i].size() == 0 || w[i].back() < b[i].back())
				bd = min(bd, 7 - b[i].back());
		}
	}

	cerr << wd << ' ' << bd << '\n';

	cout << (char)('A' + (bd < wd));
}