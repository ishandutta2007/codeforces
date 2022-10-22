#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef _MSC_VER
	freopen("e.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	int m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(n));
	vector<int> q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
			q.push_back(i * n + j);
		}
	}
	sort(q.begin(), q.end(), [&](int x, int y) { return a[x / n][x % n] > a[y / n][y % n]; });
	vector<vector<int>> r(n, vector<int>(n, -1));
	int min_x = 1e8;
	int max_x = -1e8;
	int min_y = 1e8;
	int max_y = -1e8;
	for (int at : q) {
		int x = at / n;
		int y = at % n;
		int x0 = x + y + 1;
		int y0 = x - y + n + 1;
		int x1 = x0 - m;
		int y1 = y0 - m;
		int x2 = x0 + m;
		int y2 = y0 + m;
		if (min_x < x1 || min_y < y1 || max_x > x2 || max_y > y2) {
			r[x][y] = 1;
		} else {
			r[x][y] = 0;
			min_x = min(min_x, x0);
			max_x = max(max_x, x0);
			min_y = min(min_y, y0);
			max_y = max(max_y, y0);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%c", r[i][j] ? 'G' : 'M');
		}
		printf("\n");
	}
	return 0;
}