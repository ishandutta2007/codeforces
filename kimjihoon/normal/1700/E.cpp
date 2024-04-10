#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int> > v, c;
vector<pair<int, int> > pv, tpv;
int n, m;
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

bool pchk(int x, int y)
{
	if (v[y][x] == 1) return true;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
		if (v[ty][tx] < v[y][x]) return true;
	}
	return false;
}

bool chk(int x0, int y0, int x1, int y1)
{
	swap(v[y0][x0], v[y1][x1]);
	if (!pchk(x0, y0) || !pchk(x1, y1)) {
		swap(v[y0][x0], v[y1][x1]);
		return false;
	}
	for (int i = 0; i < 4; i++) {
		int tx = x0 + dx[i], ty = y0 + dy[i];
		if (0 <= tx && tx < m && 0 <= ty && ty < n && !pchk(tx, ty)) {
			swap(v[y0][x0], v[y1][x1]);
			return false;
		}
		tx = x1 + dx[i]; ty = y1 + dy[i];
		if (0 <= tx && tx < m && 0 <= ty && ty < n && !pchk(tx, ty)) {
			swap(v[y0][x0], v[y1][x1]);
			return false;
		}
	}
	for (int i = 0; i < pv.size(); i++)
		if (!pchk(pv[i].first, pv[i].second)) {
			swap(v[y0][x0], v[y1][x1]);
			return false;
		}
	swap(v[y0][x0], v[y1][x1]);
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		v.push_back(vector<int>());
		c.push_back(vector<int>());
		for (int j = 0; j < m; j++) {
			int t; cin >> t;
			v.back().push_back(t);
			c.back().push_back(0);
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			bool f = false;
			if (v[i][j] == 1) continue;
			for (int pi = 0; pi < 4; pi++) {
				int tx = j + dx[pi], ty = i + dy[pi];
				if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
				if (v[ty][tx] < v[i][j]) {
					f = true;
					break;
				}
			}
			if (!f) pv.push_back(make_pair(j, i));
		}
	if (pv.size() == 0) {
		cout << 0 << '\n';
		return 0;
	}
	if (pv.size() > 5) {
		cout << 2 << '\n';
		return 0;
	}
	for (int i = 0; i < pv.size(); i++) {
		int x = pv[i].first, y = pv[i].second;
		c[y][x]++;
		for (int pi = 0; pi < 4; pi++) {
			int tx = x + dx[pi], ty = y + dy[pi];
			if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
			c[ty][tx]++;
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (c[i][j])
				tpv.push_back(make_pair(j, i));
	int ans = 0;
	for (int i = 0; i < tpv.size(); i++)
		for (int j = i + 1; j < tpv.size(); j++)
			if (chk(tpv[i].first, tpv[i].second, tpv[j].first, tpv[j].second))
				ans++;
	for (int pi = 0; pi < tpv.size(); pi++) {
		int x = tpv[pi].first, y = tpv[pi].second;
		if (c[y][x] == pv.size()) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (!c[i][j] && chk(j, i, x, y))
						ans++;
		}
	}
	if (ans) cout << 1 << " " << ans << '\n';
	else cout << 2 << '\n';
	return 0;
}