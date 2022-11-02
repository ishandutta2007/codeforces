#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;

int sa[99], r[1009][1009], ans[99];
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
queue<pair<int, int> > q[99], tq[99];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, p; cin >> n >> m >> p;
	for (int i = 1; i <= p; i++)
		cin >> sa[i];
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '.') r[i][j] = 0;
			else if (s[j] == '#') r[i][j] = -1;
			else {
				r[i][j] = (int)(s[j] - '0');
				q[r[i][j]].push(make_pair(j, i));
			}
		}
	}
	bool f = true;
	while (f) {
		f = false;
		for (int t = 1; t <= p; t++) {
			int c = 0;
			while (c < sa[t] && q[t].size() > 0) {
				while (!q[t].empty()) {
					int x = q[t].front().first, y = q[t].front().second; q[t].pop();
					for (int i = 0; i < 4; i++) {
						int tx = x + dx[i], ty = y + dy[i];
						if (tx < 0 || tx >= m || ty < 0 || ty >= n || r[ty][tx] != 0) continue;
						tq[t].push(make_pair(tx, ty)); r[ty][tx] = t; f = true;
					}
				}
				while (!tq[t].empty()) {
					q[t].push(tq[t].front());
					tq[t].pop();
				}
				c++;
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (r[i][j] > 0)
				ans[r[i][j]]++;
	for (int i = 1; i <= p; i++)
		cout << ans[i] << " ";
	cout << '\n';
	return 0;
}