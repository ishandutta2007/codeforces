#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

#define size(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

using namespace std;

typedef long long ll;

const ll inf0 = 2 * 1024 * 1024 * 1023;
const ll inf = inf0 * inf0;
const double eps = 1e-6;
const ll mod = 998244353;

mt19937 mrand(random_device{} ());


struct Tree {
	vector<pair<int, int>> t;
	Tree(int n) {
		t.assign(4 * n, { inf0, inf0 });
		build(0, 0, n);
	}
	void build(int v, int l, int r) {
		if (r - l == 1) {
			t[v] = { inf0, l };
			return;
		}
		build(2 * v + 1, l, (l + r) / 2);
		build(2 * v + 2, (l + r) / 2, r);
		t[v] = min(t[2 * v + 1], t[2 * v + 2]);
	}
	void upd(int v, int l, int r, int i, int x) {
		if (i >= r || i < l) return;
		if (r - l == 1) {
			t[v].first = x;
			return;
		}
		upd(2 * v + 1, l, (l + r) / 2, i, x);
		upd(2 * v + 2, (l + r) / 2, r, i, x);
		t[v] = min(t[2 * v + 1], t[2 * v + 2]);
	}
	pair<int, int> get(int v, int l, int r, int vl, int vr) {
		if (vl >= r || l >= vr) return { inf0, inf0 };
		if (vl <= l && r <= vr) return t[v];
		return min(get(2 * v + 1, l, (l + r) / 2, vl, vr), get(2 * v + 2, (l + r) / 2, r, vl, vr));
	}
};


struct Query {
	int x, y, id;
	Query() {}
	Query(int _x, int _y, int _id) : x(_x), y(_y), id(_id) {}
};

const int N = 5e5 + 7;

signed main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout.precision(15);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif	
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int m; cin >> m;
	vector<Query> qu(m);
	for (int i = 0; i < m; i++) {
		cin >> qu[i].x >> qu[i].y; qu[i].x--; qu[i].y--;
		qu[i].id = i;
	}
	Tree t = Tree(n);
	sort(all(qu), [](Query a, Query b) {return a.y < b.y; });
	int f = 0;
	vector<int> tmp(N, -1);
	vector<int> an(m, 0);
	for (int i = 0; i < n; i++) {
		if (tmp[a[i]] != -1)
			t.upd(0, 0, n, tmp[a[i]], n);
		t.upd(0, 0, n, i, tmp[a[i]]);
		while (f < m && qu[f].y == i) {
			pair<int, int> ans = t.get(0, 0, n, qu[f].x, qu[f].y + 1);
			if (ans.first < qu[f].x) {
				an[qu[f].id] = a[ans.second];
			}
			f++;
		}
		if (f == m) break;
		tmp[a[i]] = i;
	}
	for (int i : an) cout << i << endl;
	return 0;
}