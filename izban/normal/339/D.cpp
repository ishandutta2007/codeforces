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

int n, m;
int a[maxn];
int t[4 * maxn];

void build(int v, int tl, int tr, int h) {
	if (tl == tr) {
		t[v] = a[tl];
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2, tl, tm, h - 1);
	build(v * 2 + 1, tm + 1, tr, h - 1);
	if (h % 2 == 0) t[v] = t[v * 2] | t[v * 2 + 1];
	else t[v] = t[v * 2] ^ t[v * 2 + 1];
}

void upd(int v, int tl, int tr, int x, int y, int h) {
	if (tl == tr) {
		t[v] = y;
		return;
	}
	int tm = (tl + tr) >> 1;
	if (x <= tm) upd(v * 2, tl, tm, x, y, h - 1);
	else upd(v * 2 + 1, tm + 1, tr, x, y, h - 1);
	if (h % 2 == 0) t[v] = t[v * 2] | t[v * 2 + 1];
	else t[v] = t[v * 2] ^ t[v * 2 + 1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> m;
	for (int i = 0; i < 1 << n; i++) cin >> a[i];
	build(1, 0, (1 << n) - 1, n + 1);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		upd(1, 0, (1 << n) - 1, x - 1, y, n + 1);
		cout << t[1] << endl;
	}

	return 0;
}