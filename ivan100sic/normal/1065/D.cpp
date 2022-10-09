#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;

vector<pair<int, int>> moves_knight(int x, int y) {
	vector<pair<int, int>> v;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (abs(x-i) + abs(y-j) == 3 && abs(x-i)*abs(y-j) == 2)
				v.push_back({i, j});
		}
	}
	return v;
}

vector<pair<int, int>> moves_bishop(int x, int y) {
	vector<pair<int, int>> v;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (abs(x-i) == abs(y-j))
				v.push_back({i, j});
		}
	}
	return v;
}

vector<pair<int, int>> moves_rook(int x, int y) {
	vector<pair<int, int>> v;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (x == i || y == j)
				v.push_back({i, j});
		}
	}
	return v;
}

vector<pair<int, int>> moves(int x, int y, int c) {
	if (c == 0)
		return moves_rook(x, y);
	if (c == 1)
		return moves_bishop(x, y);
	if (c == 2)
		return moves_knight(x, y);
	return {};
}

//

int x[100], y[100];

int state(int x, int y, int c) {
	return c*n*n + x*n + y;
}

struct resenje {
	ll len, prom;

	resenje(ll len = 123123123, ll prom = 123123123) :
		len(len), prom(prom) {}

	bool operator< (const resenje& o) const {
		if (len != o.len)
			return len < o.len;
		return prom < o.prom;
	}

	resenje operator+ (const resenje& o) const {
		return {len + o.len, prom + o.prom};
	}
};

resenje d[300][300];
resenje g[3][100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			int z;
			cin >> z;
			z--;
			x[z] = i;
			y[z] = j;
		}
	}

	for (int c=0; c<3; c++) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {

				int u = state(i, j, c);
				auto p = moves(i, j, c);
				
				for (auto e : p) {
					int v = state(e.first, e.second, c);
					d[u][v] = min(d[u][v], resenje(1, 0));
				}

				d[u][u] = min(d[u][u], resenje(0, 0));

				for (int z=0; z<3; z++)
					if (z != c) {
						int v = state(i, j, z);
						d[u][v] = min(d[u][v], resenje(1, 1));
					}
			}
		}
	}

	int m = 3*n*n;
	for (int j=0; j<m; j++)
		for (int i=0; i<m; i++)
			for (int k=0; k<m; k++)
				d[i][k] = min(d[i][k], d[i][j] + d[j][k]);

	g[0][0] = g[1][0] = g[2][0] = {0, 0};

	for (int i=1; i<n*n; i++) {
		for (int c1=0; c1<3; c1++) {
			for (int c2=0; c2<3; c2++) {
				int u = state(x[i-1], y[i-1], c1);
				int v = state(x[i], y[i], c2);
				g[c2][i] = min(g[c2][i], g[c1][i-1] + d[u][v]);				
			}
		}
	}

	auto sol = min({g[0][n*n-1], g[1][n*n-1], g[2][n*n-1]});
	cout << sol.len << ' ' << sol.prom << '\n';
}