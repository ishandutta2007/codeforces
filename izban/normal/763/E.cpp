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

const int MAXK = -1;
const int MAXN = 1 << 17;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

int n, k, m;
vector<int> e[MAXN];
int q;
int ql[MAXN], qr[MAXN];

struct item {
	int comp;
	vector<int> p;
	vector<int> id;

	item() {
		comp = 0;
		p.clear();
		id.clear();
	}
	item(int cid) {
		comp = 1;
		p.assign(1, 0);
		id.assign(1, cid);
	}
};

int get(vector<int> &p, int x) {
	if (p[x] == x) return x;
	return p[x] = get(p, p[x]);
}

item merge(const item &a, const item &b) {
	item res;
	res.comp = a.comp + b.comp;
	res.p = a.p;
	res.id = a.id;
	for (int i = 0; i < (int)b.p.size(); i++) {
		res.p.push_back(b.p[i] + a.p.size());
		res.id.push_back(b.id[i]);
	}

	if (a.p.size() == 0 || b.p.size() == 0) return res;
	for (int i = (int)a.p.size(); i < (int)res.p.size(); i++) {
		for (int to : e[b.id[i - (int)a.p.size()]]) {
			if (to < b.id[0] && to >= a.id[0]) {
				int u = get(res.p, i - (res.id[i] - to));
				int v = get(res.p, i);
				if (u != v) {
					res.comp--;
					res.p[v] = u;
				}
			}
		}
	}
	if (res.p.size() > 2 * k) {
		for (int i = 0; i < (int)res.p.size(); i++) {
			get(res.p, i);
		}
		for (int i = 0; i < k; i++) {
			int x = get(res.p, i);
			if (x >= k && x + k < (int)res.p.size()) {
				res.p[i] = i;
				res.p[x] = i;
			}
		}		
		for (int i = (int)res.p.size() - k; i < (int)res.p.size(); i++) {
			int x = get(res.p, i);
			if (x >= k && x + k < (int)res.p.size()) {
				res.p[i] = i;
				res.p[x] = i;
			}
		}

		int subtracted = (int)res.p.size() - 2 * k;
		vector<int> np, nid;
		for (int i = 0; i < k; i++) {
			int x = get(res.p, i);
			if (x >= k) x -= subtracted;
			np.push_back(x);
			nid.push_back(res.id[i]);
		}
		for (int i = (int)res.p.size() - k; i < (int)res.p.size(); i++) {
			int x = get(res.p, i);
			if (x >= k) x -= subtracted;
			np.push_back(x);
			nid.push_back(res.id[i]);
		}
		res.p = np;
		res.id = nid;
	}
	return res;
}

item t[MAXN * 2];

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = item(tl);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

item get(int v, int tl, int tr, int l, int r) {
	if (l > r) return item();
	if (l == tl && r == tr) return t[v];
	int tm = (tl + tr) >> 1;
	item a1 = get(v * 2, tl, tm, l, min(r, tm));
	item a2 = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	item res = merge(a1, a2);
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) e[i].clear();
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		--v; --u;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &ql[i], &qr[i]);
		--ql[i];
		--qr[i];
	}

	build(1, 0, n - 1);

	for (int i = 0; i < q; i++) {
		auto o = get(1, 0, n - 1, ql[i], qr[i]);
		printf("%d\n", o.comp);
	}

	return 0;
}