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
	vector<int> a, u;
	vector<pair<int, int>> t;
	T() {}
	T(vector<int> a) : a(a){
		t.resize(4 * a.size());
		u.resize(4 * a.size(), 0);
		build(0, 0, a.size());
	}
	void build(int v, int l, int r) {
		if (r - l == 1) {
			t[v] = { a[l], l };
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
	pair<int, int> get(int v, int l, int r, int vl, int vr) {
		push(v, l, r);
		if (vl >= r || l >= vr) return { -inf0, -inf0 };
		if (vl <= l && r <= vr) return t[v];
		return max(get(2 * v + 1, l, l + r >> 1, vl, vr), get(2 * v + 2, l + r >> 1, r, vl, vr));
	}
};

const int N = 3e5 + 7;

int p[N];

int getp(int v) {
	if (p[v] == v) return v;
	return p[v] = getp(p[v]);
}

int tt[N];

void upd(int i) {
	for (; i < N; i = (i | (i + 1)))
		tt[i]++;
}

int get(int r) {
	int res = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		res += tt[r];
	return res;
}

void solve() {
	fill(tt, tt + N, 0);
	fill(p, p + N, -2);
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		b[i] = a[i] - i;
		if (b[i] > 0) b[i] = -inf0;
		//cout << b[i] << " ";
	}
	//cout << endl;
	T t = T(b);
	set<int> id;
	int last = -1;
	while (true) {
		pair<int, int> v = t.get(0, 0, n, 0, n);
		//cout << v.first << " " << v.second << " kek" << endl;
		if (v.first == 0) {
			p[v.second] = last;
			if (last == -1) p[v.second] = v.second;
			id.insert(v.second);
			t.upd(0, 0, n, v.second, v.second + 1, -inf0);
			continue;
		}
		if (id.empty()) break;
		last = *id.rbegin();
		id.erase(last);
		t.upd(0, 0, n, last, n, 1);
	}
	vector<vector<int>> kek(n);
	for (int i = 0; i < n; i++) {
		if (p[i] == -2) continue;
		getp(i);
		kek[p[i]].push_back(i);
	}
	//for (int i = 0; i < n; i++) 	cout << p[i] << " " << i << endl;
	for (int i = 0; i < n; i++)
		sort(all(kek[i]));
	vector<int> ans(q);
	vector<vector<pair<int, int>>> qu(n);
	for (int i = 0; i < q; i++) {
		int x, y; cin >> x >> y;
		qu[x].push_back({ n - y - 1, i });
	}
	//upd(12); cout << get(12) << " Mem " << endl;
	for (int i = n - 1; i >= 0; i--) {
		for (auto u : kek[i]) {
			upd(u);
		}
		for (auto u : qu[i]) {
			ans[u.second] = get(u.first);
		}
	}
	for (int i : ans)
		cout << i << endl;
	return;
}