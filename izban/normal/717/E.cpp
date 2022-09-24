#include <unordered_map>
#include <unordered_set>
#include <functional>
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

const int MAXN = 1 << 18;

int n;
int a[MAXN];
vector<int> e[MAXN];

vector<int> ans;

void dfs(int v, int pr) {
	for (int to : e[v]) {
		if (to == pr) continue;
		a[to] *= -1;
		ans.push_back(to);
		dfs(to, v);
		a[v] *= -1;
		ans.push_back(v);
	}
	if (a[v] == -1 && pr != -1) {
		ans.push_back(pr);
		a[pr] *= -1;
		ans.push_back(v);
		a[v] *= -1;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u; --v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	bool any = 0;
	for (int i = 0; i < n; i++) any |= a[i] == -1;

	if (!any) {
		cout << 1 << endl;
		return 0;
	}

	ans.push_back(0);
	dfs(0, -1);
	if (a[0] == -1) {
		ans.push_back(e[0][0]);
		ans.push_back(0);
		ans.push_back(e[0][0]);
	}

	for (int i = 0; i < (int)ans.size(); i++) printf("%d%c", ans[i] + 1, " \n"[i + 1 == (int)ans.size()]);

	return 0;
}