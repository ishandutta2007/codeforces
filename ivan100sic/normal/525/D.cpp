#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	int x, y;
};

int n, m;
string s[2005];
queue<pt> q;

const int dx8[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const int dy8[8] = {1, 0, -1, -1, -1, 0, 1, 1};

bool ok(int mask) {
	if ((mask & 0b00001110) == 0b00001110)
		return true;
	if ((mask & 0b00111000) == 0b00111000)
		return true;
	if ((mask & 0b11100000) == 0b11100000)
		return true;
	if ((mask & 0b10000011) == 0b10000011)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> s[i];

	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			q.push({i, j});

	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		if (s[x][y] == '.')
			continue;

		int mask = 0;
		for (int dir=0; dir<8; dir++) {
			int xx = x + dx8[dir];
			int yy = y + dy8[dir];
			if (0 <= xx && xx < n && 0 <= yy && yy < m) {
				if (s[xx][yy] == '.') {
					mask |= 1 << dir;
				}
			}
		}

		if (ok(mask)) {
			s[x][y] = '.';
			for (int dir=0; dir<8; dir++) {
				int xx = x + dx8[dir];
				int yy = y + dy8[dir];
				if (0 <= xx && xx < n && 0 <= yy && yy < m) {
					q.push({xx, yy});
				}
			}
		}
	}

	for (int i=0; i<n; i++)
		cout << s[i] << '\n';
}