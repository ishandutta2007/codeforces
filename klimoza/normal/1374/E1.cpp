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

#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

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
	int t, a, b;
	Item() {}
	Item(int t, int a, int b) : t(t), a(a), b(b) {}
};

void solve() {
	int n, k; cin >> n >> k;
	vector<Item> a(n);
	vector<int> x, m, y;
	for (int i = 0; i < n; i++) {
		cin >> a[i].t >> a[i].a >> a[i].b;
		if (a[i].a && a[i].b)
			m.push_back(i);
		else if (a[i].a)
			x.push_back(i);
		else if (a[i].b)
			y.push_back(i);
	}
	sort(all(x), [&](int i, int j) {return a[i].t < a[j].t; });
	sort(all(m), [&](int i, int j) {return a[i].t < a[j].t; });
	sort(all(y), [&](int i, int j) {return a[i].t < a[j].t; });
	while (x.size() > k)
		x.pop_back();
	while (y.size() > k)
		y.pop_back();
	while (y.size() > x.size())
		y.pop_back();
	while (x.size() > y.size())
		x.pop_back();
	ll ans = 0;
	int sz = k  - x.size();
	if (sz > m.size()) {
		cout << -1 << endl;
		return;
	}
	for (int i = 0; i < sz; i++)
		ans += a[m[i]].t;
	for (int i = sz; i < m.size(); i++) {
		if (x.empty()) break;
		if (a[m[i]].t < a[x.back()].t + a[y.back()].t) {
			ans += a[m[i]].t;
			x.pop_back();
			y.pop_back();
		}
		else
			break;
	}
	for (int i : x)
		ans += a[i].t;
	for (int i : y)
		ans += a[i].t;
	cout << ans << endl;
	return;
}