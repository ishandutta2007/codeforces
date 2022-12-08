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

struct Item {
	int l, r, t;
	Item() {}
	Item(int l, int r, int t) : l(l), r(r), t(t) {}
};

struct T {
	vector<int> t, u;
	T() {}
	T(int n) {
		t.resize(4 * n);
		u.resize(4 * n);
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
		if (l >= vr || vl >= r) return;
		if (vl <= l && r <= vr) {
			u[v] += d;
			push(v, l, r);
			return;
		}
		upd(2 * v + 1, l, l + r >> 1, vl, vr, d);
		upd(2 * v + 2, l + r >> 1, r, vl, vr, d);
		t[v] = max(t[2 * v + 1], t[2 * v + 2]);
	}
	int get(int v, int l, int r, int vl, int vr) {
		push(v, l, r);
		if (l >= vr || vl >= r) return 0;
		if (vl <= l && r <= vr) return t[v];
		return max(get(2 * v + 1, l, l + r >> 1, vl, vr), get(2 * v + 2, l + r >> 1, r, vl, vr));
	}
};

const int N = 4e5 + 2;

int dp[N][2];

void solve() {
	int n; cin >> n;
	vector<int> kek;
	vector<Item> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].l >> a[i].r >> a[i].t; a[i].t--;
		kek.push_back(a[i].l);
		kek.push_back(a[i].r);
	}
	sort(all(kek));
	kek.erase(unique(all(kek)), kek.end());
	map<int, int> id;
	for (int i = 0; i < kek.size(); i++)
		id[kek[i]] = i + 1;
	int m = kek.size() + 1;
	vector<vector<Item>> ed(m);
	for (auto& u : a){
		u.l = id[u.l];
		u.r = id[u.r];
		ed[u.r].push_back(u);
	}
	T t0 = T(m);
	T t1 = T(m);
	int ans = 0;
	for (int i = 1; i < m; i++) {
		for (auto u : ed[i]) {
			if (u.t == 0)
				t1.upd(0, 0, m, 0, u.l, 1);
			else
				t0.upd(0, 0, m, 0, u.l, 1);
		}
		dp[i][0] = t1.get(0, 0, m, 0, i);
		dp[i][1] = t0.get(0, 0, m, 0, i);
		ans = max(ans, max(dp[i][0], dp[i][1]));

		t0.upd(0, 0, m, i, i + 1, dp[i][0]);
		t1.upd(0, 0, m, i, i + 1, dp[i][1]);
	}
	cout << ans << endl;
	return;
}