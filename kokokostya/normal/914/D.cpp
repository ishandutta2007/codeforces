



#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

//#define FAST_ALLOCATOR_MEMORY 1e8
#undef LOCAL
//#include "optimization.h"
const int MX = 5 * 1e5 + 7;
int t[4 * MX];
int a[MX];

int gcd(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

void build(int v, int tl, int tr) {
	if (tl == tr)
		t[v] = a[tl];
	else {
		int tm = (tl + tr) >> 1;
		build(v << 1, tl, tm);
		build((v << 1) | 1, tm + 1, tr);
		t[v] = gcd(t[v << 1], t[(v << 1) | 1]);
	}
}

void update(int v, int tl, int tr, int pos, int val) {
	if (tl == tr) {
		t[v] = val;
	}
	else {
		int tm = (tl + tr) >> 1;
		if (pos <= tm)
			update(v << 1, tl, tm, pos, val);
		else
			update((v << 1)|1, tm + 1, tr, pos, val);

		t[v] = gcd(t[v << 1], t[(v << 1) | 1]);
	}
}

int nw_get(int v, int tl, int tr, int x) {
	if (tl == tr)
		return tl;
	else {
		int tm = (tl + tr) >> 1;
		if (t[v << 1] % x != 0)
			return nw_get(v << 1, tl, tm, x);
		else
			return nw_get((v << 1) | 1, tm + 1, tr, x);
	}
}

int get_bad(int v, int tl, int tr, int l, int r, int x) {
	if (l > r)
		return -1;
	if (tl == l && r == tr) {
		if (t[v] % x == 0)
			return -1;
		else {
			return nw_get(v, tl, tr, x);
		}
	}
	else {
		int tm = (tl + tr) >> 1;
		int g = get_bad(v << 1, tl, tm, l, min(r, tm), x);
		if (g != -1)
			return g;
		else
			return get_bad((v << 1) | 1, tm + 1, tr, max(tm + 1, l), r, x);
	}
}

int get(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (tl == l && r == tr) {
		return t[v];
	}
	int tm = (tl + tr) >> 1;
	return gcd(get(v << 1, tl, tm, l, min(r, tm)), get((v << 1) | 1, tm + 1, tr, max(l, tm + 1), r));
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int q;
	cin >> q;
	build(1, 0, n - 1);
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			l--; r--;
			int g = get_bad(1, 0, n - 1, l, r, x);
			if (g == -1) {
				cout << "YES\n";
			}
			else {
				update(1, 0, n - 1, g, x);
				if(get(1, 0, n - 1, l, r) == x)
					cout << "YES\n";
				else
					cout << "NO\n";
				update(1, 0, n - 1, g, a[g]);
			}
		}
		else {
			int pos, val;
			cin >> pos >> val;
			pos--;
			update(1, 0, n - 1, pos, val);
			a[pos] = val;
		}
	}
	
	return 0;
}