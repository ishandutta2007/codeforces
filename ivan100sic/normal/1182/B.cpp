#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
string a[505];

void no() {
	cout << "NO\n";
	exit(0);
}

bool zvezda(int x, int y) {
	if (a[x][y] != '*') return false;
	if (a[x-1][y] != '*') return false;
	if (a[x+1][y] != '*') return false;
	if (a[x][y-1] != '*') return false;
	if (a[x][y+1] != '*') return false;

	if (a[x-1][y-1] != '.') return false;
	if (a[x+1][y-1] != '.') return false;
	if (a[x-1][y+1] != '.') return false;
	if (a[x+1][y+1] != '.') return false;

	return true;
}

bool unutra(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];

	bool found = false;

	for (int i=1; i<n-1 && !found; i++) {
		for (int j=1; j<m-1 && !found; j++) {
			if (zvezda(i, j)) {

				found = true;
				a[i][j] = '.';

				for (int d=0; d<4; d++) {
					int dx = ::dx[d];
					int dy = ::dy[d];
					int x = i + dx;
					int y = j + dy;
					while (unutra(x, y) && a[x][y] == '*') {
						a[x][y] = '.';
						x += dx;
						y += dy;
					}
				}
			}
		}
	}

	if (!found)
		no();
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (a[i][j] == '*')
				no();
	cout << "YES\n";

}