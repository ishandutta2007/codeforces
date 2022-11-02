#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int p[29][29], dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 }, dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				p[i][j] = 0;
		int x = 0, y = 0, t = 2;
		for (int i = 0; i < 2 * (n + m - 2); i++) {
			bool f = true;
			for (int j = 0; j < 8; j++) {
				int tx = x + dx[j], ty = y + dy[j];
				if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
				if (p[ty][tx]) {
					f = false;
					break;
				}
			}
			if (f) p[y][x] = true;
			x += dx[t]; y += dy[t];
			if (x == m - 1 && t == 2) t = 4;
			else if (y == n - 1 && t == 4) t = 6;
			else if (x == 0 && t == 6) t = 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << p[i][j];
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}