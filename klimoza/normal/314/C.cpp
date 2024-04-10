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

const int N = 1e5 + 7;

int sub(int a, int b) {
	a -= b;
	if (a < 0) a += mod;
	return a;
}

int add(int a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

int mul(int a, int b) {
	return a * b % mod;
}


struct T {
	vector<int> t;
	T() {}
	T(int n) {
		t.resize(4 * n);
	}
	void upd(int v, int l, int r, int i, int d) {
		if (r <= i || l > i) return;
		if (r - l == 1) {
			t[v] = add(t[v], d);
			return;
		}
		upd(2 * v + 1, l, l + r >> 1, i, d);
		upd(2 * v + 2, l + r >> 1, r, i, d);
		t[v] = (t[2 * v + 1] + t[2 * v + 2]) % mod;
	}
	int get(int v, int l, int r, int vl, int vr) {
		if (vl >= r || l >= vr) return 0;
		if (vl <= l && r <= vr) return t[v];
		return (get(2 * v + 1, l, l + r >> 1, vl, vr) + get(2 * v + 2, l + r >> 1, r, vl, vr)) % mod;
	}
};

const int K = 1e6 + 5;

int sm[K];

void solve() {
	fill(sm, sm + K, 0);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> dp(n);
	T t = T(K);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		dp[i] = mul((t.get(0, 0, K, 0, a[i] + 1) + 1), a[i]);
		dp[i] = sub(dp[i], sm[a[i]]);
		ans = add(ans, dp[i]);
		sm[a[i]] = add(sm[a[i]], dp[i]);
		t.upd(0, 0, K, a[i], dp[i]);
	}
	cout << ans << endl;
	return;
}