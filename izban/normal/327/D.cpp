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
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 512;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};


int n, m;
string a[maxn];
vector<vector<char> > vis;
vector<pair<char, pair<int, int> > > ans;

bool ok(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

void dfs(int i, int j, bool f) {
	if (!ok(i, j) || vis[i][j] || a[i][j] == '#') return;
	vis[i][j] = 1;
	ans.push_back(make_pair('B', make_pair(i, j)));
	for (int k = 0; k < 4; k++) {
		int nx = i + dx[k], ny = j + dy[k];
		dfs(nx, ny, 1);
	}
	if (f) {
		ans.push_back(make_pair('D', make_pair(i, j)));
		ans.push_back(make_pair('R', make_pair(i, j)));
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) cin >> a[i];
		vis.assign(n, vector<char>(m, 0));
		ans.clear();
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) dfs(i, j, 0);
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++) printf("%c %d %d\n", ans[i].first, ans[i].second.first + 1, ans[i].second.second + 1);
	}

	return 0;
}