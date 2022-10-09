#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	int x, y;
};

int n, m, e;
string s[2005];

bool un(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const string ka = "<^>v";
const string od = ">v<^";

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	queue<pt> q;

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> s[i];
		for (int j=0; j<m; j++) {
			if (s[i][j] == '.') {
				e++;
				q.push({i, j});
			}
		}
	}

	while (q.size()) {
		auto [x, y] = q.front(); q.pop();

		if (s[x][y] != '.')
			continue;

		int xx=0, yy=0, c=0, dd=0;
		for (int d=0; d<4; d++) {
			int xxx = x + dx[d];
			int yyy = y + dy[d];
			if (un(xxx, yyy) && s[xxx][yyy] == '.') {
				xx = xxx;
				yy = yyy;
				c++;
				dd = d;
			}
		}

		if (c == 1) {
			e -= 2;
			s[x][y] = ka[dd];
			s[xx][yy] = od[dd];
			for (int d=0; d<4; d++) {
				int xxx = x + dx[d];
				int yyy = y + dy[d];
				if (un(xxx, yyy) && s[xxx][yyy] == '.') {
					q.push({xxx, yyy});
				}

				xxx = xx + dx[d];
				yyy = yy + dy[d];
				if (un(xxx, yyy) && s[xxx][yyy] == '.') {
					q.push({xxx, yyy});
				}
			}
		}
	}

	if (e) {
		cout << "Not unique\n";
		return 0;
	}

	for (int i=0; i<n; i++)
		cout << s[i] << '\n';
}