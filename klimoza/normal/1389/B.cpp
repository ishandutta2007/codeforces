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

int dp[N][6][2];

void solve() {
	int t; cin >> t;
	while (t--) {
		int n, k, z; cin >> n >> k >> z;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 6; j++) {
				dp[i][j][0] = dp[i][j][1] = -2e9;
			}
		}
		int ans = -2e9;
		dp[0][0][0] = a[0];
		for (int j = 0; j <= z; j++) {
			for (int i = 0; i < n; i++) {
				if (i) dp[i][j][0] = max(dp[i][j][0], max(dp[i - 1][j][0], dp[i - 1][j][1]) + a[i]);
				if (i < (n - 1) && j) dp[i][j][1] = max(dp[i][j][1], dp[i + 1][j - 1][0] + a[i]);
				if (i + 2 * j == k)
					ans = max(ans, max(dp[i][j][0], dp[i][j][1]));
				//cout << i << " " << j << " " << 0 << " " << dp[i][j][0] << endl;
				//cout << i << " " << j << " " << 1 << " " << dp[i][j][1] << endl;
			}
		}
		cout << ans << endl;
	}
	return;
}