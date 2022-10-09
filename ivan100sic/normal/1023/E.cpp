#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<vector<int>, bool> kes;
int n;

bool bad(int x) {
	return x < 1 || x > n;
}

bool ask(int r1, int c1, int r2, int c2) {

	if (bad(r1) || bad(c1) || bad(r2) || bad(c2))
		return false;

	vector<int> v = {r1, c1, r2, c2};
	if (kes.count(v))
		return kes[v];

	cout << "? " << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << '\n' << flush;

	string s;
	cin >> s;

	bool k = s == "YES";
	kes[v] = k;
	return k;
}

void ans(string s) {
	cout << "! " << s << '\n' << flush;
	exit(0);
}

bool moze[505];

string rev(string s) {
	reverse(s.begin(), s.end());
	return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;

	string sol, donji, gornji;
	// gornji deo puta
	{
		int x = 1, y = 1;
		for (int i=1; i<n; i++) {

			cerr << "i = " << i << '\n';

			if (ask(x+1, y, n, n)) {
				gornji += 'D';
				x++;
			} else {
				gornji += 'R';
				y++;
			}
		}
	}

	// donji deo puta
	{
		int x = n, y = n;
		for (int i=1; i<n; i++) {
			if (ask(1, 1, x, y-1)) {
				y--;
				donji += 'R';
			} else {
				x--;
				donji += 'D';
			}
		}
	}

	sol = gornji + rev(donji);
	ans(sol);
}