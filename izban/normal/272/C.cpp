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
const int inf = 1000000007;
const int mod = 1000000007;

int n, m, a[maxn], b[maxn], c[maxn];
ll t[2 * maxn], p[2 * maxn];

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = a[tl];
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v] = max(t[v * 2], t[v * 2 + 1]);
}

void push(int v, bool f) {
	if (p[v]) {
		if (f) p[2 * v] = p[v];
		if (f) p[2 * v + 1] = p[v];
		t[v] = p[v];
		p[v] = 0;
	}
}

ll get(int v, int tl, int tr, int l, int r) {
	push(v, tl != tr);
	if (l > r) return 0;
	if (tl == l && tr == r) return t[v];
	int tm = (tl + tr) >> 1;
	return max(
		get(v * 2, tl, tm, l, min(r, tm)),
		get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void upd(int v, int tl, int tr, int l, int r, ll x) {
	push(v, tl != tr);
	if (l > r) return;
	if (tl == l && tr == r) {
		p[v] = x;
		push(v, tl != tr);
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(v * 2, tl, tm, l, min(r, tm), x);
	upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
	t[v] = max(t[v * 2], t[v * 2 + 1]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf("%d", &a[i]);
	build(1, 0, n - 1);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &b[i], &c[i]);
		ll mx = get(1, 0, n - 1, 0, b[i] - 1);
		cout << mx << endl;
		upd(1, 0, n - 1, 0, b[i] - 1, mx + c[i]);
	}


	return 0;
}