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

struct T {
	vector<ll> ts, tx, u, a;
	vector<pair<ll, int>> tm;
	T() {}
	T(vector<ll> a) : a(a) {
		ts.resize(4 * a.size());
		tm.resize(4 * a.size(), mp(0, 0));
		tx.resize(4 * a.size());
		u.resize(4 * a.size(), -inf);
		build(0, 0, a.size());
	}
	void build(int v, int l, int r) {
		if (r - l == 1) {
			ts[v] = a[l];
			tm[v] = mp(a[l], l);
			tx[v] = a[l];
			return;
		}
		build(2 * v + 1, l, l + r >> 1);
		build(2 * v + 2, l + r >> 1, r);
		ts[v] = ts[2 * v + 1] + ts[2 * v + 2];
		tm[v] = min(tm[2 * v + 1], tm[2 * v + 2]);
		tx[v] = max(tx[2 * v + 1], tx[2 * v + 2]);
	}
	void push(int v, int l, int r) {
		if (u[v] == -inf) return;
		if (r - l == 1) {
			ts[v] = (r - l) * 1ll * u[v];
			tm[v].first = u[v];
			tx[v] = u[v];
			u[v] = -inf;
			return;
		}
		tx[v] = u[v];
		u[2 * v + 1] = u[2 * v + 2] = tm[v].first = u[v];
		ts[v] = (r - l) * 1ll * u[v];
		u[v] = -inf;
	}
	void upd(int v, int l, int r, int vl, int vr, ll d) {
		push(v, l, r);
		if (vl >= r || l >= vr) return;
		if (vl <= l && r <= vr) {
			u[v] = d;
			push(v, l, r);
			return;
		}
		upd(2 * v + 1, l, l + r >> 1, vl, vr, d);
		upd(2 * v + 2, l + r >> 1, r, vl, vr, d);
		ts[v] = ts[2 * v + 1] + ts[2 * v + 2];
		tm[v] = min(tm[2 * v + 1], tm[2 * v + 2]);
		tx[v] = max(tx[2 * v + 1], tx[2 * v + 2]);
	}
	ll getS(int v, int l, int r, int vl, int vr) {
		push(v, l, r);
		if (vl >= r || l >= vr) return 0;
		if (vl <= l && r <= vr) return ts[v];
		return getS(2 * v + 1, l, l + r >> 1, vl, vr) + getS(2 * v + 2, l + r >> 1, r, vl, vr);
	}
	ll getM(int v, int l, int r, int vl, int vr) {
		push(v, l, r);
		if (vl >= r || l >= vr) return inf;
		if (vl <= l && r <= vr) return tm[v].first;
		return min(getS(2 * v + 1, l, l + r >> 1, vl, vr), getS(2 * v + 2, l + r >> 1, r, vl, vr));
	}
	pair<ll, int> ask1(int v, int l, int r, int vl, int vr, int d) {
		push(v, l, r);
		if (vl >= r || l >= vr) return { -inf, -1 };
		if (tm[v].first > d) return { -inf, -1 };
		if (r - l == 1) return tm[v];
		pair<ll, int> kek = ask1(2 * v + 1, l, l + r >> 1, vl, vr, d);
		if (kek.first == -inf) return ask1(2 * v + 2, l + r >> 1, r, vl, vr, d);
		return kek;
	}
	pair<ll, int> ask2(int v, int l, int r, int vl, int vr, int d) {
		push(v, l, r);
		if (vl >= r || l >= vr) return mp(0, l);
		if (vl <= l && r <= vr && ts[v] <= d) {
			return mp(ts[v], r);
		}
		if (vl <= l && tx[v] > d) return mp(0, l);
		if ((l + r >> 1) > vl) {
			pair<ll, int> a1 = ask2(2 * v + 1, l, l + r >> 1, vl, vr, d);
			if (a1.second != (l + r >> 1)) return a1;
			pair<ll, int> a2 = ask2(2 * v + 2, l + r >> 1, r, vl, vr, d - a1.first);
			return mp(a1.first + a2.first, a2.second);
		}
		return ask2(2 * v + 2, l + r >> 1, r, vl, vr, d);
	}
};

T t;

int n;

pair<ll, int> get(int l, int r, int d) {
	return t.ask1(0, 0, n, l, r, d);
}

void query1(int x, int d) {
	pair<ll, int> kek = get(0, x + 1, d);
	if (kek.second == -1) return;
	t.upd(0, 0, n, kek.second, x + 1, d);
	//cout << t.getS(0, 0, n, 0, 2) << endl;
}

int query2(int x, int y) {
	int s = 0;
	while (x < n) {
		//cout << x << endl;
		if (t.getS(0, 0, n, x, n) <= y) {
			s += n - x;
			break;
		}
		else if (t.getS(0, 0, n, x, x + 1) > y) {
			pair<ll, int> kek = get(x, n, y);
			if (kek.first == -inf) break;
			x = kek.second;
		}
		else {
			pair<ll, int> l = t.ask2(0, 0, n, x, n, y);
			s += l.second - x;
			y -= t.getS(0, 0, n, x, l.second);
			x = l.second;
		}
	}
	return s;
}

void solve() {
	int q; cin >> n >> q;
	vector<ll> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	t = T(a);
	//cout << t.getS(0, 0, n, 0, n) << endl;
	while (q--) {
		int tp, x, y; cin >> tp >> x >> y;
		x--;
		if (tp == 1) {
			query1(x, y);
			//cout << t.getS(0, 0, n, 0, 5) << endl;
		}
		else {
			cout << query2(x, y) << endl;
		}
	}
	return;
}