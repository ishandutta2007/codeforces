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
	int n;
	vector<int> t, u;
	T() {}
	T(int n) : n(n) {
		t.assign(4 * n, 0);
		u.assign(4 * n, 0);
	}
	void push(int v, int l, int r) {
		if (!u[v]) return;
		if (r - l == 1) {
			t[v] = t[v] ^ u[v];
			//cout << l << " " << r << " " << t[v] << endl;
			u[v] = 0;
			return;
		}
		u[2 * v + 1] = u[2 * v + 1] ^ u[v];
		u[2 * v + 2] = u[2 * v + 2] ^ u[v];
		t[v] = t[v] ^ u[v];
		u[v] = 0;
	}
	void al() {
		push(0, 0, n);
		u[0] = u[0] ^ 1;
		push(0, 0, n);
	}
	void upd(int v, int l, int r, int i) {
		push(v, l, r);
		if (r <= i || l > i) return;
		if (r - l == 1) {
			t[v] = t[v] ^ 1;
			return;
		}
		upd(2 * v + 1, l, l + r >> 1, i);
		upd(2 * v + 2, l + r >> 1, r, i);
	}
	int get(int v, int l, int r, int i) {
		push(v, l, r);
		//cout << v << " " << l << " " << r << " " << i << endl;
		if (r <= i || l > i) return 0;
		if (r - l == 1) return t[v];
		return get(2 * v + 1, l, l + r >> 1, i) ^ get(2 * v + 2, l + r >> 1, r, i);
	}
};

struct Item {
	int l, r;
	int id;

	int vl, vr;
	ll val = -1;
	Item() {}
	Item(int l, int r) : l(l), r(r) {}
};

const int N = 19;
const int K = 1 << N;

int n;

int sz[N];

T rv[N], sw[N];

Item it[1 << 19];

int cur = 0;

int a[1 << 18];

void ex() {
	cout << -1 << endl;
	exit(0);
}

int build(int l, int r, int v=  0) {
	if (cur >= (1 << 19)) {
		ex();
	}
	int id = cur;
	it[cur] = Item(l, r);
	it[cur].id = v;
	cur++;
	if (r - l == 1) {
		it[id].val = a[l];
		return id;
	}
	int id1 = build(l, l + r >> 1, 2 * v);
	int id2 = build(l + r >> 1, r, 2 * v + 1);
	it[id].vl = id1;
	it[id].vr = id2;
	it[id].val = it[it[id].vl].val + it[it[id].vr].val;
	//cout << id << " " << l << " " << r << " " << it[id].val << endl;
	return id;
}

void push(int v, int vv, int k){
	if (!k) return;
	//cout << v << " " << k << " WHAAT\n";
	//cout << k << " " << sz[k] << endl;
	//if (k == 1) cout << v <<" srat"<< " " << rv[k].get(0, 0, sz[k], v) << endl;
	if (k && rv[k].get(0, 0, sz[k], v)) {
		rv[k - 1].upd(0, 0, sz[k - 1], 2 * v);
		rv[k - 1].upd(0, 0, sz[k - 1], 2 * v + 1);
		rv[k].upd(0, 0, sz[k], v);
		swap(it[vv].vl, it[vv].vr);
	}
	if (k && sw[k].get(0, 0, sz[k], v)) {
		//cout << "lol\n";
		sw[k].upd(0, 0, sz[k], v);
		swap(it[vv].vl, it[vv].vr);
	}
}

void upd(int v, int k, int l, int r, int i, int d) {
	//cout << v << " " << l << " " << r << endl;
	push(it[v].id, v, k);
	if (!k) {
		it[v].val = d;
		return;
	}
	if (i < ((l + r) >> 1))
		upd(it[v].vl, k - 1, l, l + r >> 1, i, d);
	else
		upd(it[v].vr, k - 1, l + r >> 1, r, i, d);
	it[v].val = it[it[v].vl].val + it[it[v].vr].val;
}

ll get(int v, int k, int l, int r, int vl, int vr) {
	push(it[v].id, v, k);
	//cout << v << " " << k << " " << l << " " << r << endl;
	if (l >= vr || vl >= r) return 0;
	if (vl <= l && r <= vr) {
		//cout << l << " " << r << " " << it[v].val << endl;
		return it[v].val;
	}
	return get(it[v].vl, k - 1, l, l + r >> 1, vl, vr) + get(it[v].vr, k - 1, l + r >> 1, r, vl, vr);
}

void solve() {
	int q; cin >> n >> q;
	for (int i = 0; i < (1 << n); i++)
		cin >> a[i];
	for (int i = 0; i <= n; i++) {
		sz[i] = (1 << (n - i));
		//cout << i << " " << sz[i] << endl;
	}
	for (int i = 0; i <= n; i++) {
		rv[i] = T(sz[i]);
		sw[i] = T(sz[i]);
	}
	build(0, 1 << n);
	//cout << it[0].vl << " " << it[0].vr << endl; cout << it[8].vl << " " << it[8].vr << endl;
	while (q--) {
		//cout << q << " kek " << endl;
		int tp; cin >> tp;
		if (tp == 2) {
			int k; cin >> k;
			rv[k].al();
			//cout << rv[k].get(0, 0, sz[k], 4) << endl;
		}
		else if (tp == 3) {
			int k; cin >> k;
			sw[k + 1].al();
			//cout << sw[k + 1].get(0, 0, sz[k + 1], 0) << " mem\n"; return;
		}
		else if (tp == 1) {
			int x, k; cin >> x >> k;
			upd(0, n, 0, 1 << n, x - 1, k);
		}
		else {
			int l, r; cin >> l >> r; l--;
			cout << get(0, n, 0, 1 << n, l, r) << endl;
		}
		//cout << it[0].vl << " " << it[0].vr << endl; cout << it[8].vl << " " << it[8].vr << endl;
	}
	return;
}