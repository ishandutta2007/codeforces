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

//#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<double> cd;
typedef vector<complex<double>> vcd;

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

struct Item {
	int l, v, r;
	Item() {}
	Item(int l, int v, int r) : l(l), v(v), r(r) {}
};

struct T {
	vector<pair<int, int>> t;
	vector<int> u;
	T() {}
	T(int n) {
		t.resize(4 * n);
		u.resize(4 * n);
		build(0, 0, n);
	}
	void build(int v, int l, int r) {
		if (r - l == 1) {
			t[v] = { 0, l };
			return;
		}
		build(2 * v + 1, l, l + r >> 1);
		build(2 * v + 2, l + r >> 1, r);
		t[v] = max(t[2 * v + 1], t[2 * v + 2]);
	}
	void push(int v, int l, int r) {
		if (!u[v]) return;
		if (r - l == 1) {
			t[v].first += u[v];
			u[v] = 0;
			return;
		}
		u[2 * v + 1] += u[v];
		u[2 * v + 2] += u[v];
		t[v].first += u[v];
		u[v] = 0;
	}
	void upd(int v, int l, int r, int vl, int vr, int d) {
		push(v, l, r);
		if (vl >= r || l >= vr) return;
		if (vl <= l && r <= vr) {
			u[v] += d;
			push(v, l, r);
			return;
		}
		upd(2 * v + 1, l, l + r >> 1, vl, vr, d);
		upd(2 * v + 2, l + r >> 1, r, vl, vr, d);
		t[v] = max(t[2 * v + 1], t[2 * v + 2]);
	}
	pair<int ,int> get(int v, int l, int r, int vl, int vr) {
		push(v, l, r);
		if (vl >= r || l >= vr) return { 0, 0 };
		if (vl <= l && r <= vr)
			return t[v];
		return max(get(2 * v + 1, l, l + r >> 1, vl, vr), get(2 * v + 2, l + r >> 1, r, vl, vr));
	}
};

const int N = 3e5 + 1;

vector<pair<int, int>> kek[N];
vector<pair<int, int>> mem[N];

void solve() {
	int n; cin >> n;
	vector<Item> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].l >> a[i].v >> a[i].r;
		kek[a[i].l].push_back({ a[i].v, a[i].r });
		mem[a[i].v].push_back({ a[i].v, a[i].r });
	}
	T t = T(N);
	int ans = 0;
	int ll = 0;
	int tt = 0;
	for (int i = 1; i < N; i++) {
		for (auto u : mem[i - 1])
			t.upd(0, 0, N, u.first, u.second + 1, -1);
		for(auto u : kek[i])
			t.upd(0, 0, N, u.first, u.second + 1, 1);
		pair<int, int> x = t.get(0, 0, N, 0, N);
		if (x.first > ans) {
			ans = x.first;
			ll = i;
			tt = x.second;
		}
	}
	cout << ans << endl;
	for(int i = 0 ;i < n ;i++){
		Item u = a[i];
		if (u.l <= ll && ll <= u.v && u.v <= tt && tt <= u.r)
			cout << i + 1 << " ";
	}
	return;
}