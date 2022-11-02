#include <iostream>
#include <algorithm>
using namespace std;

int c[509][509][4], d[19][509][509], dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 }, inf = 1000000000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m - 1; j++) {
			int t; cin >> t;
			c[i][j][0] = c[i][j + 1][2] = t;
		}
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m; j++) {
			int t; cin >> t;
			c[i][j][1] = c[i + 1][j][3] = t;
		}
	if (k & 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << -1 << " ";
			cout << '\n';
		}
		return 0;
	}
	k /= 2;
	for (int di = 1; di <= k; di++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				d[di][i][j] = inf;
				for (int pi = 0; pi < 4; pi++) {
					int tx = j + dx[pi], ty = i + dy[pi];
					if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
					d[di][i][j] = min(d[di][i][j], d[di - 1][ty][tx] + c[i][j][pi]);
				}
			}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << d[k][i][j] * 2 << " ";
		cout << '\n';
	}
	return 0;
}