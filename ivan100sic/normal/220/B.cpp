#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct upit {
	int l, r, i;
	bool operator< (const upit& b) const {
		int x = l >> 8;
		int y = b.l >> 8;
		if (x != y)
			return x < y;
		return r < b.r;
	}
};

static int n, q;
static int a[100005];
static int c[100005], ml = 1, mr = 0, mx;
static int ans[100005];
static upit b[100005];

static inline void dod(int i) {
	if (a[i] > n)
		return;
	int& x = ++c[a[i]];
	if (x == 0)
		mx++;
	else if (x == 1)
		mx--;
}

static inline void rem(int i) {
	if (a[i] > n)
		return;
	int& x = --c[a[i]];
	if (x == 0)
		mx++;
	else if (x == -1)
		mx--;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=0; i<q; i++) {
		cin >> b[i].l >> b[i].r;
		b[i].i = i;
	}
	for (int i=1; i<=n; i++)
		c[i] = -i;
	sort(b, b+q);
	for (int i=0; i<q; i++) {
		int tl = b[i].l;
		int tr = b[i].r;
		while (mr < tr) dod(++mr);
		while (ml > tl) dod(--ml);
		while (mr > tr) rem(mr--);
		while (ml < tl) rem(ml++);
		ans[b[i].i] = mx;
	}
	for (int i=0; i<q; i++)
		cout << ans[i] << '\n';
}