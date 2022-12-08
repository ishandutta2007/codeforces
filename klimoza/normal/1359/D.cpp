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

struct T {
	vector<int> a, t;
	T() {}
	T(vector<int> a) : a(a) {
		t.resize(4 * a.size(), -inf0);
		build(0, 0, a.size());
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
	int get(int v, int l, int r, int vl, int vr) {
		if (vl >= r || l >= vr) return -inf0;
		if (vl <= l && r <= vr) return t[v];
		return max(get(2 * v + 1, l, l + r >> 1, vl, vr), get(2 * v + 2, l + r >> 1, r, vl, vr));
	}
};

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	vector<int> p(n), s(n);
	p[0] = a[0];
	for (int i = 1; i < n; i++)
		p[i] = p[i - 1] + a[i];
	s[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
		s[i] = s[i + 1] + a[i];
	vector<int> nxt(n, n);
	vector<int> prv(n, -1);
	vector<pair<int, int>> kek;
	for (int i = 0; i < n; i++) {
		while (!kek.empty() && kek.back().first <= a[i])
			kek.pop_back();
		if (!kek.empty())
			prv[i] = kek.back().second;
		kek.push_back({ a[i], i });
	}
	kek.clear();
	for (int i = n - 1; i >= 0; i--) {
		while (!kek.empty() && kek.back().first <= a[i])
			kek.pop_back();
		if (!kek.empty())
			nxt[i] = kek.back().second;
		kek.push_back({ a[i], i });
	}
	kek.clear();
	T tp = T(p);
	T ts = T(s);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int f1 = tp.get(0, 0, n, i, nxt[i]);
		int f2 = ts.get(0, 0, n, prv[i] + 1, i + 1);
		ans = max(ans, f1 + f2 - p[i] - s[i]);
	}
	cout << ans << endl;
	return;
}