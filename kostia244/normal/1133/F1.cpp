//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 2e5 + 555;
using ld = long double;
int n, m;
bitset<maxn> vis;
vector<pair<int, int>> ans;
vector<vi> g;
void dfs(int v) {
	vis.set(v);
	for (auto i : g[v]) {
		if (vis.test(i))
			continue;
		dfs(i);
		ans.pb( { v, i });
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	g.resize(n + 1);
	for (int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		if (g[i].size() > g[mx].size())
			mx = i;
	}
	vis.set(mx);
	for (auto i : g[mx]) {
		ans.pb( { mx, i });
		vis.set(i);
	}
	for (auto i : g[mx]) {
		dfs(i);
	}
	for (auto i : ans)
		cout << i.first << " " << i.second << "\n";
}