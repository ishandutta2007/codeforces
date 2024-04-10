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

int n, m;
int a[300005];
vector<pair<int, int>> e[300005];
int u[300005], v[300005];

vector<int> flip;
vector<int> sol;

int f[300005];
int vis[300005];

int dfs(int x) {
	vis[x] = 1;
	int ret = f[x];
	for (auto p : e[x]) {
		int y = p.first;
		int eid = p.second;
		if (!vis[y]) {
			int t = dfs(y);
			if (t == 1) {
				sol.push_back(eid);
			}
			ret ^= t;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	for (int i=1; i<=m; i++) {
		cin >> u[i] >> v[i];
		e[u[i]].push_back({v[i], i});
		e[v[i]].push_back({u[i], i});
	}

	int minus1 = count(a+1, a+n+1, -1);
	int plus1 = count(a+1, a+n+1, 1);

	if (minus1 == 0 && plus1 % 2 == 1) {
		cout << -1;
		return 0;
	}

	for (int i=1; i<=n; i++) {
		if (a[i] == 1) {
			flip.push_back(i);
		}
	}

	if (plus1 % 2 == 1) {
		for (int i=1; i<=n; i++) {
			if (a[i] == -1) {
				flip.push_back(i);
				break;
			}
		}
	}

	for (int x : flip) {
		f[x] = 1;
	}

	dfs(1);

	cout << sol.size() << '\n';
	for (int x : sol) {
		cout << x << '\n';
	}
}