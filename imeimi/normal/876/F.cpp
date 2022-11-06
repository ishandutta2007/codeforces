#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<llong, llong> pll;
typedef pair<double, double> pd;

int n;
int a[200000];
pi b[200000];
set<int> used;
int seg[1 << 19];
void init(int i, int s, int e) {
	if (s == e) {
		seg[i] = a[s];
		return;
	}
	int m = (s + e) / 2;
	init(i << 1, s, m);
	init(i << 1 | 1, m + 1, e);
	seg[i] = seg[i << 1] | seg[i << 1 | 1];
}

int qs1(int i, int s, int e, int x, int v) {
	if (e < x) return n;
	if ((seg[i] | v) == v) return n;
	if (s == e) return s;
	int m = (s + e) / 2;
	int ret = qs1(i << 1, s, m, x, v);
	if (ret == n) return qs1(i << 1 | 1, m + 1, e, x, v);
	return ret;
}

int qs2(int i, int s, int e, int x, int v) {
	if (x < s) return -1;
	if ((seg[i] | v) == v) return -1;
	if (s == e) return s;
	int m = (s + e) / 2;
	int ret = qs2(i << 1 | 1, m + 1, e, x, v);
	if (ret == -1) return qs2(i << 1, s, m, x, v);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		b[i] = { -a[i], i };
	}
	init(1, 0, n - 1);
	sort(b, b + n);
	used.insert(-1);
	used.insert(n);
	llong ans = 0ll;
	for (int _i = 0; _i < n; ++_i) {
		int i = b[_i].second;
		auto it = used.lower_bound(i);
		int ed = *it;
		int st = *(--it);
		int q = qs1(1, 0, n - 1, i, a[i]);
		int p = qs2(1, 0, n - 1, i, a[i]);
		ans += (llong)(ed - i) * (i - st) - (llong)(min(ed, q) - i) * (i - max(st, p));
		used.insert(i);
	}

	printf("%lld\n", ans);
	return 0;
}