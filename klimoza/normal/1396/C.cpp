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

const int N = 1e6 + 1;

ll dp[N][2]; 

ll a[N];

ll min(ll a, ll b, ll c) {
	return min(a, min(b, c));
}

void solve() {
	int n; cin >> n;
	ll r1, r2, r3, d; cin >> r1 >> r2 >> r3 >> d;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < N; i++)
		dp[i][0] = dp[i][1] = inf;
	dp[0][0] = 0;
	ll ans = inf;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			if (dp[i][j] == inf) continue;
			//cout << i << " " << j << " " << dp[i][j] << endl;
			// pistol
			if (j == 0 && i == (n - 1)) {
				dp[i + 1][0] = min(dp[i + 1][0], 3 * d + dp[i][j] + (a[i] + 1) * r1 + min(r1, r2, r3));
				ans = min(ans, 2 * d + dp[i][j] + (a[i] + 1) * r1 + min(r1, r2, r3));
			}
			if (j == 0 && i != (n - 1))
				dp[i + 1][1] = min(dp[i + 1][1], d + dp[i][j] + (a[i] + 1) * r1);
			if (j == 1) {
				dp[i + 1][0] = min(dp[i + 1][0], 3 * d + dp[i][j] + (a[i] + 1) * r1 + 2 * min(r1, r2, r3));
				if (i == (n - 1))
					ans = min(ans, 2 * d + dp[i][j] + (a[i] + 1) * r1 + 2 * min(r1, r2, r3));
			}
			// laser
			if (j == 0 && i == (n - 1)) {
				dp[i + 1][0] = min(dp[i + 1][0], 3 * d + dp[i][j] + r2 + min(r1, r2, r3));
				ans = min(ans, 2 * d + dp[i][j] + r2 + min(r1, r2, r3));
			}
			if (j == 0 && i != (n - 1))
				dp[i + 1][1] = min(dp[i + 1][1], d + dp[i][j] + r2);
			if (j == 1) {
				dp[i + 1][0] = min(dp[i + 1][0], 3 * d + dp[i][j] + r2 + 2 * min(r1, r2, r3));
				if (i == (n - 1))
					ans = min(ans, 2 * d + dp[i][j] + r2 + 2 * min(r1, r2, r3));
			}
			// pistol + awp
			if (j == 0) {
				dp[i + 1][0] = min(dp[i + 1][0], d + dp[i][j] + a[i] * r1 + r3);
				if(i == (n - 1))
					ans = min(ans, dp[i][j] + a[i] * r1 + r3);
			}
			if (j == 1) {
				dp[i + 1][0] = min(dp[i + 1][0], 3 * d + dp[i][j] + a[i] * r1 + r3 + min(r1, r2, r3));
				if (i == (n - 1))
					ans = min(ans, d + dp[i][j] + a[i] * r1 + r3 + min(r1, r2, r3));
			}
			// awp
			if (j == 0) {
				dp[i + 1][0] = min(dp[i + 1][0], d + dp[i][j] + (a[i] + 1) * r3);
				if (i == (n - 1))
					ans = min(ans, dp[i][j] + (a[i] + 1) * r3);
			}
			if (j == 1) {
				dp[i + 1][0] = min(dp[i + 1][0], 3 * d + dp[i][j] + (a[i] + 1) * r3 + min(r1, r2, r3));
				if (i == (n - 1))
					ans = min(ans, d + dp[i][j] + (a[i] + 1) * r3 + min(r1, r2, r3));
			}
		}
	}
	cout << ans << endl;
	return;
}