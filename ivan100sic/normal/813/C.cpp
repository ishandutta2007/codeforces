#include <bits/stdc++.h>
using namespace std;

int n, bob;
vector<int> e[200005];

int d1[200005], dbob[200005];

void dfs(int x, int p, int d, int* dist) {
	dist[x] = d;
	for (int y : e[x]) {
		if (y != p) {
			dfs(y, x, d+1, dist);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> bob;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	dfs(1, 1, 0, d1);
	dfs(bob, bob, 0, dbob);

	int sol = 0;

	for (int i=2; i<=n; i++) {
		if (dbob[i] < d1[i]) {
			sol = max(sol, d1[i]);
		}
	}

	cout << 2*sol;

}