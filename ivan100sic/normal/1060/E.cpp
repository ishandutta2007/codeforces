#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int N = 262144;

struct node {
	ll cnt_even, cnt_odd;
	ll sum_even, sum_odd, lazy;

	ll val() {
		return (sum_even + sum_odd + cnt_odd) >> 1;
	}

	node operator+ (const node& b) const {
		node tmp = *this;
		tmp.cnt_even += b.cnt_even;
		tmp.cnt_odd += b.cnt_odd;
		tmp.sum_even += b.sum_even;
		tmp.sum_odd += b.sum_odd;
		tmp.lazy = 0;
		return tmp;
	}

	node() : sum_even(0), sum_odd(0), cnt_even(1), cnt_odd(0), lazy(0) {}

	node(int) : sum_even(0), sum_odd(0), cnt_even(0), cnt_odd(0), lazy(0) {}
};

struct lst {
	vector<node> a;

	lst() : a(2 * N) {}

	void push(int x) {
		if (!a[x].lazy) {
			return;
		}

		if (x < N) {
			a[2 * x].lazy += a[x].lazy;
			a[2 * x + 1].lazy += a[x].lazy;
		}

		a[x].sum_even += a[x].cnt_even * a[x].lazy;
		a[x].sum_odd += a[x].cnt_odd * a[x].lazy;

		if (a[x].lazy % 2) {
			swap(a[x].sum_even, a[x].sum_odd);
			swap(a[x].cnt_even, a[x].cnt_odd);
		}

		a[x].lazy = 0;
	}

	node get(int l, int r, int x, int xl, int xr) {
		push(x);
		if (xr < l || r < xl) {
			return node(0);
		}
		if (l <= xl && xr <= r) {
			return a[x];
		}
		int xm = (xl + xr) >> 1;
		return get(l, r, 2 * x, xl, xm)
			+ get(l, r, 2 * x + 1, xm + 1, xr);
	}

	void update(int l, int r, int y, int x, int xl, int xr) {
		if (xr < l || r < xl) {
			push(x);
			return;
		}
		if (l <= xl && xr <= r) {
			a[x].lazy += y;
			push(x);
			return;
		}
		push(x);
		int xm = (xl + xr) >> 1;
		update(l, r, y, 2 * x, xl, xm);
		update(l, r, y, 2 * x + 1, xm + 1, xr);
		a[x] = a[2 * x] + a[2 * x + 1];
	}
} drvo;

ll sol = 0;

int n;
int l[200005], r[200005], t;
vector<int> e[200005];
int d[200005];

void dfs1(int x, int p) {
	l[x] = ++t;
	for (int y : e[x]) {
		if (y != p) {
			d[y] = d[x] + 1;
			dfs1(y, x);
		}
	}
	r[x] = t;
}

void dfs2(int x, int p) {
	sol += drvo.get(1, n, 1, 1, N).val();
	for (int y : e[x]) {
		if (y != p) {
			drvo.update(l[y], r[y], -2, 1, 1, N);
			drvo.update(1, n, 1, 1, 1, N);
			dfs2(y, x);
			drvo.update(1, n, -1, 1, 1, N);
			drvo.update(l[y], r[y], 2, 1, 1, N);
		}
	}
}

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}

	dfs1(1, 1);

	for (int i = 1; i <= n; i++) {
		drvo.update(l[i], l[i], d[i], 1, 1, N);
	}
	
	dfs2(1, 1);

	cout << sol / 2 << '\n';
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}