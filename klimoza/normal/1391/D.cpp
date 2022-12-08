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

bool good[4][1 << 3][1 << 3];

int mem[2][3];

bool check() {
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 2; j++) {
			if ((mem[i][j] + mem[i + 1][j] + mem[i][j + 1] + mem[i + 1][j + 1]) % 2 == 0)
				return false;
		}
	}
	return true;
}

int bt[1 << 3];

void solve(){
	for(int k = 0; k < 4; k++)
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			good[k][i][j] = false;
		}
	}
	for (int i = 0; i < (1 << 3); i++) {
		for (int j = 0; j < 3; j++) {
			if (i & (1 << j))
				bt[i]++;
		}
	}
	good[1][0][0] = true;
	good[1][0][1] = true;
	good[1][1][0] = true;
	good[1][1][1] = true;
	good[2][0][1] = true;
	good[2][0][2] = true;
	good[2][3][1] = true;
	good[2][3][2] = true;
	good[2][1][0] = true;
	good[2][1][3] = true;
	good[2][2][0] = true;
	good[2][2][3] = true;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 3; k++) {
				mem[0][k] = (bool)(i & (1 << k));
				mem[1][k] = (bool)(j & (1 << k));
			}
			/*if (i == 0 && j == 5) {
				for (int t1 = 0; t1 < 2; t1++) {
					for (int t2 = 0; t2 < 3; t2++)
						cout << mem[t1][t2] << " ";
					cout << endl;
				}
			}*/
			good[3][i][j] = check();
		}
	}
	int n, m; cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			if (c == '1') a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
	//cout << good[3][0][5] << endl;
	if (n >= 4 && m >= 4) cout << -1 << endl;
	else {
		if (n < m) {
			vector<vector<int>> b(m, vector<int>(n));
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					b[j][i] = a[i][j];
				}
			}
			swap(n, m);
			a = b;
		}
		vector<vector<int>> dp(n, vector<int>(1 << m, 2e9));
		vector<int> msk(n, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				msk[i] += a[i][j] << j;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < (1 << m); j++) {
				if (i == 0) dp[i][j] = bt[msk[i] ^ j];
				else {
					for (int k = 0; k < (1 << m); k++) {
						if (good[m][k][j])
							dp[i][j] = min(dp[i - 1][k] + bt[msk[i] ^ j], dp[i][j]);
						//.if (i == (n - 1) && j == 5) cout << k << " " << dp[i][j] << " " << good << endl;
					}
				}
				//cout << i << " " << j << " " << dp[i][j] << endl;
			}
		}
		int ans = 2e9;
		for (int j = 0; j < (1 << m); j++) {
			ans = min(ans, dp[n - 1][j]);
		}
		if (ans == 2e9) cout << -1 << endl;
		else cout << ans << endl;
		/*
		int tot = n * m;
		vector<vector<int>> res(n, vector<int>(m));
		int ans = 2e9;
		for (int mask = 0; mask < (1 << tot); mask++) {
			for (int i = 0; i < tot; i++) {
				res[i / m][i % m] = (bool)(mask & (1 << i));
			}
			int cur = 0;
			bool fl = true;
			for (int i = 0; i < n - 1; i++) {
				for (int j = 0; j < m - 1; j++) {
					if ((res[i][j] + res[i + 1][j] + res[i][j + 1] + res[i + 1][j + 1]) % 2 == 0)
						fl = false;
				}
			}
			if (!fl) continue;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (res[i][j] != a[i][j])
						cur++;
			ans = min(ans, cur);
		}
		if (ans == 2e9) cout << -1 << endl;
		else cout << ans << endl;*/
	}
	return;
}