#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int n;
string a[1005], b[1005];
char first[1005], second[1005], bind[1005];

bool bad = false;

bool try_match(int x, char letter, map<char, int>& m) {
	if (!m[letter]) {
		bind[x] = letter;
		m[letter] = x;
		return true;
	} else {
		int y = m[letter];

		if (y == -1) {
			return false;
		}

		char other = first[y] ^ second[y] ^ letter;

		bind[y] = 0;
		m[letter] = 0;

		bool succ = try_match(y, other, m);

		if (succ) {
			m[letter] = x;
			bind[x] = letter;
			return true;
		} else {
			m[letter] = y;
			bind[y] = letter;
			return false;
		}
	}
}

void solve(vector<int> idx) {
	map<char, vector<int>> du;
	map<char, int> m;

	for (int x : idx) {
		char f = first[x];
		char s = second[x];

		du[f].push_back(x);		
	}

	vector<int> lepi;

	for (char a='A'; a<='Z'; a++) {
		if (du[a].size() >= 2) {
			// svima mecujem zivot
			for (int x : du[a]) {
				char f = first[x];
				char s = second[x];

				if (!m[s]) {
					m[s] = -1;
					bind[x] = s;
				} else {
					bad = true;
				}
			}
		} else if (du[a].size() == 1) {
			lepi.push_back(du[a][0]);
		}
	}

	for (int x : lepi) {
		bool succ = try_match(x, first[x], m);
		if (!succ) {
			bool suc2 = try_match(x, second[x], m);
			if (!suc2) {
				bad = true;
				return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i] >> b[i];
		first[i] = a[i][2];
		second[i] = b[i][0];
	}

	for (char x='A'; x<='Z'; x++) {
		for (char y='A'; y<='Z'; y++) {
			vector<int> idx;
			for (int i=1; i<=n; i++) {
				if (a[i][0] == x && a[i][1] == y) {
					idx.push_back(i);
				}
			}
			solve(idx);
		}
	}

	if (bad) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	for (int i=1; i<=n; i++) {
		cout << a[i][0] << a[i][1] << bind[i] << '\n';
	}
}