#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pos {
	int x : 10, y : 10, z : 10;
};

string s, t;
int n, m;

int d[205][205][805];
pos p[205][205][805];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s >> t;
	n = s.size(), m = t.size();

	memset(d, 255, sizeof d);
	d[0][0][0] = 0;
	queue<pos> q;
	q.push({0, 0, 0});

	pos solp;

	while (q.size()) {
		auto [x, y, z] = q.front(); q.pop();
		// otv?
		int done = 0;
		for (char c : {'(', ')'}) {
			int xx = x, yy = y, zz = z;
			if (xx < n && s[xx] == c)
				xx++;
			if (yy < m && t[yy] == c)
				yy++;
			if (c == '(')
				zz++;
			else
				zz--;
			if (zz < 0)
				continue;
			if (d[xx][yy][zz] == -1) {
				d[xx][yy][zz] = d[x][y][z] + 1;
				p[xx][yy][zz] = {x, y, z};
				q.push({xx, yy, zz});
				if (xx == n && yy == m && zz == 0) {
					solp = {xx, yy, zz};
					done = 1;
					break;
				}
			}
		}
		if (done)
			break;
	}

	string sol;
	while (1) {
		auto [x, y, z] = solp;
		if (x + y + z == 0)
			break;
		if (p[x][y][z].z < z)
			sol += '(';
		else
			sol += ')';
		solp = p[x][y][z];
	}
	reverse(sol.begin(), sol.end());
	cout << sol << '\n';
}