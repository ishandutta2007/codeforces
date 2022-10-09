// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
string a[1005];
int id[1005][1005], cid;
int sz[1000005];

void dfs(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)
		return;
	if (a[x][y] == '*' || id[x][y])
		return;

	id[x][y] = cid;
	sz[cid]++;

	dfs(x, y+1);
	dfs(x, y-1);
	dfs(x-1, y);
	dfs(x+1, y);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (a[i][j] == '.') {
				cid++;
				dfs(i, j);
			}
		}
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (a[i][j] == '.') {
				cout << '.';
			} else {
				set<int> s;
				for (int dx=-1; dx<=1; dx++) {
					for (int dy=-1; dy<=1; dy++) {
						if (abs(dx) + abs(dy) == 1) {
							int xx = i + dx;
							int yy = j + dy;
							if (xx >= 0 && yy >= 0 && xx < n && yy < m) {
								s.insert(id[xx][yy]);
							}
						}
					}
				}

				int u = 0;
				for (int i : s) {
					u += sz[i];
				}
				u += 1;

				cout << u % 10;
			}
		}
		cout << '\n';
	}
}