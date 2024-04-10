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
//const ll mod = 1e9 + 9;
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

const int N = 2e3 + 8;
bool bad[N];
bool can[N];
int p[N];
int dp[N];

void solve() {
	fill(bad, bad + N, false);
	fill(can, can + N, false);
	fill(dp, dp + N, 0);
	int a, m, n;
	cin >> a >> m >> n;
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		for (; l < r; l++)
			bad[l] = true;
	}
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		int x; cin >> x;
		if (can[t]) {
			p[t] = min(p[t], x);
		}
		else {
			can[t] = true;
			p[t] = x;
		}
	}
	for (int i = 1; i < N; i++) {
		if (!bad[i - 1]) {
			dp[i] = dp[i - 1];
		}
		else {
			dp[i] = inf0;
			for (int j = 0; j < i; j++) {
				if (can[j])
					dp[i] = min(dp[i], dp[j] + (i - j) * p[j]);
			}
			if (dp[i] == inf0) {
				cout << -1 << endl;
				return;
			}
		}
	}
	cout << dp[a] << endl;
	return;
}