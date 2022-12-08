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

mt19937 mrand(43);

const double PI = acos((double)-1);
const double eps = 1e-5;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

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
	vector<int> t, a, u;
	T() {}
	T(vector<int> a) : a(a) {
		t.resize(4 * a.size());
		u.resize(4 * a.size());
		build(0, 0, a.size());
	}
	void build(int v, int l, int r) {
		if (r - l == 1) {
			t[v] = a[l];
			return;
		}
		build(2 * v + 1, l, l + r >> 1);
		build(2 * v + 2, l + r >> 1, r);
		t[v] = min(t[2 * v + 1], t[2 * v + 2]);
	}
	void push(int v, int l, int r) {
		if (!u[v]) return;
		if (r - l == 1) {
			t[v] += u[v];
			u[v] = 0;
			return;
		}
		t[v] += u[v];
		u[2 * v + 1] += u[v];
		u[2 * v + 2] += u[v];
		u[v] = 0;
	}
	void upd(int v, int l, int r, int vl, int vr, int d) {
		push(v, l, r);
		if (vl >= r || l >= vr)
			return;
		if (vl <= l && r <= vr) {
			u[v] += d;
			push(v, l, r);
			return;
		}
		upd(2 * v + 1, l, l + r >> 1, vl, vr, d);
		upd(2 * v + 2, l + r >> 1, r, vl, vr, d);
		t[v] = min(t[2 * v + 1], t[2 * v + 2]);
	}
	int get(int v, int l, int r, int vl, int vr) {
		push(v, l, r);
		if (vl >= r || l >= vr)
			return 2e9;
		if (vl <= l && r <= vr) {
			return t[v];
		}
		return min(get(2 * v + 1, l, l + r >> 1, vl, vr), get(2 * v + 2, l + r >> 1, r, vl, vr));
	}
};

void solve() {
	int n, len, h;
	cin >> n >> len >> h;
	vector<int> b(len);
	vector<int> a(n);
	for (int& i : b) {
		cin >> i;
		i = h - i;
	}
	sort(all(b));
	for (int& i : a) {
		cin >> i;
	}
	vector<int> tmp(len);
	for (int i = 0; i < len; i++)
		tmp[i] = -len + i;
	T t = T(tmp);
	int ans = 0;
	for (int i = 0; i < len; i++) {
		//cout << i << endl;
		int x = upper_bound(all(b), a[i]) - b.begin();
		//cout << i << " " << x << endl;
		//cout << a[i] << " " << x << endl;
		if(x)
			t.upd(0, 0, len, 0, x, 1);
	}
	if (t.get(0, 0, len, 0, len) >= 0)
		ans++;
	//cout << ans << endl;
	for (int i = len; i < n; i++) {
		int x = upper_bound(all(b), a[i - len]) - b.begin();
		if (x)
			t.upd(0, 0, len, 0, x, -1);
		x = upper_bound(all(b), a[i]) - b.begin();
		if (x)
			t.upd(0, 0, len, 0, x, 1);
		if (t.get(0, 0, len, 0, len) >= 0)
			ans++;
	}
	cout << ans << endl;
	return;
}