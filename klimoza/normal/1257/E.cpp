#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
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

#define endl '\n'
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
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

int idr(int i, vector<int>& p, vector<int> &a) {
	if (a[i] == p[2]) return -1;
	else if (a[i] == p[1]) return 1;
	else return 0;
}

int idl(int i, vector<int>& p, vector<int>& a) {
	if (a[i] == p[0]) return -1;
	else if (a[i] == p[1]) return 1;
	else return 0;
}

struct T {
	vector<int> t;
	vector<int> a;
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
		build(2 * v + 1, l, (l + r) / 2);
		build(2 * v + 2, (l + r) / 2, r);
		t[v] = min(t[2 * v + 1], t[2 * v + 2]);
	}
	int get(int v, int l, int r, int vl, int vr) {
		if (vl >= r || l >= vr) return 0;
		if (vl <= l && r <= vr) return t[v];
		return min(get(2 * v + 1, l, (l + r) / 2, vl, vr), get(2 * v + 2, (l + r) / 2, r, vl, vr));
	}
};

void solve() {
	int k1, k2, k3; cin >> k1 >> k2 >> k3;
	int n = k1 + k2 + k3;
	vector<int> a(n);
	for (int i = 0; i < k1; i++) {
		int t; cin >> t; t--; 
		a[t] = 1;
	}
	for (int i = 0; i < k2; i++) {
		int t; cin >> t; t--;
		a[t] = 2;
	}
	for (int i = 0; i < k3; i++) {
		int t; cin >> t; t--;
		a[t] = 3;
	}
	vector<int> p = { 1, 2, 3 };
	ll ans = inf;
	ll f = 0;
	for (int i : a) f += (i != p[1]);
	ans = min(ans, f);
	vector<int> r(n);
	r[n - 1] = idr(n - 1, p, a);
	for (int i = n - 2; i >= 0; i--) r[i] = r[i + 1] + idr(i, p, a);
	T t = T(r);
	ans = min(ans, f + min(0, t.get(0, 0, n, 0, n)));
	for (int i = 0; i < n; i++) {
		f += idl(i, p, a);
		ans = min(ans, f + t.get(0, 0, n, i + 1, n));
	}
	cout << ans << endl;
}