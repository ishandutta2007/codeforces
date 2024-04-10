#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct upit {
	int l, r, id;
	bool operator< (const upit& b) const {
		int al = l >> 8, bl = b.l >> 8;
		if (al != bl)
			return al < bl;
		return r < b.r;
	}
};

int n, q;
int a[200005], c[1000005];
upit b[200005];
ll sum, ans[200005];
int ml, mr;

void add(int i) {
	c[a[i]]++;
	sum += a[i] * (2 * c[a[i]] - 1ll);
}

void rem(int i) {
	sum -= a[i] * (2 * c[a[i]] - 1ll);
	c[a[i]]--;
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
		b[i].id = i;
	}
	sort(b, b+q);
	for (int i=0; i<q; i++) {
		while (mr < b[i].r)
			add(++mr);
		while (ml > b[i].l)
			add(--ml);
		while (mr > b[i].r)
			rem(mr--);
		while (ml < b[i].l)
			rem(ml++);
		ans[b[i].id] = sum;
	}
	for (int i=0; i<q; i++)
		cout << ans[i] << '\n';
}