#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <list>
#include <bitset>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int m;

struct vec {
	int a[2];

	vec() {
		a[0] = a[1] = 0;
	}

	vec operator+ (const vec& o) const {
		vec tmp;
		tmp.a[0] = a[0] + o.a[0];
		if (tmp.a[0] >= m) {
			tmp.a[0] -= m;
		}
		tmp.a[1] = a[1] + o.a[1];
		if (tmp.a[1] >= m) {
			tmp.a[1] -= m;
		}
		return tmp;
	}
};

struct mat {
	int a[2][2];

	mat operator* (const mat& o) const {
		mat tmp;
		tmp.a[0][0] = 0;
		tmp.a[0][1] = 0;
		tmp.a[1][0] = 0;
		tmp.a[1][1] = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					tmp.a[i][k] += a[i][j] * o.a[j][k];
				}
			}
		}
		tmp.a[0][0] %= m;
		tmp.a[0][1] %= m;
		tmp.a[1][0] %= m;
		tmp.a[1][1] %= m;
		return tmp;
	}

	vec operator* (const vec& o) const {
		vec tmp;
		tmp.a[0] = 0;
		tmp.a[1] = 0;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				tmp.a[i] += a[i][j] * o.a[j];
			}
		}

		tmp.a[0] %= m;
		tmp.a[1] %= m;
		return tmp;
	}
};

struct upit {
	int l, r, i;

	bool operator< (const upit& b) const {
		if ((l >> 7) != (b.l >> 7)) {
			return l < b.l;
		}
		return r < b.r;
	}
};

mat F[30005]; // stepeni Fib matrice

struct fib_node {
	int cnt;
	vec sum;

	fib_node() : cnt(0) {}

	fib_node operator+ (const fib_node& o) const {
		fib_node tmp;
		tmp.cnt = cnt + o.cnt;
		tmp.sum = sum + F[cnt] * o.sum;
		return tmp;
	}
};

const int N = 32768;

struct segtree {
	vector<fib_node> a;

	segtree() : a(2 * N) {}

	fib_node get(int l, int r, int x, int xl, int xr) {
		if (xr < l || r < xl) {
			return fib_node();
		}
		if (l <= xl && xr <= r) {
			return a[x];
		}
		int xm = (xl + xr) >> 1;
		return get(l, r, 2 * x, xl, xm)
			+ get(l, r, 2 * x + 1, xm + 1, xr);
	}

	void set(int x, fib_node val) {
		x += N - 1;
		a[x] = val;
		while (x > 1) {
			x >>= 1;
			a[x] = a[2 * x] + a[2 * x + 1];
		}
	}
};

segtree drvo;

int n, q;
int a[30005];
int sorted_pos[30005];
int c[30005];
upit b[30005];
int ans[30005];

void add(int i) {
	int x = sorted_pos[i];
	c[x]++;
	if (c[x] != 1) {
		return;
	}
	fib_node tmp;
	tmp.sum.a[0] = a[i];
	tmp.sum.a[1] = 0;
	tmp.sum = F[1] * tmp.sum;
	tmp.cnt = 1;
	drvo.set(x, tmp);
}

void rem(int i) {
	int x = sorted_pos[i];
	c[x]--;
	if (c[x] != 0) {
		return;
	}
	drvo.set(x, fib_node());
}

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	F[0].a[0][0] = 1;
	F[0].a[1][1] = 1;
	F[1].a[0][0] = 1;
	F[1].a[0][1] = 1;
	F[1].a[1][0] = 1;

	for (int i = 2; i <= n + 1; i++) {
		F[i] = F[i - 1] * F[1];
	}

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	{
		map<int, int> mp;
		for (int i = 1; i <= n; i++) {
			mp[a[i]] = 0;
		}
		int j = 0;
		for (auto& p : mp) {
			p.second = ++j;
		}
		for (int i = 1; i <= n; i++) {
			sorted_pos[i] = mp[a[i]];
		}
	}

	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> b[i].l >> b[i].r;
		b[i].i = i;
	}

	int ml = 1, mr = 0;

	sort(b + 1, b + q + 1);
	for (int i = 1; i <= q; i++) {
		int l = b[i].l;
		int r = b[i].r;
		while (mr < r) add(++mr);
		while (ml > l) add(--ml);
		while (mr > r) rem(mr--);
		while (ml < l) rem(ml++);

		ans[b[i].i] = drvo.a[1].sum.a[1];
	}

	for (int i = 1; i <= q; i++) {
		cout << ans[i] << '\n';
	}
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}