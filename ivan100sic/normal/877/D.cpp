#include <bits/stdc++.h>
using namespace std;

int n, m, k;
string a[1005];
int d[1005][1005];
set<int> unvis_x[1005], unvis_y[1005];

queue<pair<int, int>> q;

int z[1005][1005];

int zauz(int x1, int y1, int x2, int y2) {
	if (y1 > y2) {
		swap(y1, y2);
	}
	if (x1 > x2) {
		swap(x1, x2);
	}

	x1--;
	y1--;
	return z[x2][y2] + z[x1][y1] - z[x2][y1] - z[x1][y2];
}

int find_larger(set<int>& s, int x) {
	auto it = s.upper_bound(x);
	if (it == s.end()) {
		return -1;
	}
	return *it;
}

int find_smaller(set<int>& s, int x) {
	auto it = s.lower_bound(x);
	if (it == s.begin()) {
		return -1;
	}
	return *--it;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		a[i] = string(" ") + a[i];
	}
	memset(d, 255, sizeof(d));

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	q.push({x1, y1});
	d[x1][y1] = 0;
	unvis_x[x1].erase(y1);
	unvis_y[y1].erase(x1);

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			unvis_x[i].insert(j);
			unvis_y[j].insert(i);

			z[i][j] = a[i][j] == '#' ? 1 : 0;
			z[i][j] += z[i-1][j] + z[i][j-1] - z[i-1][j-1];
		}
	}

	while (!q.empty()) {
		auto p = q.front(); q.pop();
		int x = p.first;
		int y = p.second;

		while (1) {
			int yy = find_larger(unvis_x[x], y);
			if (yy == -1 || yy > y + k) {
				break;
			}
			if (zauz(x, y, x, yy)) {
				break;
			}

			d[x][yy] = d[x][y] + 1;
			q.push({x, yy});
			unvis_x[x].erase(yy);
			unvis_y[yy].erase(x);
		}
		
		while (1) {
			int yy = find_smaller(unvis_x[x], y);
			if (yy == -1 || yy < y - k) {
				break;
			}
			if (zauz(x, y, x, yy)) {
				break;
			}

			d[x][yy] = d[x][y] + 1;
			q.push({x, yy});
			unvis_x[x].erase(yy);
			unvis_y[yy].erase(x);
		}

		while (1) {
			int xx = find_larger(unvis_y[y], x);
			if (xx == -1 || xx > x + k) {
				break;
			}
			if (zauz(x, y, xx, y)) {
				break;
			}

			d[xx][y] = d[x][y] + 1;
			q.push({xx, y});
			unvis_x[xx].erase(y);
			unvis_y[y].erase(xx);
		}
	
		while (1) {
			int xx = find_smaller(unvis_y[y], x);
			if (xx == -1 || xx < x - k) {
				break;
			}
			if (zauz(x, y, xx, y)) {
				break;
			}

			d[xx][y] = d[x][y] + 1;
			q.push({xx, y});
			unvis_x[xx].erase(y);
			unvis_y[y].erase(xx);
		}
	}

	cout << d[x2][y2];

}