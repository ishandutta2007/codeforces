#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
#include <queue>
using namespace std;

int n, m, k;
string a[1005];

int d[1005][1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;

	for (int i=1; i<=n; i++) {
		cin >> a[i];
		a[i] = string("*") + a[i] + string("*");
	}

	a[0] = string(m+2, '*');
	a[n+1] = string(m+2, '*');

	pair<int, int> pos0;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (a[i][j] == 'X') {
				pos0.first = i;
				pos0.second = j;
			}
		}
	}

	queue<pair<int, int>> q;
	q.push(pos0);
	memset(d, 255, sizeof(d));
	d[pos0.first][pos0.second] = 0;
	int s = 0;

	while (!q.empty()) {
		auto pos = q.front(); q.pop();
		for (int dx=-1; dx<=1; dx++) {
			for (int dy=-1; dy<=1; dy++) {
				if (abs(dx) + abs(dy) == 1) {

					int x = pos.first + dx;
					int y = pos.second + dy;

					if (a[x][y] != '*' && d[x][y] == -1) {
						s++;
						d[x][y] = d[pos.first][pos.second] + 1;
						q.push({x, y});
					}
				}
			}
		}
	}

	if (s == 0 || k % 2 == 1) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	{
		string red = "DLRU";
		int dx[4] = {1, 0, 0, -1};
		int dy[4] = {0, -1, 1, 0};
		string sol;

		int x = pos0.first;
		int y = pos0.second;

		for (int i=1; i<=k; i++) {
			for (int dir=0; dir<4; dir++) {
				int xc = x + dx[dir];
				int yc = y + dy[dir];

				if (a[xc][yc] != '*' && d[xc][yc] <= k-i) {
					sol += red[dir];
					x = xc;
					y = yc;
					break;
				}
			}
		}

		cout << sol;

	}
	
}