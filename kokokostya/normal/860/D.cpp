#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>

using namespace std;

#define LOCAL

vector< vector<int> > g;
vector <bool> used;

struct vert {
	int a, b, c;
};

vector<vert> ans;
vector< vector<int> > will;
vector<int> p;
vector<int> h;

void dfs(int v) {
	used[v] = 1;
	for (int i : g[v]) {
		if (!used[i]) {
			p[i] = v;
			h[i] = h[v] + 1;
			dfs(i);
		}
		else {
			if (p[v] != i) {
				if (h[i] < h[v])
					will[i].push_back(v);
			}
		}
	}
	if (will[v].size() % 2 == 1) {
		if (p[v] != -1) {
			ans.push_back({ p[v], v, will[v].back() });
		}
		will[v].pop_back();
	}
	else {
		if (p[v] != -1)
			will[p[v]].push_back(v);
	}
	for (int i = 0; i < will[v].size(); i += 2) {
		ans.push_back({will[v][i], v, will[v][i + 1]});
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
#ifndef LOCAL
	freopen("victory.in", "r", stdin);
	freopen("victory.out", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	g.resize(n);
	used.resize(n);
	will.resize(n);
	h.resize(n);
	p.resize(n, -1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (!used[i])
			dfs(i);
	}
	cout << ans.size() << '\n';
	for (vert i : ans)
		cout << i.a + 1 << ' ' << i.b + 1 << ' ' << i.c + 1 << '\n';
	return 0;
}