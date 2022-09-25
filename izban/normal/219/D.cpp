#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>


using namespace std;


const int maxn = 200100;

int n, ans[maxn], mn = 1e6;
vector<pair<int, int>> e[maxn];

void bfs(int v) {
	ans[1] = 0;
	queue<int> q;
	q.push(v);
	vector<int> d(n + 1, 1e6);
	d[v] = 1;
	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (int i = 0; i < e[v].size(); i++) {
			int u = e[v][i].first;
			if (d[u] > d[v] + e[v][i].second) {
				q.push(u);
				d[u] = d[v] + e[v][i].second;
				ans[1] += e[v][i].second;
			}
		}
	}
}

void dfs(int v, int a) {
	if (ans[v] != -1) return;
	ans[v] = a;
	mn = min(mn, ans[v]);
	for (int i = 0; i < e[v].size(); i++) {
		int x = e[v][i].second == 0? 1 : -1;
		dfs(e[v][i].first, a + x);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(ans, -1, sizeof(ans));

	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		e[x].push_back(make_pair(y, 0));
		e[y].push_back(make_pair(x, 1));
	}
	bfs(1);
	int k = ans[1];
	ans[1] = -1;
	dfs(1, k);

	cout << mn << endl;
	for (int i = 1; i <= n; i++)
		if (ans[i] == mn)
			cout << i << " ";

	return 0;
}