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

const int maxn = 1 << 18;
const int inf = 1000000007;
const int mod = 1000000007;

int n, a[maxn];
int to[maxn][2];
ll sum[maxn][2];

int dfs1(int v, int k) {
	if (v <= 0 || v > n) return n + 1;
	if (to[v][k] > 0) return to[v][k];
	if (to[v][k] == -1) return -1;

	to[v][k] = -1;
	sum[v][k] = a[v];
	int nv = v + (k % 2 ? -a[v] : a[v]);
	int o = dfs1(nv, k ^ 1);

	to[v][k] = o;
	if (o != -1) sum[v][k] += sum[(nv >= 1 && nv <= n ? nv : n + 1)][k ^ 1];
	return to[v][k];
}

ll dfs2(int v, int k) {
	if (v != 1) return to[v][k];

	int nv = v + a[v];
	int o = dfs2(nv, k ^ 1);
	if (o == -1) return -1;
	return sum[nv][k ^ 1] + a[v];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 2; i <= n; i++) scanf("%d", &a[i]);

	for (int i = 2; i <= n; i++) {
		dfs1(i, 0);
		dfs1(i, 1);
	}

	for (int i = 1; i < n; i++) {
		a[1] = i;
		cout << dfs2(1, 0) << endl;
	}

	return 0;
}