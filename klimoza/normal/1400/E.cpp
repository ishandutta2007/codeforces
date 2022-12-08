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

const int N = 5e3 + 1;

ll dp[N][N];

ll m[N];

int a[N];

void solve() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int len = 1; len <= n; len++) {
		for (int l = 0; (l + len - 1 < n); l++) {
			int r = l + len - 1;
			if (len == 1) m[l] = l;
			else {
				if (a[l] <= a[m[l + 1]])
					m[l] = l;
				else
					m[l] = m[l + 1];
			}
		}
		for (int l = 0; (l + len - 1 < n); l++) {
			int r = l + len - 1;
			if (len == 1) dp[l][r] = a[l];
			else {
				ll x1 = 0;
				if (m[l] == l)  x1 = 0;
				else x1 = min(m[l] - l, dp[l][m[l] - 1] - a[m[l]]);
				ll x2 = 0;
				if (m[l] == r) x2 = 0;
				else x2 = min(r - m[l], dp[m[l] + 1][r] - a[m[l]]);
				dp[l][r] = x1 + x2 + a[m[l]];
			}
		}
	}
	cout << min((ll)n, dp[0][n - 1]) << endl;
	return;
}