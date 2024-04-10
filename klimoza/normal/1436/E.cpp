//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
//#pragma GCC target("avx2")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
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
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
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
	vector<pair<int, int>> t;
	T() {}
	T(int n) {
		t.resize(4 * n, mp(-1, -1));
		build(0, 0, n);
	}
	void build(int v, int l, int r) {
		if (r - l == 1) {
			t[v] = mp(-1, l);
			return;
		}
		build(2 * v + 1, l, l + r >> 1);
		build(2 * v + 2, l + r >> 1, r);
		t[v] = min(t[2 * v + 1], t[2 * v + 2]);
	}
	void upd(int v, int l, int r, int id, int d) {
		if (id >= r || l > id) return;
		if (r - l == 1) {
			t[v] = mp(d, l);
			return;
		}
		upd(2 * v + 1, l, l + r >> 1, id, d);
		upd(2 * v + 2, l + r >> 1, r, id, d);
		t[v] = min(t[2 * v + 1], t[2 * v + 2]);
	}
	/*int get(int v, int l, int r, int vl, int vr) {
		if (vl >= r || l >= vr) return inf0;
		if (vl <= l && r <= vr) return t[v];
		return min(get(2 * v + 1, l, l + r >> 1, vl, vr), get(2 * v + 2, l + r >> 1, r, vl, vr));
	}*/
	pair<int, int> qu(int v, int l, int r, int d) {
		if (t[v].first >= d) return mp(inf0, inf0);
		if (r - l == 1)
			return t[v];
		pair<int, int> kek = qu(2 * v + 1, l, l + r >> 1, d);
		if (kek.first != inf0) return kek;
		return qu(2 * v + 2, l + r >> 1, r, d);
	}
};

struct Query {
	int l, r;
	Query() {}
	Query(int l, int r) : l(l), r(r) {}
};

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	vector<Query> q;
	vector<int> id(n + 1, -1);
	for (int i = 0; i < n; i++) {
		int l = id[a[i]] + 1;
		int r = i - 1;
		if (l <= r)
			q.push_back(Query(l, r));
		id[a[i]] = i;
	}
	for (int i = 0; i <= n; i++) {
		int l = id[i] + 1;
		int r = n - 1;
		if (l <= r)
			q.push_back(Query(l, r));
	}
	q.push_back(Query(0, n - 1));
	sort(all(q), [](Query a, Query b) {return a.r < b.r; });
	int j = 0;
	set<int> kek;
	//cout << "lol\n";
	T t = T(n + 1);
	for (int i = 0; i < n; i++) {
		t.upd(0, 0, n + 1, a[i], i);
		while (j < q.size() && q[j].r == i) {
			//cout << q[j].l << " " << q[j].r << endl;
			auto f = t.qu(0, 0, n + 1, q[j].l);
			//cout << f.second << endl;
			if (f.first == inf0)
				kek.insert(n + 1);
			else
				kek.insert(f.second);
			j++;
		}
	}
	for (int i = 0; i <= n + 2; i++) {
		if (kek.find(i) == kek.end()) {
			cout << i + 1 << endl;
			return;
		}
	}
	return;
}