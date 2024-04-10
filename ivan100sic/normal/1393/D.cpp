// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int d[2005][2005];
int n, m;
string a[2005];

pair<int, int> dd[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool u(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	vector<pair<int, int>> q;

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			for (auto [dx, dy] : dd) {
				int ii = i + dx, jj = j + dy;
				if (!u(ii, jj) || a[i][j] != a[ii][jj]) {
					d[i][j] = 1;
					q.emplace_back(i, j);
				}
			}
		}
	}

	size_t qs = 0;
	while (qs != q.size()) {
		auto [x, y] = q[qs++];
		for (auto [dx, dy] : dd) {
			int ii = x + dx, jj = y + dy;
			if (u(ii, jj) && d[ii][jj] == 0) {
				d[ii][jj] = d[x][y] + 1;
				q.emplace_back(ii, jj);
			}
		}
	}

	ll sum = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			sum += d[i][j];
		}
	}

	cout << sum << '\n';
}