// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

void ans(int x) {
	cout << x << '\n';
	exit(0);
}

bool ok(string s) {
	int c = 0, z = 0;
	for (int i=0; i<(int)s.size(); i++) {
		if (s[i] == '#') {
			if (z == 0) {
				z = 1;
				c++;
			}
		} else {
			z = 0;
		}
	}
	return c <= 1;
}

int n, m;
string s[1005];
bool v[1005][1005];

void dfs(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m || v[x][y] || s[x][y] == '.')
		return;
	v[x][y] = 1;
	dfs(x+1, y);
	dfs(x-1, y);
	dfs(x, y+1);
	dfs(x, y-1);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> s[i];

	// validno?
	for (int i=0; i<n; i++) {
		if (!ok(s[i])) {
			ans(-1);
		}
	}

	for (int j=0; j<m; j++) {
		string t;
		for (int i=0; i<n; i++)
			t += s[i][j];
		if (!ok(t))
			ans(-1);
	}

	// ako su sve vrste okupirane, ne mozes da imas praznu kolonu i obratno
	bool orow = 1, ocol = 1;

	for (int i=0; i<n; i++) {
		int c = 0;
		for (int j=0; j<m; j++) {
			c += s[i][j] == '#';
		}
		if (c == 0)
			orow = 0;
	}

	for (int j=0; j<m; j++) {
		int c = 0;
		for (int i=0; i<n; i++) {
			c += s[i][j] == '#';
		}
		if (c == 0)
			ocol = 0;
	}

	if (orow != ocol) {
		ans(-1);
	}

	int comp = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (!v[i][j] && s[i][j] == '#') {
				comp++;
				dfs(i, j);
			}
		}
	}

	ans(comp);
}