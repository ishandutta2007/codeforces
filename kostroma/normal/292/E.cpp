//MIPT Ababahalamaha
#pragma comment (linker, "/STACK:128000000")
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <map>
#include <cassert>
#include <memory.h>
#include <sstream>
#include <memory>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long long i64;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

int main() {
#ifdef LocalTechCourse
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	clock_t start = clock(); 
#else

#endif
	cout.sync_with_stdio(0);
	cout.precision(10);
	cout << fixed;
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
#ifdef LocalTechCourse
	cerr<<"\n\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
	return 0;
}


struct _node {
	int cnt;
	const int val;
	_node* l;
	_node* r;
	_node(int val):val(val), cnt(1) { 
		l = r = NULL;
	}

	_node (const _node& v):cnt(v.cnt), val(v.val), l(v.l), r(v.r) {}

	void recalc() {
		cnt = 1;
		if (l) {
			cnt += l->cnt;
		}
		if (r) {
			cnt += r->cnt;
		}
	}

};

typedef _node* node;

int Cnt (node v) {
	return (v == NULL) ? 0 : v->cnt;
}

node mergeUsual(node l, node r) {
	if (!l)
		return r;
	if (!r)
		return l;
	int num = rand() % (Cnt(l) + Cnt(r));
	if (num < Cnt(l)) {
		l->r = mergeUsual(l->r, r);
		l->recalc();
		return l;
	}
	else {
		r->l = mergeUsual(l, r->l);
		r->recalc();
		return r;
	}
}

node merge(const node l, const node r) {
	if (!l)
		return r;
	if (!r)
		return l;
	int num = rand() % (Cnt(l) + Cnt(r));
	if (num < Cnt(l)) {
		node newRoot = new _node(*l);
		newRoot->r = merge(newRoot->r, r);
		newRoot->recalc();
		return newRoot;
	}
	else {
		node newRoot = new _node(*r);
		newRoot->l = merge(l, newRoot->l);
		newRoot->recalc();
		return newRoot;
	}
}

void split(node v, int key, node& l, node& r) {
	l = r = NULL;
	if (!v)
		return;
	int leftCnt = (v->l == NULL) ? 0 : v->l->cnt;
	if (leftCnt < key) {
		l = new _node(*v);
		split(l->r, key - leftCnt - 1, l->r, r);
		l->recalc();
	}
	else {
		r = new _node(*v);
		split(r->l, key, l, r->l);
		r->recalc();
	}
}

int getVal(node v, int pos) {
	node l, m, r;
	split(v, pos, l, m);
	split(m, 1, m, r);
	assert(m != NULL && m->cnt == 1);
	int res = m->val;
	return res;
}


void solve() {
	int n, m;
	cin >> n >> m;

	node a = NULL, b = NULL;

	for (int i = 0; i < n; ++i) {
		int cur;
		cin >> cur;
		a = mergeUsual(a, new _node(cur));
	}
	for (int i = 0; i < n; ++i) {
		int cur;
		cin >> cur;
		b = mergeUsual(b, new _node(cur));
	}

	while(m--) {
		int type;
		cin >> type;
		if (type == 1) {
			int x, y, k;
			cin >> x >> y >> k;
			--x; --y;

			node la, ma, ra;
			split(a, x, la, ma);
			split(ma, k, ma, ra);

			node lb, mb, rb;
			split(b, y, lb, mb);
			split(mb, k, mb, rb);

			b = mergeUsual(mergeUsual(lb, ma), rb);
		}
		else {
			int x;
			cin >> x;
			--x;
			cout << getVal(b, x) << "\n";
		}
	}

}