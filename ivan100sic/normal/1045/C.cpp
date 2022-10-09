#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int n, m, q;
vector<int> e[100005];
set<int> e2[100005];
vector<int> e3[200005];
int par[18][200005];
int depth[200005];

void dfs(int x, int p) {
	par[0][x] = p;
	for (int i = 1; i < 18; i++) {
		par[i][x] = par[i - 1][par[i - 1][x]];
	}
	for (int y : e3[x]) {
		if (y != p) {
			depth[y] = depth[x] + 1;
			dfs(y, x);
		}
	}
}

int dizi(int x, int y) {
	for (int i = 0; i < 18; i++) {
		if (y & (1 << i)) {
			x = par[i][x];
		}
	}
	return x;
}

int lca(int x, int y) {
	if (depth[x] > depth[y]) {
		swap(x, y);
	}
	y = dizi(y, depth[y] - depth[x]);

	if (y == x) {
		return x;
	}

	for (int i = 17; i >= 0; i--) {
		int xx = par[i][x];
		int yy = par[i][y];

		if (xx != yy) {
			x = xx;
			y = yy;
		}
	}
	return par[0][x];
}

int dub[100005];
int idx[100005], low[100005], t;
int brojc;

vector<pair<int, int>> estack;

void bcc(int x, int p) {
	idx[x] = low[x] = ++t;
	int ch = 0;
	for (int y : e[x]) {
		// tree edge
		if (idx[y] == 0) {
			estack.push_back({ x, y });
			bcc(y, x);
			low[x] = min(low[x], low[y]);
			if (low[y] >= idx[x]) {
				brojc++;
				while (1) {
					auto t = estack.back();
					estack.pop_back();
					e2[t.first].insert(brojc);
					e2[t.second].insert(brojc);
					if (t == pair<int, int>{x, y})
						break;
				}
			}
		}
		else if (idx[y] < idx[x] && y != p) {
			// back edge
			low[x] = min(low[x], idx[y]);
			estack.push_back({ x, y });
		} // forward edge, do nothing
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}

	bcc(1, 1);

	if (estack.size()) {
		brojc++;
		while (estack.size()) {
			auto t = estack.back();
			estack.pop_back();
			e2[t.first].insert(brojc);
			e2[t.second].insert(brojc);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int x : e2[i]) {
			e3[i].push_back(x + n);
			e3[x + n].push_back(i);
		}
	}

	dfs(1, 1);

	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		int z = lca(x, y);
		int t = depth[x] + depth[y] - 2 * depth[z];
		cout << (t >> 1) << '\n';
	}

	// system("pause");

}