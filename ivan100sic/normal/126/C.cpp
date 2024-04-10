#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef int mat[2005][2005];

mat a, u, d, l, r; // na koju stranu se propagira
int n;

void prop(int i, int j) {
	u[i - 1][j] ^= u[i][j];
	d[i + 1][j] ^= d[i][j];
	l[i][j - 1] ^= l[i][j];
	r[i][j + 1] ^= r[i][j];
}

int val(int i, int j) {
	return a[i][j] ^ u[i][j] ^ d[i][j] ^ l[i][j] ^ r[i][j];
}

vector<pair<int, int>> e[2005];

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= n; j++) {
			a[i][j] = s[j - 1] - '0';
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int d = min(abs(i - 1) + abs(j - n), abs(i - n) + abs(j - 1));
			e[d].push_back({ i, j });
		}
	}

	int sol = 0;

	for (int i = 0; i < n - 1; i++) {
		for (auto p : e[i]) {
			int x = p.first;
			int y = p.second;
			a[x][y] = val(x, y);
			prop(x, y);
			if (a[x][y] == 1) {
				if (x > y) {
					u[x - 1][y] ^= 1;
					r[x][y + 1] ^= 1;
				}
				else {
					d[x + 1][y] ^= 1;
					l[x][y - 1] ^= 1;
				}
				sol++;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int z = val(i, i);
		sol += z;
	}

	cout << sol << '\n';
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}