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

bool has_loop[1000005];
long long loops;
long long n, m;
vector<int> e[1000005];

bool vis[1000005];
int br;
void dfs(int x) {
	br++;
	vis[x] = true;
	for (int y : e[x]) {
		if (!vis[y]) {
			dfs(y);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int u, v;
		cin >> u >> v;
		if (u == v) {
			has_loop[u] = true;
			loops++;
		} else {
			e[u].push_back(v);
			e[v].push_back(u);
		}
	}

	int start = 0;
	int nn = n;

	for (int i=1; i<=n; i++) {
		if (!has_loop[i] && e[i].size() == 0) {
			nn--;
		} else {
			start = i;
		}
	}

	if (start == 0) {
		cout << 0;
		return 0;
	}

	cerr << start << '\n';

	dfs(start);

	if (br != nn || m < 2) {
		cout << 0;
		return 0;
	}

	long long sol = 0;

	// normalna resenja
	for (int i=1; i<=n; i++) {
		long long deg = e[i].size();
		sol += deg * (deg-1) / 2;
	}

	// loop - druga
	sol += loops * (m - loops);

	// loops medju sobom
	sol += loops * (loops - 1) / 2;

	cout << sol;
}