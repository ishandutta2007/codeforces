// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, k;
string s[1005];
int sol[1005][1005];

template<class T, class V>
void dfs(int x, int y, V& v, T& t) {
	s[x][y] = 'v';
	t.insert({x, y});
	for (int d=0; d<4; d++) {
		int xx = x + dx[d];
		int yy = y + dy[d];
		if (s[xx][yy] == '*') {
			v.insert({x, y, xx, yy});
		} else if (s[xx][yy] == '.') {
			dfs(xx, yy, v, t);
		}
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m >> k;

	for (int i=0; i<n; i++) {
		cin >> s[i];
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (s[i][j] == '.') {
				set<pair<int, int>> t;
				set<array<int, 4>> v;
				dfs(i, j, v, t);
				for (auto [x, y] : t) {
					sol[x][y] = v.size();
				}
			}
		}
	}

	while (k--) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		cout << sol[x][y] << "\n";
	}
}