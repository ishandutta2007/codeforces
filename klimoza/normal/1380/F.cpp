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

mt19937 mrand(239);

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

const int N = 1e6;

int s[N];

int c[100];

ll mul(ll a, ll b) {
	return a * b % mod;
}

ll add(ll a, ll b) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

int stupid(int l, int r) {
	//cout << l << " " << r << endl;
	vector<int> dp(r - l + 1);
	dp[0] = 1;
	for (int i = 0; i < (r - l); i++) {
		int x = dp[i];
		if(i + 1 <= (r - l))
			dp[i + 1] = add(dp[i + 1], mul(x, c[s[i + l]]));
		if (i + 2 <= (r - l) && s[i + l])
			dp[i + 2] = add(dp[i + 2], mul(x, c[s[i + l] * 10 + s[i + l + 1]]));
		//cout << i << " " << dp[i] << "  KEK\n";
	}
	return dp.back();
}

void merge(vector<int> &a, vector<int> &b, vector<int> &res, int l, int r) {
	int m = l + r >> 1;
	vector<int> ans;
	for (int i = 0; i < 4; i++) {
		int x = i & 1;
		int y = i & 2;
		res[i] = mul(a[x + 2], b[y + 1]);
		if (s[m - 1])
			res[i] = add(res[i], mul(mul(a[x], b[y]), c[s[m - 1] * 10 + s[m]]));
	}
}

struct T {
	vector<vector<int>> t;
	T() {}
	T(int n) {
		t.resize(4 * n);
		for (int i = 0; i < 4 * n; i++)
			t[i].resize(4);
		build(0, 0, n);
	}
	void build(int v, int l, int r) {
		if (r - l <= 4) {
			t[v][0] = stupid(l + 1, r - 1);
			t[v][1] = stupid(l, r - 1);
			t[v][2] = stupid(l + 1, r);
			t[v][3] = stupid(l, r);
			return;
		}
		build(2 * v + 1, l, l + r >> 1);
		build(2 * v + 2, l + r >> 1, r);
		merge(t[2 * v + 1], t[2 * v + 2], t[v], l, r);
	}
	void upd(int v, int l, int r, int i) {
		if (l > i || r <= i) return;
		if (r - l <= 4) {
			t[v][0] = stupid(l + 1, r - 1);
			t[v][1] = stupid(l, r - 1);
			t[v][2] = stupid(l + 1, r);
			t[v][3] = stupid(l, r);
			return;
		}
		upd(2 * v + 1, l, l + r >> 1, i);
		upd(2 * v + 2, l + r >> 1, r, i);
		merge(t[2 * v + 1], t[2 * v + 2], t[v], l, r);
	}
	int get() {
		return t[0][3];
	}
};

void solve(){
	fill(c, c + 100, 0);
	for (int i = 0; i < 10; i++)
		c[i] = i + 1;
	for (int i = 10; i <= 18; i++)
		c[i] = 19 - i;
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		char t; cin >> t;
		s[i] = t - '0';
	}
	T t;
	if (n >= 4) t = T(n);
	for (int i = 0; i < m; i++) {
		int x, d; cin >> x >> d; x--;
		s[x] = d;
		if (n >= 4) {
			t.upd(0, 0, n, x);
			cout << t.get() << endl;
		}
		else {
			cout << stupid(0, n) << endl;
		}
	}
	return;
}