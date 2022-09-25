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

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n, m, d;
int ans;
bool f[maxn];
int mx[maxn];
vector<int> e[maxn];

void dfs1(int v, int p = -1) {
	if (f[v]) mx[v] = 0;
	for (int i = 0; i < e[v].size(); i++) if (e[v][i] != p) {
		dfs1(e[v][i], v);
		if (mx[e[v][i]] != -1) mx[v] = max(mx[v], mx[e[v][i]] + 1);
	}
}

//int mxl[maxn], mxr[maxn];

void dfs2(int v, int p = -1) {
	vector<int> mxl(e[v].size(), -1), mxr(e[v].size(), -1);

	if (mx[e[v][0]] != -1) mxl[0] = mx[e[v][0]] + 1;
	for (int i = 1; i < e[v].size(); i++) {
		mxl[i] = mxl[i - 1];
		if (mx[e[v][i]] != -1) mxl[i] = max(mxl[i], mx[e[v][i]] + 1);
	}
	if (mx[e[v][e[v].size() - 1]] != -1) mxr[e[v].size() - 1] = mx[e[v][e[v].size() - 1]] + 1;
	for (int i = (int)e[v].size() - 2; i >= 0; i--) {
		mxr[i] = mxr[i + 1];
		if (mx[e[v][i]] != -1) mxr[i] = max(mxr[i], mx[e[v][i]] + 1);
	}

	if (mxl[e[v].size() - 1] <= d) 
		ans++;

	for (int i = 0; i < e[v].size(); i++) if (e[v][i] != p) {
		mx[v] = -1;
		if (f[v]) mx[v] = 0;
		if (i > 0) mx[v] = max(mx[v], mxl[i - 1]);
		if (i < (int)e[v].size() - 1) mx[v] = max(mx[v], mxr[i + 1]);
		dfs2(e[v][i], v);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n >> m >> d) {
		for (int i = 1; i <= n; i++) e[i].clear();
		memset(f, 0, sizeof(f));
		memset(mx, -1, sizeof(mx));
		for (int i = 0; i < m; i++) {
			int x;
			scanf("%d", &x);
			f[x] = true;
		}
		for (int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			e[u].push_back(v);
			e[v].push_back(u);
		}

		ans = 0;
		dfs1(1);
		dfs2(1);
		cout << ans << endl;
	}

	return 0;
}