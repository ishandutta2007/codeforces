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

int n;
vector<int> e[MAXN];
int h[MAXN], p[MAXN];

void dfs1(int v, int pr, int ch) {
	p[v] = pr;
	h[v] = ch;
	for (int to : e[v]) {
		if (to == pr) continue;
		dfs1(to, v, ch + 1);
	}
}

int dfs2(int v, int pr) {
	vector<int> vct;
	for (int to : e[v]) {
		if (to == pr) continue;
		vct.push_back(dfs2(to, v));
	}
	sort(vct.begin(), vct.end());
	if (!vct.empty() && vct[0] == -1) return -1;
	for (int i = 0; i < (int)vct.size(); i++) vct[i]++;
	if (vct.empty()) {
		vct.push_back(0);
	}
	vct.resize(unique(vct.begin(), vct.end()) - vct.begin());
	if (vct.size() > 2) return -1;
	if (vct.size() == 2) {
		if (pr == -1) return vct[0] + vct[1];
		return -1;
	}
	return vct[0];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++) {
			e[i].clear();
		}
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u; --v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int root = 0;
		dfs1(root, -1, 0);
		for (int i = 0; i < n; i++) if (h[i] > h[root]) root = i;
		dfs1(root, -1, 0);
		for (int i = 0; i < n; i++) if (h[i] > h[root]) root = i;
		vector<int> vct;
		while (root != -1) {
			vct.push_back(root);
			root = p[root];
		}
		root = vct[vct.size() / 2];
		int len = dfs2(root, -1);
		while (len % 2 == 0) len /= 2;
		cout << len << endl;
	}

	return 0;
}