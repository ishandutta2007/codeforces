#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int n, m;
vector<string> a;
vector<vector<bool>> b, c;

bool inside(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void doit(vector<vector<bool>>& b, int x0, int y0) {
	int dx[] = {-1, 0, 1, 0};
	int dy[] = {0, 1, 0, -1};

	for (int d=0; d<4; d++) {
		int x = x0;
		int y = y0;
		while (inside(x, y) && a[x][y] != '*') {
			b[x][y] = true;
			x += dx[d];
			y += dy[d];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	int xs, ys, xt, yt;
	a.resize(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
		for (int j=0; j<m; j++) {
			if (a[i][j] == 'S') {
				xs = i;
				ys = j;
			} else if (a[i][j] == 'T') {
				xt = i;
				yt = j;
			}
		}
	}

	b.resize(n, vector<bool>(m, false));
	c = b;

	doit(b, xs, ys);
	doit(c, xt, yt);

	/*
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cerr << b[i][j] ? 1 : 0;
		}
		cerr << '\n';
	}
	*/


	// redovi
	for (int i=0; i<n; i++) {
		int x = 0;
		for (int j=0; j<m; j++) {
			if (a[i][j] == '*') {
				x = 0;
			}
			if (b[i][j]) {
				x |= 1;
			}
			if (c[i][j]) {
				x |= 2;
			}
			if (x == 3) {
				cout << "YES";
				return 0;
			}
		}
	}

	// kolone
	for (int j=0; j<m; j++) {
		int x = 0;
		for (int i=0; i<n; i++) {
			if (a[i][j] == '*') {
				x = 0;
			}
			if (b[i][j]) {
				x |= 1;
			}
			if (c[i][j]) {
				x |= 2;
			}
			if (x == 3) {
				cout << "YES";
				return 0;
			}
		}
	}

	cout << "NO";


}