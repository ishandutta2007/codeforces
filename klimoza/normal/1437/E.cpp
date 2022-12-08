/*#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC target("avx2")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <deque>
#include <bitset>
#include <string>
#include <queue>
#include <complex>
#include <stack>
#include <ctime>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());
//mt19937 mrand(228);

const double PI = acos((double)-1);
const double eps = 1e-5;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 7;
const ll mod = 998244353;

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
struct T {
	vector<int> t, u, a;
	int n;
	T() {}
	T(int n) : n(n) {
		t.resize(4 * n, -inf0);
		u.resize(4 * n, inf0);
		//build(0, 0, a.size());
	}
	void build(int v, int l, int r) {
		if (r - l == 1) {
			t[v] = a[l];
			return;
		}
		build(2 * v + 1, l, l + r >> 1);
		build(2 * v + 2, l + r >> 1, r);
		t[v] = max(t[2 * v + 1], t[2 * v + 2]);
	}
	void push(int v, int l, int r) {
		if (u[v] == inf0) return;
		if (r - l == 1) {
			t[v] = u[v];
			u[v] = inf0;
			return;
		}
		u[2 * v + 1] = u[v];
		u[2 * v + 2] = u[v];
		t[v] = u[v];
		u[v] = inf0;
	}
	void upd(int v, int l, int r, int vl, int vr, int d) {
		push(v, l, r);
		if (l >= vr || r <= vl) return;
		if (vl <= l && r <= vr) {
			u[v] = d;
			push(v, l, r);
			return;
		}
		upd(2 * v + 1, l, l + r >> 1, vl, vr, d);
		upd(2 * v + 2, l + r >> 1, r, vl, vr, d);
		t[v] = max(t[2 * v + 1], t[2 * v + 2]);
	}
	int get(int v, int l, int r, int vl, int vr) {
		push(v, l, r);
		if (l >= vr || r <= vl) return -inf0;
		if (vl <= l && r <= vr) return t[v];
		return max(get(2 * v + 1, l, l + r >> 1, vl, vr), get(2 * v + 2, l + r >> 1, r, vl, vr));
	}

};

void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	n++;
	reverse(all(a));
	a.push_back(-inf0);
	reverse(all(a));
	vector<bool> bad(n, false);
	for (int i = 0; i < k; i++) {
		int x; cin >> x;
		bad[x] = true;
	}
	bad[0] = true;
	vector<pair<int, int>> b(n);
	for (int i = 0; i < n; i++) {
		a[i] = a[i] - i;
		b[i] = { a[i], i };
	}
	T t = T(n);
	sort(all(b));
	a[b[0].second] = 0;
	for (int i = 1; i < n; i++) {
		a[b[i].second] = a[b[i - 1].second];
		if (b[i].first != b[i - 1].first)
			a[b[i].second]++;
	}
	for (int i = 0; i < n; i++) {
		if (!i) {
			t.upd(0, 0, n, 0, 1, 1);
			continue;
		}
		int kek = t.get(0, 0, n, 0, a[i] + 1);
		//cout << kek << endl;
		if (!bad[i]) {
			if (kek == -inf0) continue;
			t.upd(0, 0, n, a[i], a[i] + 1, kek + 1);
		}
		else {
			if (kek == -inf0) {
				cout << -1 << endl;
				return;
			}
			t.upd(0, 0, n, 0, n, -inf0);
			t.upd(0, 0, n, a[i], a[i] + 1, kek + 1);
		}
		//cout << i << " " << t.get(0, 0, n, 0, n) << endl;
	}
	int ans = t.get(0, 0, n, 0, n);
	if (ans < k) cout << -1 << endl;
	else cout << (n - ans) << endl;
	return;
}