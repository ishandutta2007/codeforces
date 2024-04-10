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

int n, q, t;
int a[301];
int p[301], nxt[301], vis[301];

void rec(int i, int h = 0) {
	if (p[i]) rec(p[i], h + 1);
	t -= a[i] * h;
	if (t < 0) t = -1;
	a[i] += a[p[i]];
	vis[i] = 1;
}

int dp[100001][301];

void add(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int calc(int x, int cur) {
	if (x < 0 || cur == n && x > 0) return 0;
	if (dp[x][cur] != -1) return dp[x][cur];
	dp[x][cur] = 0;
	add(dp[x][cur], calc(x - a[cur], cur));
	add(dp[x][cur], calc(x, cur + 1));
	return dp[x][cur];
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> q >> t;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		p[y] = x;
		nxt[x] = y;
	}

	for (int i = 1; i <= n; i++) if (!nxt[i]) rec(i);
	for (int i = 1; i <= n; i++) if (!vis[i]) {cout << 0; return 0;}
	for (int i = 0; i < n; i++) a[i] = a[i + 1];

	memset(dp, -1, sizeof(dp));
	for (int i = 0; i <= n; i++) dp[0][i] = 1;
	cout << calc(t, 0) << endl;

	return 0;
}