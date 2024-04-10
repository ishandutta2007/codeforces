#include<bits/stdc++.h>

using namespace std;

#define int long long

vector<vector<int>> g;
map<int, int> mp;
vector<int> a;
int ans = 0, mod = 1e9 + 7;

void dfs(int v, int pr, map<int, int> &p) {
	map<int, int> new_p;
	new_p[a[v]]++;
	for (auto &c : p) {
		new_p[__gcd(a[v], c.first)] += c.second;
	}
	for (auto &c : new_p) {
		ans += c.second * c.first;
		ans %= mod;
	}
	for (auto &c : g[v]) {
		if (c != pr) {
			dfs(c, v, new_p);
		}
	}
}

signed main() {
	int n;
	cin >> n;
	a.resize(n);
	g.resize(n);
	for (auto &c : a) {
		cin >> c;
	}
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(0, -1, mp);
	cout << ans;
}