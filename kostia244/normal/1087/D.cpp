#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int n, a, f, t, leaves = 0;
vector<vector<int>> g;

void dfs(int v = 1, int p = -1) {
	int c = 0;
	for(auto& i : g[v]) {
		if(i != p)
			dfs(i, v), c++;
	}
	if(c == 0 || (c == 1 && p == -1))
		leaves++;
}

int main() {
	cin >> n >> a;
	g.resize(n + 1);
	for(int i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	dfs();
	printf("%.15lf", (a * 2.0)/leaves);
	return 0;
}