// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
string s[1005];

const int HOR = 0;
const int VER = 2;

char col(int i, int j, int dir) {
	return dir + (dir == HOR ? i : j) % 2;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> s[i];
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (s[i][j] == 'w') {
				// ako ima desno, desno
				if (j+2 < m && s[i][j+1] == 'b' && s[i][j+2] == 'w') {
					s[i][j] = s[i][j+1] = s[i][j+2] = col(i, j+1, HOR);
				} else if (i+2 < n && s[i+1][j] == 'b' && s[i+2][j] == 'w') {
					s[i][j] = s[i+1][j] = s[i+2][j] = col(i+1, j, VER);
				} else {
					cout << "NO\n";
					return 0;
				}
			} else if (s[i][j] == 'b') {
				cout << "NO\n";
				return 0;
			}
		}
	}

	cout << "YES\n";
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cout << (char)(s[i][j] == '.' ? '.' : s[i][j] + 'a');
		}
		cout << '\n';
	}
}