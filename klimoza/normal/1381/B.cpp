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

const int N = 4e3 + 2;
const int K = 2e3 + 2;

bool dp[N][K][2];	

void solve() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i <= 2 * n; i++) {
			for (int j = 0; j <= n; j++) {
				dp[i][j][0] = dp[i][j][1] = false;
			}
		}
		dp[0][1][0] = dp[0][0][1] = true;
		vector<int> p(2 * n);
		for (int i = 0; i < 2 * n; i++)
			cin >> p[i];
		int m = 0;
		for (int i = 0; i < 2 * n; i++) {
			for (int j = 0; j <= i; j++) {
				if (p[i] < m) {
					if (dp[i][j][0]) {
						if (j < n)
							dp[i + 1][j + 1][0] = true;
					}
					if (dp[i][j][1]) {
						if ((i - j) < n)
							dp[i + 1][j][1] = true;
					}
				}
				else {
					if (j < n) {
						if (dp[i][j][0] || dp[i][j][1])
							dp[i + 1][j + 1][0] = true;
					}
					if ((i - j) < n) {
						if (dp[i][j][0] || dp[i][j][1])
							dp[i + 1][j][1] = true;
					}
				}
			}
			m = max(m, p[i]);
		}
		if (dp[2 * n][n][0] || dp[2 * n][n][1]) cout << "YES\n";
		else cout << "NO\n";
	}
	return;	
}