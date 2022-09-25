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

int n, m;
vector<pair<pair<int, int>, int> > a;
vector<int> q;

bool reading() {
	if (!(cin >> n >> m)) return 0;
	a.resize(m);
	q.resize(n);
	for (int i = 0; i < m; i++)	scanf("%d%d%d", &a[i].first.first, &a[i].first.second, &a[i].second);
	for (int i = 0; i < n; i++) scanf("%d", &q[i]);
	return 1;
}

void print(vector<int> v) {
	for (int i = 0; i < v.size(); i++) printf("%d\n", v[i]);
}

struct magic {
	magic *l, *r;
	int a, b;

	magic() {l = 0; r = 0; a = 0; b = 0;}
};

typedef magic* pmagic;

pmagic t;

void push(pmagic t, int tl, int tr) {
	if (tl != tr) {
		if (!t->l) t->l = new magic();
		t->l->a += t->a;
		t->l->b += t->b;

		int tm = (tl + tr) >> 1;
		if (!t->r) t->r = new magic();
		t->r->a += t->a;
		t->r->b += t->b + (tm - tl + 1) * t->a;
	}
	t->a = 0;
	if (tl != tr) t->b = 0;
}

void upd(pmagic t, int tl, int tr, int l, int r, int a, int b) {
	if (tr < 0) return;
	push(t, tl, tr);
	if (l > r) return;
	if (l == tl && r == tr) {
		t->a += a;
		t->b += b;
		push(t, tl, tr);
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(t->l, tl, tm, l, min(r, tm), a, b);
	upd(t->r, tm + 1, tr, max(l, tm + 1), r, a, b + (tm - min(l, tm + 1) + 1) * a);
}

int get(pmagic t, int tl, int tr, int x) {
	push(t, tl, tr);
	if (tl == tr) return t->b;
	int tm = (tl + tr) >> 1;
	if (x <= tm) return get(t->l, tl, tm, x);
	else return get(t->r, tm + 1, tr, x);
}

vector<int> fastsolve() {
	t = new magic();
	vector<pair<int, pair<int, int> > > e;
	for (int i = 0; i < m; i++) {
		e.push_back(make_pair(a[i].first.first, make_pair(0, i)));
		e.push_back(make_pair(a[i].first.second, make_pair(1, i)));
	}
	sort(e.begin(), e.end());
	multiset<int> st;
	for (int i = 0; i < e.size(); i++) {
		if (!st.empty()) {
			int L = e[i - 1].first, R = e[i].first;
			if (L != R) {
				int ctime = *st.begin();
				int L1 = ctime - R, R1 = ctime - L; //L1 - first, 0. R1 - first, R-L. 
				upd(t, -1000000002, 1e9, L1, R1, 1, 0);
				upd(t, -1000000002, 1e9, R1+1, 1e9, 0, R-L);
			}
		}

		if (e[i].second.first == 0) {
			st.insert(a[e[i].second.second].second);
		}
		if (e[i].second.first == 1) {
			st.erase(st.lower_bound(a[e[i].second.second].second));
		}
	}
	vector<int> res;
	for (int i = 0; i < n; i++) res.push_back(get(t, -1000000002, 1e9, q[i]));
	return res;
}

vector<int> slowsolve() {
	vector<int> res(n, 0);
	for (int o = 0; o < n; o++) {
		vector<pair<int, pair<int, int> > > e;
		for (int i = 0; i < m; i++) {
			e.push_back(make_pair(a[i].first.first, make_pair(0, i)));
			e.push_back(make_pair(a[i].first.second, make_pair(1, i)));
		}
		sort(e.begin(), e.end());
		multiset<int> st;
		for (int i = 0; i < e.size(); i++) {
			if (!st.empty()) {
				int L = e[i - 1].first, R = e[i].first;
				if (L != R) {
					int ctime = *st.begin();
					int L1 = ctime - R, R1 = ctime - L; //L1 - first, 0. R1 - first, R-L. 
					if (L1 <= q[o]) {
						if (R1 >= q[o]) {
							res[o] += q[o] - L1;
						} else {
							res[o] += R - L;
						}
					}
				}
			}

			if (e[i].second.first == 0) {
				st.insert(a[e[i].second.second].second);
			}
			if (e[i].second.first == 1) {
				st.erase(a[e[i].second.second].second);
			}
		}
	}
	return res;
}

int Rand() {
	return (rand() << 15) + rand();
}

void gen() {
	//n = Rand() % 100 + 1;
	//m = Rand() % 100 + 1;
	n = 200;
	m = 20;
	a.resize(m);
	q.resize(n);
	int mx = 1000;
	for (int i = 0; i < m; i++) {
		a[i].first.first = Rand() % mx;
		a[i].first.second = Rand() % mx;
		if (a[i].first.first > a[i].first.second) swap(a[i].first.first, a[i].first.second);
		a[i].second = Rand() % mx;
	}
	for (int i = 0; i < n; i++) q[i] = Rand() % mx;
}

void stress(bool f) {
	if (!f) return;
	for (int it = 0; it < 10000; it++) {
		gen();
		vector<int> res1 = fastsolve();
		vector<int> res2 = slowsolve();
		if (res1 != res2) {
			cout << n << " " << m << endl;
			for (int i = 0; i < m; i++) cout << a[i].first.first << " " << a[i].first.second << " " << a[i].second << endl;
			for (int i = 0; i < n; i++) cout << q[i] << " \n"[i + 1 == n];
			cout << "________\n";
			for (int i = 0; i < n; i++) cout << res1[i] << " \n"[i + 1 == n];
			cout << "instead of" << endl;
			for (int i = 0; i < n; i++) cout << res2[i] << " \n"[i + 1 == n];
			cout << it << endl;
			break;
		}
		cerr << it << endl;
	}
	exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	stress(0);
	while (reading()) print(fastsolve());

	return 0;
}