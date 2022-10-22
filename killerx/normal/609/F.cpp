#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

#define pii pair <int, int>

const int mxn = 2e5 + 5;
const int inf = 1e9 + 7;
const pii pinf = {inf, inf};
int n, q, cnt[mxn], x[mxn];
ll t[mxn];
multiset <pii> food;

struct SEG {
	static const int mxn = 3e7 + 5;
	int tot, ls[mxn], rs[mxn];
	pii mn[mxn];

	int nd() {
		int x = ++ tot;
		ls[x] = rs[x] = 0;
		mn[x] = pinf;
		return x;
	}

	void upd(int& x, int a, int b, int l, int r, pii v) {
		if (r <= a || b <= l) return ;
		if (!x) x = nd();
		if (l <= a && b <= r) return void((mn[x] = min(mn[x], v)));
		int m = (a + b) >> 1;
		upd(ls[x], a, m, l, r, v);
		upd(rs[x], m, b, l, r, v);
	}

	pii qry(int x, int a, int b, int p) {
		if (!x) return pinf;
		if (a + 1 == b) return mn[x];
		int m = (a + b) >> 1;
		if (p < m) return min(qry(ls[x], a, m, p), mn[x]);
		else return min(qry(rs[x], m, b, p), mn[x]);
	}
} seg;

int rt;

int main() {
	scanf("%d %d", &n, &q);
	rep(i, n) {
		scanf("%d %lld", &x[i], &t[i]);
		seg.upd(rt, 0, inf, x[i], min(1LL * inf, x[i] + t[i] + 1), {x[i], i});
	}
	while (q --) {
		int p, b; scanf("%d %d", &p, &b);
		int i = seg.qry(rt, 0, inf, p).second;
		if (i >= n) {
			food.insert({p, b});
			continue;
		}
		t[i] += b;
		++ cnt[i];
		auto it = food.lower_bound({x[i], 0});
		while (it != food.end() && it->first <= x[i] + t[i]) {
			t[i] += it->second;
			++ cnt[i];
			it = food.erase(it);
		}
		seg.upd(rt, 0, inf, x[i], min(1LL * inf, x[i] + t[i] + 1), {x[i], i});
	}
	rep(i, n) {
		printf("%d %lld\n", cnt[i], t[i]);
	}
	// cerr << seg.tot << endl;
	return 0;
}