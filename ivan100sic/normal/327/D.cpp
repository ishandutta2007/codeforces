#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<tuple<char, int, int>> sol;
string s[505];

void dfs(int x, int y, int d) {
	auto go = [&](int p, int q, int d) {
		if (p < 0 || q < 0 || p >= n || q >= m)
			return;
		if (s[p][q] != '.')
			return;
		dfs(p, q, d);
	};

	s[x][y] = 'B';
	sol += {'B', x, y};
	go(x+1, y, d+1);
	go(x-1, y, d+1);
	go(x, y+1, d+1);
	go(x, y-1, d+1);
	if (d) {
		sol += {'D', x, y};
		sol += {'R', x, y};
		s[x][y] = 'R';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> s[i];
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (s[i][j] == '.') {
				dfs(i, j, 0);
			}
		}
	}

	cout << sol.size() << '\n';
	for (auto [c, x, y] : sol) {
		cout << c << ' ' << x+1 << ' ' << y+1 << '\n';
	}
}