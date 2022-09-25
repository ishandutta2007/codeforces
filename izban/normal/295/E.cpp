#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

struct item {
	int key, prior, cnt;
	ll sum, ans;
	item *l, *r;

	item() {}
};

typedef item * pitem;

/* **+++++**
+++**MAGIC**+++
   **+++++** */

int cnt(pitem t) {
	return t ? t->cnt : 0;
}

ll sum(pitem t) {
	return t ? t->sum : 0;
}

ll ans(pitem t) {
	return t ? t->ans : 0;
}

void push(pitem t) {
	if (t) {
		t->cnt = 1 + cnt(t->l) + cnt(t->r);
		t->sum = t->key + sum(t->l) + sum(t->r);
		t->ans = 0;
		t->ans += ans(t->l) + ans(t->r);
		t->ans += sum(t->r) * cnt(t->l) - sum(t->l) * cnt(t->r);
		t->ans += sum(t->r) - (ll)cnt(t->r) * t->key;
		t->ans += (ll)cnt(t->l) * t->key - sum(t->l);
	}
}

void merge(pitem &t, pitem l, pitem r) {
	if (!l || !r) t = l ? l : r;
	else if (l->prior > r->prior) merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;
	push(t);
}

void split(pitem t, pitem &l, pitem &r, int key) {
	if (!t) return void(l = r = 0);
	if (t->key > key) split(t->l, l, t->l, key), r = t;
	else split(t->r, t->r, r, key), l = t;
	push(t);
}

/* **+++++**
+++**MAGIC**+++
   **+++++** */

int n, m, x[maxn], p[maxn];
item a[maxn];
pitem t;

int Rand() {
	return (rand() << 15) + rand();
}

bool cmp(int i, int j) {
	return x[i] < x[j];
}

void print(pitem t) {
	if (!t) return;
	print(t->l);
	cout << t->key << " ";
	print(t->r);
	push(t);	
}

void gen(bool f) {
	if (!f) return;
	n = 10; cout << n << endl;
	for (int i = 0; i < n; i++) x[i] = Rand() % (int)2e9 - 1e9, cout << x[i] << " \n"[i + 1 == n];
	m = 1000; cout << m << endl;
	for (int i = 0; i < m; i++) {
		int tp, l, r;
		tp = rand() % 2 + 1;
		if (tp == 1) {
			l = rand() % n + 1;
			r = rand() % 2000 - 1000;
		}
		if (tp == 2) {
			l = Rand() % (int)1e9 - 5e8;
			r = Rand() % (int)1e9 - 5e8;
			if (l > r) swap(l, r);
		}
		cout << tp << " " << l << " " << r << endl;
	}

	exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	gen(0);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &x[i]), p[i] = i;
	sort(p, p + n, cmp);
	for (int i = 0; i < n; i++) {
		a[i].key = x[p[i]];
		a[i].cnt = 1;
		a[i].prior = Rand();
		a[i].sum = a[i].key;
		merge(t, t, &a[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int tp, l, r;
		scanf("%d%d%d", &tp, &l, &r);
		if (tp == 1) {
			pitem t1 = 0, t2 = 0, t3 = 0, t4 = 0;
			split(t, t1, t2, x[l - 1] - 1);
			split(t2, t2, t3, x[l - 1]);
			merge(t, t1, t3);
			t2->key += r; t2->sum += r; x[l - 1] += r;
			split(t, t1, t3, t2->key);
			merge(t, t1, t2);
			merge(t, t, t3);
		}
		if (tp == 2) {
			pitem t1 = 0, t2 = 0, t3 = 0;
			split(t, t1, t2, l - 1);
			split(t2, t2, t3, r);
			cout << ans(t2) << endl;
			merge(t, t1, t2);
			merge(t, t, t3);
		}
	}

	return 0;
}