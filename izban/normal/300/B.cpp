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


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 6;
const int mod = 1000000007;

int n, m, cnt;
int team[maxn];
vector<int> e[maxn], ans[maxn];

void dfs(int v) {
	if (team[v]) return;
	team[v] = cnt;
	ans[cnt].push_back(v);
	for (int i = 0; i < e[v].size(); i++) dfs(e[v][i]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
		if (e[i].size() && !team[i])
			cnt++, dfs(i);
	
	bool res = 1;
	for (int i = 1; i <= max(cnt, n / 3); i++) {
		if (ans[i].size() > 3) {
			res = 0;
		}
		while (ans[i].size() < 3) {
			int j;
			for (j = 1; j <= n; j++) if (!team[j]) {
				team[j] = i;
				ans[i].push_back(j);
				break;
			}
			if (j == n + 1) {
				res = 0;
				break;
			}
		}
	}

	if (res) {
		for (int i = 1; i <= n / 3; i++) {
			for (int j = 0; j < 3; j++)
				cout << ans[i][j] << " \n"[j == 2];
		}
	} else cout << -1 << endl;

	return 0;
}