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
const double eps = 1e-7;
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

struct Tr {
	vector<int> t;
	Tr() {}
	Tr(int n) {
		t.resize(4 * n, inf0);
	}
	void upd(int v, int l, int r, int i, int d) {
		if (i >= r || l > i) return;
		if (r - l == 1) t[v] = d;
		else {
			upd(2 * v + 1, l, l + r >> 1, i, d);
			upd(2 * v + 2, l + r >> 1, r, i, d);
			t[v] = min(t[2 * v + 1], t[2 * v + 2]);
		}
	}
	int get(int v, int l, int r, int vl, int vr) {
		if (vl >= r || l >= vr) return inf0;
		if (vl <= l && r <= vr) return t[v];
		return min(get(2 * v + 1, l, l + r >> 1, vl, vr), get(2 * v + 2, l + r >> 1, r, vl, vr));
	}
};

bool stupid(int n, vector<int> a, int k) {
	if (n == 1 && a[0] == k) return true;
	for (int l = 0; l < n; l++) {
		vector<int> cur = { 0, a[l] };
		for (int r = l + 1; r < n; r++) {
			cur.push_back(a[r]);
			sort(all(cur));
			int len = cur.size();
			if (cur[len / 2] >= k)
				return true;
		}
	}
	return false;
}

bool smart(int n, vector<int> a, int k) {
	int last = -1;
	vector<int> b(n, 0), m(n, 0);
	int f = 2 * n + 1;
	Tr t = Tr(f);
	t.upd(0, 0, f, n, -1);
	bool fl = false;
	for (int i = 0; i < n; i++) {
		if (i) {
			b[i] = b[i - 1];
			m[i] = m[i - 1];
		}
		if (a[i] == k)
			last = i;
		if (a[i] < k)
			m[i]++;
		else
			b[i]++;
		int id;
		if (b[i] - m[i] + n == 0) id = inf0;
		else id = t.get(0, 0, f, 0, b[i] - m[i] + n);
		//cout << i << " " << id << " "  << b[i] - m[i] << endl;
		if (id < (i - 1)) fl = true;
		if (t.get(0, 0, f, b[i] - m[i] + n, b[i] - m[i] + n + 1) == inf0)
			t.upd(0, 0, f, b[i] - m[i] + n, i);
	}
	if ((last != -1 && fl) || (n == 1 && a[0] == k)) return true;
	else return false;
}

void stress() {
	int cnt = 0;
	while (true) {
		cnt++;
		int n = mrand() % 100 + 1;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			a[i] = mrand() % (10) + 1000000000;
		int k = mrand() % 10 + 1000000000;
		bool m1 = smart(n, a, k);
		bool m2 = stupid(n, a, k);
		if (m1 == m2) cout << "TEST# " << cnt << " OK" << endl;
		else {
			cout << "TEST " << cnt << " FAILED\n";
			cout << n << " " << k << endl;
			for (int i : a)
				cout << i << " ";
			cout << endl;
			cout << m1 << " " << m2 << endl;
			return;
		}
	}
}

void solve() {
	//stress(); return;
	int T; cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int& i : a) {
			cin >> i;
		}
		bool ans;
		ans = smart(n, a, k);
		if (ans) cout << "yes\n";
		else cout << "no\n";
	}
	return;
}