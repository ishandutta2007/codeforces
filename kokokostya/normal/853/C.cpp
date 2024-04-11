#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>

using namespace std;

#define LOCAL

int n, q;
vector<int> p;

struct vert{
	int l, r, u, ind;
};

bool comp(vert a, vert b) {
	return a.u < b.u || (a.u == b.u && a.ind < b.ind);
}

vector<int> t;

void update(int v, int tl, int tr, int pos) {
	if (tl == tr)
		t[v]++;
	else {
		int tm = (tl + tr) >> 1;
		if (pos <= tm)
			update(v << 1, tl, tm, pos);
		else
			update((v << 1) | 1, tm + 1, tr, pos);
		t[v] = t[v << 1] + t[(v << 1) | 1];
	}
	return;
}

int get(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (tl == l && tr == r)
		return t[v];
	int tm = (tl + tr) >> 1;
	return get(v << 1, tl, tm, l, min(r, tm)) + get((v << 1) | 1, tm + 1, tr, max(l, tm + 1), r);
}

int main() {
	ios_base::sync_with_stdio(false);
#ifndef LOCAL
	freopen("testbrain.in", "r", stdin);
	freopen("testbrain.out", "w", stdout);
#endif
	cin >> n >> q;
	p.resize(n);
	t.resize(4 * n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}
	vector<vert> a, b;
	vector<long long> ans(q, (n * 1ll * (n - 1)) / 2);
	for (int i = 0; i < q; i++) {
		int l, r, d, u;
		cin >> l >> d >> r >> u;
		l--; r--; d--; u--;
		a.push_back({ 0, n - 1, d - 1, 3 * i });
		a.push_back({ 0, l - 1, d - 1, 3 * i + 1 });
		a.push_back({ r + 1, n - 1, d - 1, 3 * i + 2 });

		b.push_back({ 0, n - 1, u + 1, 3 * i });
		b.push_back({ 0, l - 1, u + 1, 3 * i + 1 });
		b.push_back({ r + 1, n - 1, u + 1, 3 * i + 2 });

		ans[i] -= ((l - 1) * 1ll * (l)) / 2;
		long long len = (n - (r + 1));
		ans[i] -= ((len - 1) * 1ll * (len)) / 2;
	}
	sort(a.begin(), a.end(), comp);
	sort(b.rbegin(), b.rend(), comp);
	int pos = 0;
	vector< pair<int, int> > c(n);
	for (int i = 0; i < n; i++)
		c[i] = { p[i], i };
	sort(c.begin(), c.end());
	pos = 0;
	for (int i = 0; i < 3 * q; i++) {
		while (pos < n && c[pos].first <= a[i].u) {
			update(1, 0, n - 1, c[pos].second);
			pos++;
		}

		int val = get(1, 0, n - 1, a[i].l, a[i].r);
		if (a[i].ind % 3 == 0)
			ans[a[i].ind / 3] -= (val * 1ll * (val - 1)) / 2;
		else
			ans[a[i].ind / 3] += (val * 1ll * (val - 1)) / 2;
	}
	t.assign(4 * n, 0);
	pos = n - 1;
	for (int i = 0; i < 3 * q; i++) {
		while (pos >= 0 && c[pos].first >= b[i].u) {
			update(1, 0, n - 1, c[pos].second);
			pos--;
		}
		int val = get(1, 0, n - 1, b[i].l, b[i].r);
		if (b[i].ind % 3 == 0)
			ans[b[i].ind / 3] -= (val * 1ll * (val - 1)) / 2;
		else
			ans[b[i].ind / 3] += (val * 1ll * (val - 1)) / 2;
	}
	for (long long i : ans)
		cout << i << '\n';
	return 0;
}