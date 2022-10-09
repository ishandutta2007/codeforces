#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string a, b, c;
int n, m, k;

int f[105][26];

struct ind {
	int x, y, z;
};

int d[105][105][105];
ind p[105][105][105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> a >> b >> c;
	n = a.size();
	m = b.size();
	k = c.size();

	for (int i=0; i<=k; i++) {
		string s = c.substr(0, i);
		for (char x='A'; x<='Z'; x++) {
			string t = s + x;
			for (int l=t.size(); l>=0; l--) {
				if (t.substr(t.size() - l) == c.substr(0, l)) {
					f[i][x-'A'] = l;
					break;
				}
			}
		}
	}

	memset(d, 0xff, sizeof d);
	d[0][0][0] = 0;

	for (int i=0; i<=n; i++) {
		for (int j=0; j<=m; j++) {
			for (int y=0; y<k; y++) {
				if (i < n && d[i][j][y] > d[i+1][j][y]) {
					d[i+1][j][y] = d[i][j][y];
					p[i+1][j][y] = {i, j, y};
				}

				if (j < m && d[i][j][y] > d[i][j+1][y]) {
					d[i][j+1][y] = d[i][j][y];
					p[i][j+1][y] = {i, j, y};
				}

				if (i < n && j < m && a[i] == b[j]) {
					int y2 = f[y][a[i] - 'A'];
					if (y2 == k)
						continue;
					if (d[i+1][j+1][y2] < d[i][j][y] + 1) {
						d[i+1][j+1][y2] = d[i][j][y] + 1;
						p[i+1][j+1][y2] = {i, j, y};
					}
				}
			}
		}
	}

	int yh = 0;
	for (int y=0; y<k; y++)
		if (d[n][m][y] > d[n][m][yh])
			yh = y;

	if (d[n][m][yh] == 0) {
		cout << "0\n";
		return 0;
	}

	string sol;
	ind r = {n, m, yh};
	while (r.x | r.y | r.z) {
		ind t = p[r.x][r.y][r.z];
		if (t.x != r.x && t.y != r.y)
			sol += a[t.x];
		r = t;
	}
	reverse(sol.begin(), sol.end());
	cout << sol << '\n';
}