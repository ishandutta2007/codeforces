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

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

struct bit {
	static const int maxn = 1e5 + 5;
	ll s0[maxn], s1[maxn];
	void upd(int x, int v) {
		for (int ix = x; x < maxn; x += x & -x)
			s0[x] += v, s1[x] += 1LL * ix * v;
	}
	void upd(int l, int r, int v) {
		upd(l, v); upd(r + 1, -v);
	}
	ll qry(int x) {
		ll ans = 0;
		for (int ix = x; x; x -= x & -x)
			ans += 1LL * (ix + 1) * s0[x] - s1[x];
		return ans;
	}
	ll qry(int l, int r) {
		return qry(r) - qry(l - 1);
	}
} sum;

int n, q;
map <int, int> a;

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; ++ i) a[i] = i;
	while (q --) {
		int tp; scanf("%d", &tp);
		int l, r; scanf("%d %d", &l, &r);
		if (tp == 1) {
			int x; scanf("%d", &x);
			map <int, int> :: iterator it;
			it = a.upper_bound(l); -- it;
			int lst;
			while (it != a.end() && it -> first <= r) {
				lst = it -> second;
				int st = it -> first;
				if (st < l) st = l;
				map <int, int> :: iterator rit = it;
				++ it; if (rit -> first >= l) a.erase(rit);
				int ed = r;
				if (it != a.end() && it -> first <= r)
					ed = it -> first - 1;
				sum.upd(st, ed, abs(x - lst));
			}
			a[l] = x;
			if (r + 1 <= n && !a.count(r + 1))
				a[r + 1] = lst;
		} else {
			printf("%lld\n", sum.qry(l, r));
		}
	}
	return 0;
}