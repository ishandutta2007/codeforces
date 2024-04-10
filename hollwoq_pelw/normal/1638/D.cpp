#include <bits/stdc++.h>
using namespace std;

void solve_case();

signed main() {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);

	// int test; for (cin >> test; test --; )
	{
		solve_case();
	}
}

const int N = 1005;

int n, m, a[N][N], vis[N][N];
queue<pair<int, int>> q;

vector<tuple<int, int, int>> res;

inline int check(int x, int y) {
	if (!(1 <= x && x < n && 1 <= y && y < m))
		return -1;
	int v = max({
		a[x][y],
		a[x][y + 1],
		a[x + 1][y],
		a[x + 1][y + 1]
	});
	if (a[x][y] > 0 && a[x][y] < v) return -1;
	if (a[x][y + 1] > 0 && a[x][y + 1] < v) return -1;
	if (a[x + 1][y] > 0 && a[x + 1][y] < v) return -1;
	if (a[x + 1][y + 1] > 0 && a[x + 1][y + 1] < v) return -1;
	return v;
}

inline void paint(int x, int y, int c) {
	if (vis[x][y] < 0) {
		vis[x][y] = c;
		if (c) res.emplace_back(x, y, c);
		q.emplace(x, y);
	}
	a[x][y] = a[x + 1][y] = a[x][y + 1] = a[x + 1][y + 1] = 0;
}

void solve_case() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	memset(vis, -1, sizeof vis);

	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++) {
			int c = check(i, j);
			if (c >= 0)
				paint(i, j, c);
		}

	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();

		for (int nx = x - 1; nx <= x + 1; nx++)
			for (int ny = y - 1; ny <= y + 1; ny++) {
				int c = check(nx, ny);
				if (c >= 0)
					paint(nx, ny, c);
			}
	}

	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
			if (vis[i][j] < 0)
				return cout << "-1\n", (void) 0;
	cout << res.size() << '\n';
	reverse(res.begin(), res.end());
	for (auto [x, y, c] : res)
		cout << x << ' ' << y << ' ' << c << '\n';
}