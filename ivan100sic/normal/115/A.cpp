#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> e[2005];
vector<int> roots;

int dfs(int x) {
	int r = 0;
	for (int y : e[x]) {
		r = max(r, dfs(y));
	}
	return r + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		if (x == -1) {
			roots.push_back(i);
		} else {
			e[x].push_back(i);
		}
	}
	int sol = 0;
	for (int x : roots) {
		sol = max(sol, dfs(x));
	}
	cout << sol;
}