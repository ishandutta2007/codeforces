#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, k;
string a[505], b[505];
bool v[505][505];

int dfs(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)
		return 0;
	if (v[x][y])
		return 0;
	if (a[x][y] == '#')
		return 0;
	v[x][y] = 1;
	int z = 0;
	z += dfs(x+1, y);
	z += dfs(x-1, y);
	z += dfs(x, y+1);
	z += dfs(x, y-1);
	if (z == 0 && k > 0) {
		b[x][y] = 'X';
		k--;
	} else {
		z += 1;
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	int x = 0, y = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (a[i][j] == '.') {
				x = i;
				y = j;
			}
		}
	}
	cerr << "x = " << x << " y = " << y << '\n';
	dfs(x, y);
	for (int i=0; i<n; i++)
		cout << b[i] << '\n';
}