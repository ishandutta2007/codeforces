#include<bits/stdc++.h>
using namespace std;
const int maxn = 1<<20;
int n, c[2] = {0, 0};
vector<int> g[maxn];
void dfs(int v, int p = -1, int d = 0) {
	c[d]++;
	for(int i : g[v]) if(i^p) dfs(i, v, d^1);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	dfs(1);
	cout << min(c[0], c[1])-1 << '\n';
	return 0;
}