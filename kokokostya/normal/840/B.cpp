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

vector<int> d;
vector< vector< pair<int, int> > > g;
set<int> ans;
vector<bool> used;

bool dfs(int v) {
	used[v] = 1;
	int res = 0;
	for (pair<int, int> i : g[v]) {
		if (!used[i.first]) {
			if (!dfs(i.first)) {
				res++;
				ans.insert(i.second);
			}
		}
	}
	if (d[v] == -1 || res % 2 == d[v])
		return 1;	
	else
		return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	d.resize(n);
	g.resize(n);
	int is = 0;
	used.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		if (d[i] == -1)
			is = i;
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back({b, i});
		g[b].push_back({ a, i });
	}
	if (dfs(is)) {
		cout << ans.size() << '\n';
		for (int i : ans)
			cout << i << '\n';
	}
	else {
		cout << -1;
	}
	return 0;
}