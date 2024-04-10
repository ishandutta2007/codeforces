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


int n;
ll t[2 * maxn], add[2 * maxn];

void push(int v, int tl, int tr) {
	t[v] += add[v] * (tr - tl + 1);
	if (tl != tr) {
		add[v * 2] += add[v];
		add[v * 2 + 1] += add[v];
	}
	add[v] = 0;
}

void upd(int v, int tl, int tr, int l, int r, int x) {
	push(v, tl, tr);
	if (l > r) return;
	if (tl == l && tr == r) {
		add[v] += x;
		push(v, tl, tr);
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(v * 2, tl, tm, l, min(r, tm), x);
	upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
	t[v] = t[v * 2] + t[v * 2 + 1];
}

ll sum(int v, int tl, int tr, int l, int r) {
	push(v, tl, tr);
	if (l > r) return 0;
	if (l == tl && r == tr) return t[v];
	ll res = 0;
	int tm = (tl + tr) >> 1;
	res += sum(v * 2, tl, tm, l, min(r, tm));
	res += sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int cur = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y, z;
		scanf("%d", &x);
		if (x == 1) {
			scanf("%d%d", &y, &z);
			y--;
			upd(1, 0, maxn - 1, 0, y, z);
		}
		if (x == 2) {
			scanf("%d", &y);
			upd(1, 0, maxn - 1, cur, cur, y);
			cur++;
		}
		if (x == 3) {
			cur--;
			upd(1, 0, maxn - 1, cur, cur, -sum(1, 0, maxn - 1, cur, cur));
		}
		double ans = 0;
		ans += sum(1, 0, maxn - 1, 0, maxn - 1);
		ans /= cur;
		printf("%.10lf\n", ans);
	}

	return 0;
}