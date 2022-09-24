#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXK = -1;
const int MAXN = 1 << 18;
const int MOD = 0; // 1000 * 1000 * 1000 + 7;

int n, m, k;
vector<int> e[MAXN];
int vis[MAXN];
vector<int> vct;

void dfs(int v) {
	vis[v] = 1;
	vct.push_back(v);
	for (int to : e[v]) {
		if (vis[to]) continue;
		dfs(to);
		vct.push_back(v);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	bool first = 1;
	while (scanf("%d%d%d", &n, &m, &k) == 3) {
		if (first) first = 0;
		else printf("\n");
		for (int i = 0; i < n; i++) {
			e[i].clear();
			vis[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u; --v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		vct.clear();
		dfs(0);
		int x = (2 * n + k - 1) / k;
		
		vector<vector<int> > ans;
		for (int i = 0; i < (int)vct.size(); i++) {
			int j = min((int)vct.size() - 1, i + x - 1);
			vector<int> cur;
			for (int k = i; k <= j; k++) cur.push_back(vct[k]);
			i = j;
			ans.push_back(cur);
		}
		assert((int)ans.size() <= k);
		while (ans.size() < k) ans.push_back(vector<int>(1, 1));
		for (int i = 0; i < (int)ans.size(); i++) {
			printf("%d", (int)ans[i].size());
			for (int x : ans[i]) printf(" %d", x + 1);
			printf("\n");
		}
	}

	return 0;
}