#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string s[1005];
bool v[1005][1005];
int n, m;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

const int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy8[8] = {1, 1, 0, -1, -1, -1, 0, 1};

struct pt {
	int x, y;
};

vector<vector<pt>> sol;
int sz[1005][1005];

vector<pt> dfs(int x, int y, bool root = false) {
	v[x][y] = true;
	vector<pt> q = {{x, y}};
	for (int d=0; d<4; d++) {
		int xx = x + dx[d];
		int yy = y + dy[d];
		if (xx < 0 || xx >= n || yy < 0 || yy >= m || s[xx][yy] == '#'
			 || v[xx][yy])
			continue;
		auto v = dfs(xx, yy);
		q.insert(q.end(), v.begin(), v.end());
	}
	if (q.size() >= 2) {
		sol.push_back(q);
		q = {};
	}
	return q;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> s[i];

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (!v[i][j] && s[i][j] == '.')
				dfs(i, j, true);
		}
	}

	// nacrtaj
	for (auto v : sol) {
		set<char> ss;
		for (auto [x, y] : v) {
			sz[x][y] = v.size();
			for (int d=0; d<8; d++) {
				int xx = x + dx8[d];
				int yy = y + dy8[d];
				if (xx < 0 || xx >= n || yy < 0 || yy >= m || s[xx][yy] == '#')
					continue;
				ss.insert(s[xx][yy]);
			}
		}
		for (char c='0'; c<='9'; c++)
			if (!ss.count(c)) {
				for (auto [x, y] : v)
					s[x][y] = c;
				break;
			}
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (s[i][j] == '.') {
				bool ok = false;
				for (int d=0; d<4; d++) {
					int xx = i + dx[d];
					int yy = j + dy[d];
					if (xx < 0 || xx >= n || yy < 0 || yy >= m || s[xx][yy] == '#')
						continue;
					s[i][j] = s[xx][yy];
					ok = true;
					break;
				}
				if (!ok) {
					cout << "-1\n";
					return 0;
				}
			}
		}
	}

	for (int i=0; i<n; i++)
		cout << s[i] << '\n';
}