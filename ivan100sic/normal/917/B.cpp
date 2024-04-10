#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<pair<int, int>> e[105];

int winner[105][105][26];

int solve(int x, int y, int c) {
	if (winner[x][y][c] != 0)
		return winner[x][y][c];
	// moze li prvi igrac da pobedi?
	bool moze = false;
	for (auto ee : e[x]) {
		if (ee.second < c)
			continue;
		moze |= solve(y, ee.first, ee.second) == 2;
		if (moze)
			return winner[x][y][c] = 1;
	}
	return winner[x][y][c] = 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v;
		char c;
		cin >> u >> v >> c;
		e[u] += {v, c - 'a'};
	}

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			cout << (char)(solve(i, j, 0) + 'A' - 1);
		}
		cout << '\n';
	}
}