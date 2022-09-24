#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;
#ifdef _MSC_VER
const int MAXN = 1 << 8;
#else
const int MAXN = 1 << 19;
#endif
const ll INF = 1e18;

int n;
int a[MAXN];
int q;
int tt[MAXN], l[MAXN], r[MAXN], k[MAXN];

void print(vector<int> a) {
	for (int x : a) printf("%d\n", x);
}

struct segtree {
	ll t[MAXN * 2];
	ll p[MAXN * 2];

	segtree() {
		memset(t, 0, sizeof(t));
		memset(p, 0, sizeof(p));
	}

	void push(int v, int tl, int tr) {
		if (tl != tr) {
			p[v * 2] += p[v];
			p[v * 2 + 1] += p[v];
		}
		t[v] += p[v];
		p[v] = 0;
	}
	
	void add(int v, int tl, int tr, int l, int r, ll x) {
		push(v, tl, tr);
		if (l > r) return;
		if (l == tl && r == tr) {
			p[v] += x;
			push(v, tl, tr);
			return;
		}
		int tm = (tl + tr) >> 1;
		add(v * 2, tl, tm, l, min(r, tm), x);
		add(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
		t[v] = min(t[v * 2], t[v * 2 + 1]);
	}

	void add(int l, int r, ll x) {
		add(1, 0, MAXN - 1, l, r, x);
	}

	ll get(int v, int tl, int tr, int l, int r) {
		push(v, tl, tr);
		if (l > r) return INF;
		if (l == tl && r == tr) return t[v];
		int tm = (tl + tr) >> 1;
		return min(get(v * 2, tl, tm, l, min(r, tm)), get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
	}

	ll getMin(int l, int r) {
		return get(1, 0, MAXN - 1, l, r);
	}

	void print(int v, int tl, int tr, int l, int r) {
		push(v, tl, tr);
		if (l > r) return;
		if (tl == tr) {
			cerr << t[v] << " ";
			return;
		}
		int tm = (tl + tr) >> 1;
		print(v * 2, tl, tm, l, min(r, tm));
		print(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	}

	void print(int n) {
		print(1, 0, MAXN - 1, 0, n);
		cerr << endl;
	}
};

int x[MAXN];

vector<int> solve() {
	x[0] = 0;
	for (int i = 0; i < n; i++) {
		x[i + 1] = a[i] - (i ? x[i] : 0);
	}
	// x[i] = a[i - 1] - a[i - 2] + ...

	segtree t1;
	for (int i = 0; i < n; i++) {
		t1.add(i, i, a[i]);
	}
	
	segtree t2, t3;
	for (int i = 0; i <= n; i++) {
		if (i % 2 == 0) {
			t2.add(i, i, x[i]);
			t3.add(i, i, INF);
		}
		else {
			t2.add(i, i, INF);
			t3.add(i, i, x[i]);
		}
	}
	vector<int> res;
	for (int i = 0; i < q; i++) {
		if (tt[i] == 1) {
			segtree *tt1, *tt2;
			// tt1[l[i] + 1] -- ok
			if (l[i] % 2 == 0) {
				tt1 = &t3;
				tt2 = &t2;
			}
			else {
				tt1 = &t2;
				tt2 = &t3;
			}

			tt1->add(l[i] + 1, r[i] + 1, k[i]);
			if (l[i] % 2 == r[i] % 2) {
				tt1->add(r[i] + 2, n, k[i]);
				tt2->add(r[i] + 2, n, -k[i]);
			}
			t1.add(l[i], r[i], k[i]);
		}
		if (tt[i] == 2) {
			if (l[i] == r[i]) {
				ll x = t1.getMin(l[i], r[i]);
				res.push_back(x == 1);
			}
			else {
				bool ok = 1;
				segtree *tt1, *tt2;
				if (l[i] % 2 == 0) {
					tt1 = &t3;
					tt2 = &t2;
				}
				else {
					tt1 = &t2;
					tt2 = &t3;
				}
				ll sub = tt2->getMin(l[i], l[i]);
				ok &= t1.getMin(l[i], l[i]) > 0;
				ll last = t1.getMin(r[i], r[i]);
				ll prev = r[i] % 2 == 0 ? t2.getMin(r[i], r[i]) : t3.getMin(r[i], r[i]);
				if (r[i] % 2 == l[i] % 2) prev -= sub;
				else prev += sub;
				ok &= last == prev + (r[i] - l[i] + 1) % 2;
				//t2.print(n + 1);
				//t3.print(n + 1);
				ok &= tt1->getMin(l[i] + 1, r[i] + 1) + sub >= 1;// (r[i] - l[i] + 1) % 2;
				ok &= tt2->getMin(l[i] + 1, r[i] + 1) - sub >= 0;// (r[i] - l[i] + 1) % 2;
				res.push_back(ok);
			}
		}
	}
	return res;
}

vector<int> slow() {
	for (int i = 0; i < n; i++) x[i] = a[i];
	vector<int> ans;
	for (int i = 0; i < q; i++) {
		if (tt[i] == 1) {
			for (int j = l[i]; j <= r[i]; j++) x[j] += k[i];
		}
		if (tt[i] == 2) {
			bool ok = 1;
			if (l[i] == r[i]) {
				ok = x[l[i]] == 1;
			}
			else {
				int cur = x[l[i]] - 1;
				ok = x[l[i]] >= 1;
				for (int j = l[i] + 1; j <= r[i]; j++) {
					ok &= x[j] >= cur + 1;
					cur = x[j] - (cur + 1);
				}
				ok &= cur == 0;
			}
			ans.push_back(ok);
		}
	}
	return ans;
}

void stress() {
	const int T = 5;
	for (int it = 0;; it++) {
		cerr << it << endl;
		srand(it);

		n = rand() % 100 + 1;
		for (int i = 0; i < n; i++) a[i] = rand() % T;
		q = rand() % 100 + 1;
		for (int i = 0; i < q; i++) {
			tt[i] = rand() % 2 + 1;
			l[i] = rand() % n;
			r[i] = rand() % n;
			k[i] = rand() % T;
			if (r[i] < l[i]) swap(l[i], r[i]);
		}
		auto ans1 = solve();
		auto ans2 = slow();
		if (ans1 != ans2) {
			cout << endl;
			print(ans1);
			cout << "instead of" << endl;
			print(ans2);
			cout << endl;
			cout << n << endl;
			for (int i = 0; i < n; i++) cout << a[i] << " ";
			cout << endl;
			cout << q << endl;
			for (int i = 0; i < q; i++) {
				cout << tt[i] << " " << l[i] << " " << r[i] << " ";
				if (tt[i] == 1) cout << k[i];
				cout << endl;
			}
			solve();
			slow();
			exit(0);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	//stress();

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d%d%d", &tt[i], &l[i], &r[i]);
		if (tt[i] == 1) scanf("%d", &k[i]);
	}
	print(solve());

	return 0;
}