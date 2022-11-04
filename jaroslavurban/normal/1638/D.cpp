#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct Q {
	int x, y, c;
};

void ProGamerMove() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> f(n, vector<int>(m));
	vector<vector<int>> done(n, vector<int>(m));
	auto check = [&](int i, int j) {
		if (i < 0 || i >= n - 1 || j < 0 || j >= m - 1 || done[i][j]) return 0;
		int c = 0, pos = true;
		for (int di = 0; di < 2; ++di)
			for (int dj = 0; dj < 2; ++dj) {
				if (c != f[i + di][j + dj] && f[i + di][j + dj] && c) pos = false;
				c = max(c, f[i + di][j + dj]);
			}
		return pos * c;
	};
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> f[i][j];
	queue<Q> q;
	for (int c, i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (c = check(i, j)) {
				done[i][j] = true;
				q.push({i, j, c});
			}
	vector<Q> res;
	while (q.size()) {
		auto [i, j, c] = q.front(); q.pop();
		res.push_back({i, j, c});
		for (int di = 0; di < 2; ++di)
			for (int dj = 0; dj < 2; ++dj)
				f[i + di][j + dj] = 0;
		for (int c, di = -1; di < 2; ++di)
			for (int dj = -1; dj < 2; ++dj)
				if (c = check(i + di, j + dj)) {
					done[i + di][j + dj] = true;
					q.push({i + di, j + dj, c});
				}
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (f[i][j]) {
				cout << "-1\n";
				return;
			}
	cout << res.size() << "\n";
	reverse(res.begin(), res.end());
	for (auto [i, j, c] : res) cout << i + 1 << " " << j + 1 << " " << c << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
//	cin >> tc;
	while (tc--) ProGamerMove();
}