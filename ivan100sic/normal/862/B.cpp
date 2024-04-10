#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> e[100005];
int c[2];

void dfs(int x, int p, int d) {
	c[d]++;
	for (int y : e[x]) {
		if (y != p) {
			dfs(y, x, 1-d);
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

	dfs(1, 1, 0);

	long long sol = c[0] * 1ll * c[1] - (n-1);

	cout << sol;
}