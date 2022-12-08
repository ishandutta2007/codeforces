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

double PI = acos((double)-1);
const double eps = 1e-7;
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

const int N = 1e5 + 7;
const int K = 101;

ll dp[N][K];
ll sm[N];
int lst[N][K];

void add(ll& a, ll b) {
	a += b;
	if (a >= mod)
		a -= mod;
}

ll sub(ll a, ll b) {
	a -= b;
	if (a < 0)
		a += mod;
	return a;
}

int ss[N][K];
int pm[N][K];

void solve() {

	int n, k, len;
	cin >> n >> k >> len;
	if (len == 0) {
		cout << 0 << endl;
		return;
	}
	vector<int> a(n);
	for (int& i : a) cin >> i;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (a[i] == j) lst[i][j] = i;
			else if (!i) lst[i][j] = -1;
			else lst[i][j] = lst[i - 1][j];
			if (j == 1) pm[i][j] = lst[i][j];
			else pm[i][j] = max(pm[i][j - 1], lst[i][j]);
		}
		for (int j = k; j >= 1; j--) {
			if (j == k) ss[i][j] = lst[i][j];
			else ss[i][j] = max(lst[i][j], ss[i][j + 1]);
		}
	}
	sm[0] = 1;
	for (int j = 1; j <= k; j++)
		dp[0][j] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			int m1 = -1;
			int m2 = -1;
			if (j != 1) m1 = pm[i - 1][j - 1];
			if (j != k) m2 = ss[i - 1][j + 1];
			int v = max(m1, m2);
			if (a[i - 1] != -1 && a[i - 1] != j) dp[i][j] = 0;
			else if (v == -1 && i == len)
				dp[i][j] = sub(sm[i - 1], 1);
			else if ((i - 1) - v >= len)
				dp[i][j] = sub(sm[i - 1], sub(sm[i - len], dp[i - len][j]));
			else
				dp[i][j] = sm[i - 1];
			//cout << i << " " << j << " " << dp[i][j] << endl;
			add(sm[i],dp[i][j]);
		}
	}
	cout << sm[n] << endl;
	return;
}