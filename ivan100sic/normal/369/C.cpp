#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
vector<pair<int, int>> e[100005];
vector<int> sol;

int dfs(int x, int p, int z) {
	int prob = 0;
	for (auto ee : e[x]) {
		int y = ee.first;
		int w = ee.second;
		if (y == p)
			continue;
		prob += dfs(y, x, w) + (w == 2);
	}
	if (z == 2 && prob == 0)
		sol.push_back(x);
	return prob;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		e[x].push_back({y, z});
		e[y].push_back({x, z});
	}

	dfs(1, 1, 1);

	cout << sol.size() << '\n';
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
}