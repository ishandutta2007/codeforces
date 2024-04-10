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


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const ll inf = 1000000000000000007LL;
const int mod = 1000000007;

int n;
ll sum[maxn], ans[maxn], a[maxn], sumup[maxn];
ll pl[maxn], ms[maxn];
vector<int> e[maxn];

ll abs1(ll x) {
	return x >= 0 ? x : -x;
}

/*void dfs(int v, int p = -1) {
	ll mx = 0, mn = 0;
	for (int i = 0; i < e[v].size(); i++) if (e[v][i] != p) {
		dfs(e[v][i], v);
		ans[v] += ans[e[v][i]];
		a[v] += sumup[e[v][i]];
		sumup[v] += sumup[e[v][i]];
	}
	sumup[v] += -a[v];
	ans[v] += abs1(a[v]);
}*/

/*void dfs(int v, int p = -1) {
	ll mx = 0, mn = 0;
	for (int i = 0; i < e[v].size(); i++) if (e[v][i] != p) {
		dfs(e[v][i], v);
		mx = max(mx, sum[e[v][i]]);
		mn = min(mn, sum[e[v][i]]);
		ans[v] += ans[e[v][i]];
	}
	a[v] += mn + mx;
	sum[v] = -a[v] + mn + mx;
	ans[v] += abs1(a[v]);
}*/

void dfs(int v, int p = -1) {
	for (int i = 0; i < e[v].size(); i++) if (e[v][i] != p) {
		dfs(e[v][i], v);
		pl[v] = max(pl[v], pl[e[v][i]]);
		ms[v] = max(ms[v], ms[e[v][i]]);
	}
	a[v] += pl[v] - ms[v];
	pl[v] -= min(0LL, a[v]);
	ms[v] += max(0LL, a[v]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		cin >> a[i];
		//scanf("%d", &a[i]);

	dfs(1);
	cout << pl[1] + ms[1] << endl;

	return 0;
}