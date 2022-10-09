#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[105][105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int dx[] = {-1, 0, 1, 0};
	int dy[] = {0, 1, 0, -1};

	int p[4] = {0, 1, 2, 3};

	memset(a, '#', sizeof(a));

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		string s;
		cin >> s;
		for (int j=1; j<=m; j++) {
			a[i][j] = s[j-1];
		}
	}

	int xs=0, ys=0, xe=0, ye=0;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (a[i][j] == 'S') {
				xs = i;
				ys = j;
			} else if (a[i][j] == 'E') {
				xe = i;
				ye = j;
			}
		}
	}


	int ok = 0;
	string s;

	cin >> s;

	for (int rep=0; rep<24; rep++) {

		int x = xs;
		int y = ys;

		for (char l : s) {
			int dir = p[l - '0'];
			x += dx[dir];
			y += dy[dir];

			if (x == xe && y == ye) {
				ok++;
				break;
			}

			if (a[x][y] == '#') {
				break;
			}
		}

		next_permutation(p, p+4);
	}

	cout << ok << '\n';
}