#pragma optimise('O3');
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 1e9 + 7;

struct Tree {
	vector<int> tree;
	vector<int> ar;
	vector<int> add;

	Tree() {}
	Tree(vector<int> _ar) {
		ar = _ar;
		tree.resize(4 * ar.size());
		add.resize(4 * ar.size());
		build(0, 0, ar.size());
	}

	void build(int pos, int l, int r) {	
		if (r - l == 1) {
			tree[pos] = ar[l];
			return;
		}
		build(2 * pos + 1, l, (l + r) / 2);
		build(2 * pos + 2, (l + r) / 2, r);
		
		tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
	}

	void push(int pos, int l, int r) {
		if (!add[pos]) return;
		if (r - l == 1) {
			tree[pos] += add[pos];
			add[pos] = 0;
			return;
		}
		add[2 * pos + 1] += add[pos];
		add[2 * pos + 2] += add[pos];
		tree[pos] += add[pos];
		add[pos] = 0;
	}

	void add_seg(int pos, int l, int r, int vl, int vr, int delta) {
		push(pos, l, r);
		if (l >= vr || vl >= r) {
			return;
		}
		if (vl <= l && r <= vr) {
			add[pos] += delta;
			push(pos, l, r);
			return;
		}
		add_seg(2 * pos + 1, l, (l + r) / 2, vl, vr, delta);
		add_seg(2 * pos + 2, (l + r) / 2, r, vl, vr, delta);
		tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
	}

	int get_max(int pos, int l, int r, int vl, int vr) {
		push(pos, l, r);

		if (l >= vr || vl >= r) {
			return -INFi;
		}
		if (vl <= l && r <= vr) {
			return tree[pos];
		}
		return max(get_max(2 * pos + 1, l, (l + r) / 2, vl, vr), get_max(2 * pos + 2, (l + r) / 2, r, vl, vr));
	}

};



int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<pair<int, int>> b(m);
	vector<vector<pair<int, int>>> beg(n);
	vector<vector<pair<int, int>>> end(n + 1);
	int t1, t2;
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2;
		t1--; t2--;
		b[i] = { t1, t2 };
		beg[t1].push_back({ t1, t2 });
		end[t2 + 1].push_back({ t1, t2 });
	}
	int ans = -INFi;
	int cur = -1;
	Tree tree = Tree(a);
	for (int i = 0; i < n; i++) {
		for (auto j : beg[i]) {
			tree.add_seg(0, 0, n, j.first, j.second + 1, -1);
		}
		for (auto j : end[i]) {
			tree.add_seg(0, 0, n, j.first, j.second + 1, 1);
		}
		int f1 = tree.get_max(0, 0, n, 0, n);
		//cout << i << endl;
		int f2 = tree.get_max(0, 0, n, i, i + 1);
		if (f1 - f2 > ans) {
			ans = f1 - f2;
			cur = i;
		}
	}
	vector<int> an;
	for (int i = 0; i < m; i++) {
		if (b[i].first <= cur && cur <= b[i].second) an.push_back(i);
	}
	cout << ans << endl;
	cout << an.size() << endl;
	for (int i : an) cout << i + 1 << " ";
	cout << endl;
	//system("pause");
	return 0;
}