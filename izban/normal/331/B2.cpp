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

const int maxn = 1 << 19;
const int inf = 1000000007;
const int mod = 1000000007;

int n, m;
vector<int> a, b;
int tp[maxn], x[maxn], y[maxn];

void reading() {
	scanf("%d", &n);
	a.resize(n + 1);
	b.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b[a[i]] = i;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &tp[i], &x[i], &y[i]);
	}
}

void print(vector<int> v) {
	for (int i = 0; i < v.size(); i++) printf("%d\n", v[i]);
}

int calcdp(int l, int r) {
	int res = 1;
	for (int i = l; i < r; i++) {
		if (b[i + 1] < b[i]) res++;
	}
	return res;
}

int t[2 * maxn], tl[2 * maxn], tm[2 * maxn], tr[2 * maxn];

int combine(int v, int x, int u, int y) {
	return v + u - (x < y);
}

void build(int v, int TL, int TR) {
	tl[v] = TL; tr[v] = TR;
	if (tl[v] == tr[v]) {
		t[v] = 1;
		return;
	}
	tm[v] = (tl[v] + tr[v]) >> 1;
	build(v * 2, tl[v], tm[v]);
	build(v * 2 + 1, tm[v] + 1, tr[v]);
	t[v] = combine(t[v * 2], b[tr[v * 2]], t[v * 2 + 1], b[tl[v * 2 + 1]]);
}

int get(int v, int l, int r) {
	if (l > r) return 0;
	if (tl[v] == l && tr[v] == r) return t[v];
	int o1 = get(v * 2, l, min(r, tm[v]));
	int o2 = get(v * 2 + 1, max(l, tm[v] + 1), r);
	return combine(o1, (o1 > 0 ? b[tr[v * 2]] : inf), o2, (o2 > 0 ? b[tl[v * 2 + 1]] : -inf));
}

void upd(int v, int x, int y) {
	if (tl[v] == tr[v]) {
		b[tl[v]] = y;
		return;
	}
	if (x <= tm[v]) upd(v * 2, x, y);
	else upd(v * 2 + 1, x, y);
	t[v] = combine(t[v * 2], b[tr[v * 2]], t[v * 2 + 1], b[tl[v * 2 + 1]]);
}

vector<int> slowsolve() {
	vector<int> res;
	build(1, 0, n);
	for (int i = 0; i < m; i++) {
		if (tp[i] == 1) {
			res.push_back(get(1, x[i], y[i]));
		}
		if (tp[i] == 2) {
			upd(1, a[x[i]], y[i]);
			upd(1, a[y[i]], x[i]);
			swap(a[x[i]], a[y[i]]);
		}
	}
	for (int i = m - 1; i >= 0; i--) if (tp[i] == 2) {
		swap(a[x[i]], a[y[i]]);
		b[a[x[i]]] = x[i];
		b[a[y[i]]] = y[i];
	}
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	reading();
	print(slowsolve());

	return 0;
}