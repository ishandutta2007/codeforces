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

int n;
vector<int> e[35];

long long xx[35], yy[35];

void dfs(int u, int p, long long x, long long y, long long dx, long long dy) {
	xx[u] = x;
	yy[u] = y;

	dx *= -1;
	dy *= -1;

	dx /= 2;
	dy /= 2;

	for (int v : e[u]) {
		if (v != p) {
			long long t = dx;
			dx = -dy;
			dy = t;

			dfs(v, u, x+dx, y+dy, dx, dy);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	for (int i=1; i<=n; i++) {
		if (e[i].size() > 4) {
			cout << "NO";
			return 0;
		}
	}

	dfs(1, 1, 0, 0, 1 << 30, 0);

	cout << "YES\n";
	for (int i=1; i<=n; i++) {
		cout << xx[i] << ' ' << yy[i] << '\n';
	}
}