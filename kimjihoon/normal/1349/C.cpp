#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <utility>
using namespace std;

string s[1009];
queue<pair<int, int> > q;
int p[1009][1009], dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, qr; cin >> n >> m >> qr;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				int tx = j + dx[k], ty = i + dy[k];
				if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
				if (s[ty][tx] == s[i][j]) {
					p[i][j] = 1;
					q.push(make_pair(j, i));
					break;
				}
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i], ty = y + dy[i];
			if (tx < 0 || tx >= m || ty < 0 || ty >= n || p[ty][tx]) continue;
			q.push(make_pair(tx, ty));
			p[ty][tx] = p[y][x] + 1;
		}
	}
	for (int i = 0; i < qr; i++) {
		int y, x; long long t; cin >> y >> x >> t; x--; y--;
		int tr = s[y][x] - '0';
		if (p[y][x] == 0 || 1LL * p[y][x] > t) cout << tr << '\n';
		else if ((t - 1LL * p[y][x]) % 2LL == 0LL) cout << 1 - tr << '\n';
		else cout << tr << '\n';
	}
	return 0;
}