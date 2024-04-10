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

const int N = 2e2 + 1;

int dp[N][N][N];

void solve() {
	int n, k; cin >> n >> k;
	string s, t; cin >> s >> t;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int h = 0; h < N; h++)
				dp[i][j][h] = -inf0;
	if (t[0] == t[1]) {
		int c = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == t[0]) c++;
			else if (k) {
				c++;
				k--;
			}
		}
		cout << c * (c - 1) / 2 << endl;
		return;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= min(k, i + 1); j++) { // changes
			for (int h = 0; h <= i + 1; h++) { // t[0]
				dp[i][j][h] = 0;
				if (!i && (j > 1 || h > 1 || (j == 0 && h == 1 && s[i] != t[0]))) {
					dp[i][j][h] = -inf0;
				}
				else if (!i && j == 1 && h == 0) {
					dp[i][j][h] = 0;
				}
				else {
					//not change
					if (h == (i + 1))
						dp[i][j][h] = -inf0;
					else {
						if (i == 0)
							dp[i][j][h] = 0;
						else
							dp[i][j][h] = dp[i - 1][j][h];
					}
					// t[0]
					if (j >= (s[i] != t[0])) {
						if (i)
							dp[i][j][h] = max(dp[i][j][h], dp[i - 1][j - (s[i] != t[0])][h - 1]);
						else
							dp[i][j][h] = 0;
					}
					// t[1]
					if (j >= (s[i] != t[1])) {
						if (i)
							dp[i][j][h] = max(dp[i][j][h], dp[i - 1][j - (s[i] != t[1])][h] + h);
					}
					//cout << i << " " << j << " " << h << " " << dp[i][j][h] << endl;
					ans = max(ans, dp[i][j][h]);
				}
			}
		}
	}
	cout << ans << endl;
	return;
}