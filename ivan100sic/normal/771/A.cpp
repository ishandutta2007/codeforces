#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> e[150005];
bool v[150005];

int ec, vc;

void dfs(int x) {
	vc++;
	ec += e[x].size();
	v[x] = true;
	for (int y : e[x]) {
		if (!v[y]) {
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
		e[u].push_back(v);
		e[v].push_back(u);
	}

	for (int i=1; i<=n; i++) {
		if (!v[i]) {
			ec = vc = 0;
			dfs(i);
			if (vc * 1ll * (vc - 1) != ec) {
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
}