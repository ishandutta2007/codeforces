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

const int N = 1e6 + 5;
const int64_t inf = 2e18;

int n, b[N], cnt[65];
int64_t a[N], res;
int p_mx[N], p_mn[N];

void solve(int l, int r) {
	if (l == r)
		return ++ res, (void) 0;
	int m = (l + r) >> 1;
	
	solve(l, m), solve(m + 1, r);

	for (int p = m    , mx = 0, mn = 0; p >= l; p --) {
		if (!mx || a[mx] <  a[p]) mx = p;
		if (!mn || a[mn] >= a[p]) mn = p;
		p_mn[p] = mn, p_mx[p] = mx;
	}

	for (int p = m + 1, mx = 0, mn = 0; p <= r; p ++) {
		if (!mx || a[mx] <= a[p]) mx = p;
		if (!mn || a[mn] >  a[p]) mn = p;
		p_mn[p] = mn, p_mx[p] = mx;
	}

	// min, max -> L, L
	for (int i = m, j = m + 1; i >= l; i --) {
		int mn = p_mn[i], mx = p_mx[i];

		while (j <= r && a[mn] <= a[p_mn[j]] && a[mx] > a[p_mx[j]])
			j ++;
		if (b[mx] == b[mn]) res += j - (m + 1);
	}
	// min, max -> R, R
	for (int i = m, j = m + 1; j <= r; j ++) {
		int mn = p_mn[j], mx = p_mx[j];

		while (i >= l && a[mn] < a[p_mn[i]] && a[mx] >= a[p_mx[i]])
			i --;
		if (b[mx] == b[mn]) res += m - i;
	}
	// min, max -> L, R
	memset(cnt, 0, sizeof cnt);
	for (int i = m, cl = m + 1, cr = m + 1; i >= l; i --) {
		int mx = p_mx[i], mn = p_mn[i];

		while (cr <= r && a[mn] <= a[p_mn[cr]])
			cnt[b[p_mx[cr ++]]] ++;
		while (cl < cr && a[mx] > a[p_mx[cl]])
			cnt[b[p_mx[cl ++]]] --;

		res += cnt[b[mn]];
	}
	// min, max -> R, L
	memset(cnt, 0, sizeof cnt);
	for (int i = m, cl = m + 1, cr = m + 1; i >= l; i --) {
		int mx = p_mx[i], mn = p_mn[i];

		while (cr <= r && a[mx] > a[p_mx[cr]])
			cnt[b[p_mn[cr ++]]] ++;
		while (cl < cr && a[mn] <= a[p_mn[cl]])
			cnt[b[p_mn[cl ++]]] --;

		res += cnt[b[mx]];
	}
}

void solve_case() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], b[i] = __builtin_popcountll(a[i]);
	solve(1, n);

	cout << res;
}