#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int nmax = 1010;

char a[nmax][nmax];
char valid1[nmax][nmax];
char valid2[nmax][nmax];

int main()
{

	//ifstream cin("f.in");
	//ofstream cout("f.out");
	//freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	memset(valid1, false, sizeof(valid1));
	memset(valid2, false, sizeof(valid2));

	int n, m;
	cin >> n >> m;
	int x1, y1, x2, y2;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 'S') {
				x1 = i, y1 = j;
			}
			if (a[i][j] == 'T') {
				x2 = i, y2 = j;
			}
		}
	}

	int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
	for (int k = 0; k < 4; ++k) {
		int x = x1, y = y1;
		valid1[x][y] = true;
		while (true) {
			x += dx[k], y += dy[k];
			if (x < 0 || x >= n || y < 0 || y >= m) {
				break;
			}
			if (a[x][y] == '*') {
				break;
			}
			valid1[x][y] = true;
		}
	}

	for (int k = 0; k < 4; ++k) {
		int x = x2, y = y2;
		valid2[x][y] = true;
		while (true) {
			x += dx[k], y += dy[k];
			if (x < 0 || x >= n || y < 0 || y >= m) {
				break;
			}
			if (a[x][y] == '*') {
				break;
			}
			valid2[x][y] = true;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (valid1[i][j] && valid2[i][j]) {
				cout << "YES\n";
				return 0;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (valid1[i][j]) {
				for (int k = 0; k < 4; ++k) {
					int x = i, y = j;
					while (true) {
						x += dx[k], y += dy[k];
						if (x < 0 || x >= n || y < 0 || y >= n) {
							break;
						}
						if (valid1[x][y] || a[x][y] == '*') {
							break;
						}
						if (valid2[x][y]) {
							cout << "YES\n";
							return 0;
						}
					}
				}
			}
		}
	}

	cout << "NO\n";

}