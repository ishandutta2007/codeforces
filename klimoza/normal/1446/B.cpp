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

const int N = 5e3 + 2;

int dp[N][N];

void solve() {
	int n, m; cin >> n >> m;
	string a, b; cin >> a >> b;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			dp[i][j] = -inf0;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i + j == 0) dp[i][j] = 0;
			else if (i == 0) dp[i][j] = -1;
			else if (j == 0) dp[i][j] = -1;
			else {
				dp[i][j] = max(max(0, dp[i - 1][j]) - 1, max(0, dp[i][j - 1]) - 1);
				if (a[i - 1] == b[j - 1])
					dp[i][j] = max(dp[i][j], max(0, dp[i - 1][j - 1]) + 2);
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
	return;
}