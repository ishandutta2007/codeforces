#include <bits/stdc++.h>
using namespace std;

void solve_case();

signed main() {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);

	// int test; for (cin >> test; test --; )
	{
		solve_case();
	}
}

const int N = 1e5 + 5;

#define int long long

struct ring_t {
	int a, b, h;
	bool operator < (const ring_t &o) const {
		return b > o.b || (b == o.b && a < o.a);
	}
} _ring[N], ring[N];

int n, m, dp[N], val[N << 1], st[N << 3];

#define tm ((tl + tr) >> 1)
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

void update(int l, int r, int v, int id = 1, int tl = 1, int tr = n) {
	if (l > tr || tl > r) return ;
	if (l <= tl && tr <= r) 
		return st[id] = max(st[id], v), (void) 0;
	update(l, r, v, left), update(l, r, v, right);
}

int query(int p, int id = 1, int tl = 1, int tr = n) {
	if (tl == tr) return st[id];
	return max(st[id], p > tm ? query(p, right) : query(p, left));
}

void solve_case() {
	cin >> n;
	for (int i = 1, a, b, h; i <= n; i++)
		cin >> a >> b >> h, _ring[i] = {a, b, h};
	sort(_ring + 1, _ring + n + 1);

	// simplify
	for (int i = 1; i <= n; i++) {
		if (m && ring[m].b == _ring[i].b)
			ring[m].h += _ring[i].h;
		else
			ring[++ m] = _ring[i];
	}

	{ // compress
		n = 0;
		for (int i = 1; i <= m; i++) {
			val[n ++] = ring[i].a;
			val[n ++] = ring[i].b;
		}
		sort(val, val + n);
		n = unique(val, val + n) - val;
		for (int i = 1; i <= m; i++) {
			ring[i].a = lower_bound(val, val + n, ring[i].a) - val + 1;
			ring[i].b = lower_bound(val, val + n, ring[i].b) - val + 1;
		}
	}

	for (int i = 1; i <= m; i++) {
		dp[i] = query(ring[i].b) + ring[i].h;
		update(ring[i].a + 1, ring[i].b, dp[i]);
	}

	cout << *max_element(dp, dp + m + 1);
}