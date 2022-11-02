#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, a[1009][1009];
int dx[8] = { 1, 1, 1, 0, -1, -1, -1, 0}, dy[8] = { 1, 0, -1, -1, -1, 0, 1, 1 };
bool vs[1009][1009];
queue<pair<int, int> > q;
vector<pair<pair<int, int>, int> > ans;

int chk(int y, int x)
{
	if (x < 1 || y < 1 || x + 1 > m || y + 1 > n) return 0;
	int p = 0;
	for (int i = y; i <= y + 1; i++)
		for (int j = x; j <= x + 1; j++) {
			if (!p) p = a[i][j];
			else if (a[i][j] && p != a[i][j]) return 0;
		}
	if (p) return p;
	else return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) 
			cin >> a[i][j];
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
			if (chk(i, j)) {
				vs[i][j] = true;
				q.push(make_pair(i, j));
			}
	while (!q.empty()) {
		int y = q.front().first, x = q.front().second; q.pop();
		ans.push_back(make_pair(make_pair(y, x), chk(y, x)));
		a[y][x] = a[y + 1][x] = a[y][x + 1] = a[y + 1][x + 1] = 0;
		for (int i = 0; i < 8; i++) {
			int tx = x + dx[i], ty = y + dy[i];
			if (!vs[ty][tx] && chk(ty, tx)) {
				vs[ty][tx] = true;
				q.push(make_pair(ty, tx));
			}
		}
	}
	if (ans.size() != (n - 1) * (m - 1)) {
		cout << -1 << '\n';
		return 0;
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << '\n';
	return 0;
}