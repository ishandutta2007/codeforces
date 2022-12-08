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

const int N = 1e5 + 1;

int t[N];

int get(int i) {
	int res = 0;
	for (; i >= 0; i = ((i & (i + 1)) - 1)) {
		res += t[i];
	}
	return res;
}

int get(int l, int r) {
	return get(r) - get(l - 1);
}

void upd(int i, int d) {
	for (; i < N; i = (i | (i + 1)))
		t[i] += d;
}

struct T {
	vector<int> t, a;
	T() {}
	T(vector<int> a) : a(a) {
		t.resize(4 * a.size());
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
	void upd(int v, int l, int r, int i, int d) {
		if (l > i || r <= i) return;
		if (r - l == 1) {
			t[v] = d;
			return;
		}
		upd(2 * v + 1, l, l + r >> 1, i, d);
		upd(2 * v + 2, l + r >> 1, r, i, d);
		t[v] = min(t[2 * v + 1], t[2 * v + 2]);
	}
	int get(int v, int l, int r, int vl, int vr) {
		if (vl >= r || l >= vr) return 2e9;
		if (vl <= l && r <= vr) return t[v];
		return min(get(2 * v + 1, l, l + r >> 1, vl, vr), get(2 * v + 2, l + r >> 1, r, vl, vr));
	}
};

void solve() {
	fill(t, t + N, 0);
	int m; cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; i++)
		cin >> b[i];
	int q; cin >> q;
	vector<int> ans(q);
	vector<pair<int, int>> qu(q);
	for (int i = 0; i < q; i++) {
		cin >> qu[i].first >> qu[i].second;
		qu[i].first--; qu[i].second--;
	}
	vector<vector<int>> tt(m);
	for (int i = 0; i < q; i++) {
		tt[qu[i].second].push_back(i);
	}
	map<int, int> p;
	vector<int> prv(m);
	vector<int> pp(m, -1);
	T t = T(prv);
	map<int, int> kek;
	for (int i = 0; i <m; i++) {
		if (kek.find(b[i]) == kek.end()) {
			prv[i] = -1;
		}
		else {
			if (pp[kek[b[i]]] == -1)
				prv[i] = -1;
			else if (kek[b[i]] - pp[kek[b[i]]] != i - kek[b[i]])
				prv[i] = pp[kek[b[i]]];
			else
				prv[i] = prv[kek[b[i]]];
			pp[i] = kek[b[i]];
			t.upd(0, 0, m, pp[i], 2e9);
		}
		kek[b[i]] = i;
		t.upd(0, 0, m, i, prv[i]);
		upd(i, 1);
		if (p.find(b[i]) != p.end())
			upd(p[b[i]], -1);
		p[b[i]] = i;
		for (int j : tt[i]) {
			ans[j] = get(qu[j].first, qu[j].second) + 1;
			//cout << qu[j].first << " " << qu[j].second << " " << ans[j] << endl;
			if (t.get(0, 0, m, qu[j].first, qu[j].second + 1) < qu[j].first)
				ans[j]--;
		}
	}
	for (int i = 0; i < q; i++)
		cout << ans[i] << endl;
	return;
}