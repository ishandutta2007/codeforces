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

mt19937 mrand(43);

const double PI = acos((double)-1);
const double eps = 1e-5;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
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

const int N = 70;

int dp[N][N][N][N];
int a[N][N];
int kek[N][N];

int sub(int a, int b, int mod) {
	a -= b;
	if (a < 0)
		a += mod;
	return a;
}

void solve() {
	int n, m, d; cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				for (int h = 0; h < N; h++) {
					dp[i][j][k][h] = -inf0;
				}
			}
			kek[i][j] = -inf0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k <= (m / 2); k++) {
				for (int h = 0; h < d; h++) {
					if (j)
						dp[i][j][k][h] = dp[i][j - 1][k][h];
					if (k) {
						if (j) {
							if (dp[i][j - 1][k - 1][sub(h, a[i][j] % d, d)] == -inf0)
								dp[i][j][k][h] = max(dp[i][j][k][h], -inf0);
							else
								dp[i][j][k][h] = max(dp[i][j][k][h], dp[i][j - 1][k - 1][sub(h, a[i][j] % d, d)] + a[i][j]);
						}
						else if (k == 1 && h == (a[i][j] % d)) {
							dp[i][j][k][h] = max(dp[i][j][k][h], a[i][j]);
						}
						else
							dp[i][j][k][h] = max(dp[i][j][k][h], -inf0);
					}
					else if (h != 0)
						dp[i][j][k][h] = max(dp[i][j][k][h], -inf0);
					else
						dp[i][j][k][h] = max(dp[i][j][k][h], 0);
					//cout << i << " " << j << " " << k << " " << h << " " << dp[i][j][k][h] << "   " << kek[i][h] << endl;
				}
			}
		}
		for (int tot = 0; tot < d; tot++) {
			if (i)
				kek[i][tot] = kek[i - 1][tot];
			for (int k = 0; k <= (m / 2); k++) {
				for (int h = 0; h < d; h++) {
					if (i) {
						if (kek[i - 1][sub(tot, h, d)] == -inf0)
							kek[i][tot] = max(kek[i][tot], -inf0);
						else
							kek[i][tot] = max(kek[i][tot], kek[i - 1][sub(tot, h, d)] + dp[i][m - 1][k][h]);
					}
					else {
						if (tot != h)
							kek[i][tot] = max(kek[i][tot], -inf0);
						else
							kek[i][tot] = max(kek[i][tot], dp[i][m - 1][k][h]);
					}
				}
			}
		}
	}
	cout << kek[n - 1][0] << endl;
	return;
}