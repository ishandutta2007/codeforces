#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m;
vector<vector<bool > > vs;
vector<string> s;

bool dfs(int x, int y)
{
	vs[y][x] = true;
	if (x == m - 1 && y == n - 1) return true;
	for (int i = 0; i < 2; i++) {
		int tx = x, ty = y;
		if (i == 0) tx++;
		else ty++;
		if (tx >= m || ty >= n || vs[ty][tx] || s[ty][tx] == '#') continue;
		if (dfs(tx, ty)) {
			if (x != 0 || y != 0) s[y][x] = '#';
			return true;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	vs = vector<vector<bool> >(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) {
		string ts;
		cin >> ts;
		s.push_back(ts);
	}
	int ans = 0;
	while (dfs(0, 0)) {
		ans++;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				vs[i][j] = false;
	}
	cout << ans << '\n';
	return 0;
}