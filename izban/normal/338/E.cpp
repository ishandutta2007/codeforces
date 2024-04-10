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

int n, len, h;
int a[maxn], b[maxn];

int t[2 * maxn], add[2 * maxn];

void push(int v, int tl, int tr) {
	if (add[v]) {
		if (tl != tr) add[v * 2] += add[v];
		if (tl != tr) add[v * 2 + 1] += add[v];
		t[v] += add[v];
		add[v] = 0;
	}
}

void upd(int v, int tl, int tr, int l, int r, int x) {
	push(v, tl, tr);
	if (l > r) return;
	if (l == tl && r == tr) {
		add[v] += x;
		push(v, tl, tr);
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(v * 2, tl, tm, l, min(r, tm), x);
	upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
	t[v] = min(t[v * 2], t[v * 2 + 1]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n >> len >> h) {
		for (int i = 0; i < len; i++) cin >> b[i];
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(b, b + len);

		for (int i = 0; i < len; i++) upd(1, 0, len - 1, i, i, -i - 1);
		for (int i = 0; i < len; i++) upd(1, 0, len - 1, lower_bound(b, b + len, h - a[i]) - b, len - 1, 1);

		int ans = 0;
		for (int i = 0; i + len - 1 < n; i++) {
			ans += t[1] >= 0;
			upd(1, 0, len - 1, lower_bound(b, b + len, h - a[i]) - b, len - 1, -1);
			upd(1, 0, len - 1, lower_bound(b, b + len, h - a[i + len]) - b, len - 1, 1);
		}
		cout << ans << endl;
	}

	return 0;
}