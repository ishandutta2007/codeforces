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

const double PI = acos((double)-1);
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

const int N = 1e2 + 1;
const int M = N * N;

int n, m;
ll a[N][N];
ll dp[N][N];
ll tmp[M];

ll foo(ll x) {
	if (x > a[0][0]) return inf;
	dp[0][0] = a[0][0] - x;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + j == 0) continue;
			dp[i][j] = inf;
			if (x + (i + j) > a[i][j]) 
				dp[i][j] = inf;
			else {
				if (i)
				{
					if (dp[i - 1][j] + (a[i][j] - (x + (i + j))) < dp[i][j]) {
						dp[i][j] = dp[i - 1][j] + (a[i][j] - (x + (i + j)));
					}
				}
				if (j) {
					if (dp[i][j - 1] + (a[i][j] - (x + (i + j))) < dp[i][j]) {
						dp[i][j] = dp[i][j - 1] + (a[i][j] - (x + (i + j)));
					}
				}

			}
			//cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}
	return dp[n - 1][m - 1];
}

void solve() {
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		int id = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				tmp[id++] = (a[i][j] - (i + j));
			}
		}
		ll ans = inf;
		for (int i = 0; i < id; i++) {
			ans = min(ans, foo(tmp[i]));
		}
		cout << ans << endl;
	}
	return;
}