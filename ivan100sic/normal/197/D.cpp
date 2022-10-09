#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
string a[1505];
const int dxx[4] = {0, 1, 0, -1};
const int dyy[4] = {1, 0, -1, 0};

typedef complex<int> ci;

ci d[1505][1505];
bool vis[1505][1505];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	int x0=0, y0=0;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		for (int j=0; j<m; j++)
			if (a[i][j] == 'S')
				x0 = i, y0 = j;
	}

	basic_string<pair<int, int>> qu;
	qu += {x0, y0};
	size_t qs = 0;
	while (qs != qu.size()) {
		auto [x, y] = qu[qs++];
		for (int dir=0; dir<4; dir++) {
			int dx = dxx[dir], dy = dyy[dir];
			int p = (x+dx+n)%n;
			int q = (y+dy+m)%m;

			if (a[p][q] == '#')
				continue;

			ci t = d[x][y] + ci(dx, dy);
			if (vis[p][q]) {
				if (t != d[p][q]) {
					cout << "Yes\n";
					return 0;
				}
			} else {
				d[p][q] = t;
				vis[p][q] = 1;
				qu += {p, q};
			}
		}
	}

	cout << "No\n";
}