#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

struct segment_tree {
	static const int maxn = 1 << 19;
	int add[maxn << 1], mx[maxn << 1];
	void push_down(int i) {
		if (add[i]) {
			mx[i] += add[i];
			if (i < maxn) {
				add[i << 1] += add[i];
				add[i << 1 | 1] += add[i];
			}
			add[i] = 0;
		}
	}
	void upd(int l, int r, int v, int i = 1, int a = 0, int b = maxn) {
		if (l <= a && b <= r) {
			add[i] += v; push_down(i); return ;
		}
		push_down(i);
		if (r <= a || b <= l) {
			return ;
		}
		int m = (a + b) >> 1;
		upd(l, r, v, i << 1, a, m);
		upd(l, r, v, i << 1 | 1, m, b);
		mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
	}
	int qry() {
		return mx[1];
	}
} segt;

const int maxn = 300005;
int n;
int p[maxn], pos[maxn], q[maxn];

int main() {
	ios :: sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; ++ i) {
		cin >> p[i]; p[i] --;
		pos[p[i]] = i;
	}
	for (int i = 0; i < n; ++ i) {
		cin >> q[i]; q[i] --;
	}
	int ans = n - 1;
	for (int i = 0; i < n; ++ i) {
		while (true) {
			segt.upd(0, pos[ans] + 1, 1);
			if (segt.qry() > 0) {
				segt.upd(0, pos[ans] + 1, -1);
				break;
			}
			-- ans;
		}
		cout << ans + 1 << " \n"[i + 1 == n];
		segt.upd(0, q[i] + 1, -1);
	}
	return 0;
}