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

const int L = 840;
const int N = 9;

ll c[N];

const ll W = 8 * L + 1;

ll dp[N][W];

void solve() {
	ll w; cin >> w;
	for (int i = 1; i < N; i++)
		cin >> c[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < W; j++)
			dp[i][j] = -1;
	dp[0][0] = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < W; j++) {
			dp[i][j] = dp[i - 1][j];
			for (int k = 0; k <= min((ll)j, min((ll)L, c[i])); k++) {
				if (dp[i - 1][j - k * i] == -1) continue;
				if (i * k > j || i * k > L) break;
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k * i] + (c[i] - k) * i / L);
			}
		}
	}
	ll ans = 0;
	for (int j = 0; j < min(w + 1, W); j++) {
		if (dp[8][j] == -1) continue;
		ll c = dp[8][j];
		ll t = w - j;
		ll tmp = t / L;
		tmp = min(tmp, dp[8][j]);
		t = tmp * L + j;
		ans = max(ans, t);
	}
	cout << ans << endl;
	return;
}