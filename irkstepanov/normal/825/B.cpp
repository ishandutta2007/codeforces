
#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int n = 10;
char m[n][n];

int dx[4] = {0, 1, 1, 1};
int dy[4] = {1, 0, 1, -1};

bool check() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (m[i][j] != 'X') {
				continue;
			}
			for (int k = 0; k < 4; ++k) {
				int x = i, y = j;
				bool ok = true;
				for (int t = 0; t < 4; ++t) {
					x += dx[k], y += dy[k];
					if (x < 0 || x >= n || y < 0 || y >= n || m[x][y] != 'X') {
						ok = false;
						break;
					}
				}
				if (ok) {
					return true;
				}
			}
		}
	}
	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> m[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (m[i][j] == '.') {
				m[i][j] = 'X';
				if (check()) {
					cout << "YES\n";
					return 0;
				}
				m[i][j] = '.';
			}
		}
	}

	cout << "NO\n";
		
}