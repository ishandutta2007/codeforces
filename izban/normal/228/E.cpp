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
#include <deque>

using namespace std;

#define ll long long


const int maxn = 1 << 7;

int n, m, cnt = 1;
vector<pair<int, int> > e[maxn];

pair<int, int> c[maxn];

bool dfs(int v, int x, int time) {
	if (c[v].second == time) return 1;
	c[v] = make_pair(x, time);
	for (int i = 0; i < e[v].size(); i++) {
		if (c[e[v][i].first].second != time)
			if (!dfs(e[v][i].first, x ^ e[v][i].second ^ 1, time)) return 0;
		if (c[e[v][i].first].first != (x ^ e[v][i].second ^ 1)) 
			return false;
	}
	return 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		e[x].push_back(make_pair(y, z));
		e[y].push_back(make_pair(x, z));
	}

	for (int i = 1; i <= n; i++) {
		if (c[i].second != cnt) {
			if (!dfs(i, 0, ++cnt))
				if (!dfs(i, 1, ++cnt)) {
					cout << "Impossible";
					return 0;
				}
		}
	}

	vector<int> ans;
	for (int i = 1; i <= n; i++)
		if (c[i].first == 1)
			ans.push_back(i);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";

	return 0;
}