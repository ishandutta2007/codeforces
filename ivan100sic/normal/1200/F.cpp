#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int k0[1005], m[1005];
vector<int> e[1005];

bool vis[1005][2520];
bool inst[1005][2520];
pair<int, int> sink[1005][2520];
int sol[1005][2520];

pair<int, int> nx(int x, int y) {
	int yy = y + k0[x];
	int xx = e[x][yy % m[x]];
	yy -= 2520 * (yy >= 2520);
	return {xx, yy};
}

void dfs(int x, int y) {
	vis[x][y] = true;
	inst[x][y] = true;

	auto [xx, yy] = nx(x, y);

	if (!vis[xx][yy]) {
		dfs(xx, yy);
		sink[x][y] = sink[xx][yy];
	} else if (!inst[xx][yy]) {
		sink[x][y] = sink[xx][yy];
	} else {
		sink[x][y] = {x, y};
	}

	inst[x][y] = false;
}

int c[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> k0[i];
		k0[i] = (k0[i] + 1002519000) % 2520;
	}
	for (int i=1; i<=n; i++) {
		cin >> m[i];
		e[i].resize(m[i]);
		for (int& x : e[i])
			cin >> x;
	}

	for (int i=1; i<=n; i++) {
		for (int j=0; j<2520; j++) {
			if (!vis[i][j]) {
				dfs(i, j);
			}
		}
	}

	memset(sol, 255, sizeof(sol));

	for (int i=1; i<=n; i++) {
		for (int j=0; j<2520; j++) {
			auto [x, y] = sink[i][j];
			if (sol[x][y] == -1) {
				int z = 0;
				int xx = x, yy = y;
				do {
					z += 1 - c[xx], c[xx] = 1;
					tie(xx, yy) = nx(xx, yy);
				} while (tie(xx, yy) != tie(x, y));
				sol[x][y] = z;
				xx = x, yy = y;
				do {
					c[xx] = 0;
					tie(xx, yy) = nx(xx, yy);
				} while (tie(xx, yy) != tie(x, y));
			}
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		y = (y + 1002519000) % 2520;
		tie(x, y) = sink[x][y];
		cout << sol[x][y] << '\n';
	}
}