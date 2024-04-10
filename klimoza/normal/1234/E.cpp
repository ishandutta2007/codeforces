#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <deque>
#include <bitset>
#include <string>
#include <complex>

#define int long long

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-6;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;

void solve();
void scan();

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

struct Tree {
	vector<int> ar;
	vector<int> upd;
	Tree() {}
	Tree(vector<int> ar) : ar(ar) {
		upd.resize(4 * ar.size(), 0);
	}
	void push(int v, int l, int r) {
		if (!upd[v]) return;
		if (r - l == 1) {
			ar[l] += upd[v];
			upd[v] = 0;
			return;
		}
		upd[2 * v + 1] += upd[v];
		upd[2 * v + 2] += upd[v];
		upd[v] = 0;
	}
	void add(int v, int l, int r, int vl, int vr, int d) {
		push(v, l, r);
		if (vl >= r || vr <= l) return;
		if (vl <= l && r <= vr) {
			upd[v] += d;
			push(v, l, r);
			return;
		}
		add(2 * v + 1, l, (l + r) / 2, vl, vr, d);
		add(2 * v + 2, (l + r) / 2, r, vl, vr, d);
	}
	int get(int v, int l, int r, int i) {
		push(v, l, r);
		if (i >= r || i < l) return -1;
		if (r - l == 1) return ar[l];
		return max(get(2 * v + 1, l, (l + r) / 2, i), get(2 * v + 2, (l + r) / 2, r, i));
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> x(m);
	for (int i = 0; i < m; i++) cin >> x[i];
	vector<int> ar(n);
	Tree t = Tree(ar);
	for (int i = 0; i < m - 1; i++) {
		int u = x[i] - 1;
		int v = x[i + 1] - 1;
		if (u > v) swap(u, v);
		if (u == v) continue;
		t.add(0, 0, n, 0, u, v - u);
		t.add(0, 0, n, u, u + 1, v);
		t.add(0, 0, n, u + 1, v, v - u - 1);
		t.add(0, 0, n, v, v + 1, u + 1);
		t.add(0, 0, n, v + 1, n, v - u);
	}
	for (int i = 0; i < n; i++) {
		cout << t.get(0, 0, n, i) << " ";
	}
	cout << endl;
}