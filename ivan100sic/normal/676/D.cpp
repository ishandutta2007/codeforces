#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, r0, c0, r1, c1;
string a[1005];

int d[1005][1005][4];

struct entry {
	int x, y, r;
};

// right, down, left, up
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool hasdoor(char x, int dir) {
	if (x == '+')
		return true;
	if (x == '-')
		return dir == 0 || dir == 2;
	if (x == '|')
		return dir == 1 || dir == 3;
	if (x == '^')
		return dir == 3;
	if (x == '>')
		return dir == 0;
	if (x == '<')
		return dir == 2;
	if (x == 'v')
		return dir == 1;
	if (x == 'L')
		return dir != 2;
	if (x == 'R')
		return dir != 0;
	if (x == 'U')
		return dir != 3;
	if (x == 'D')
		return dir != 1;
	return false;
}

bool can_walk(int x0, int y0, int dir, int r) {
	int x1 = x0 + dx[dir];
	int y1 = y0 + dy[dir];
	if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m)
		return false;
	return hasdoor(a[x0][y0], (dir+3*r)&3) && hasdoor(a[x1][y1], (dir+3*r+2)&3);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	memset(d, 255, sizeof(d));

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];
	cin >> r0 >> c0 >> r1 >> c1;
	r0--, c0--, r1--, c1--;

	queue<entry> q;
	q.push({r0, c0, 0});
	d[r0][c0][0] = 0;

	while (q.size()) {
		auto [x, y, r] = q.front(); q.pop();

		// samo rotiraj
		if (d[x][y][(r+1)&3] == -1) {
			d[x][y][(r+1)&3] = d[x][y][r] + 1;
			q.push({x, y, (r+1) & 3});
		}

		for (int dir=0; dir<4; dir++) {
			if (can_walk(x, y, dir, r)) {
				int x2 = x + dx[dir];
				int y2 = y + dy[dir];
				if (d[x2][y2][r] == -1) {
					d[x2][y2][r] = d[x][y][r] + 1;
					q.push({x2, y2, r});
				}
			}
		}
	}
	int sol = 123123123;
	for (int i=0; i<4; i++)
		sol = min(sol, d[r1][c1][i] == -1 ? 123123123 : d[r1][c1][i]);
	if (sol == 123123123)
		sol = -1;
	cout << sol << '\n';
}