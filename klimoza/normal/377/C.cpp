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

const int N = 20;

int dp[N + 1][1 << N];

void solve() {
	int n; cin >> n;
	vector<int> s(n);
	int ans = 0;
	for (int &i : s)
		cin >> i;
	sort(rall(s));
	int m; cin >> m;
	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < (1 << N); j++) {
			dp[i][j] = 2e9;
		}
	}
	dp[0][0] = 0;
	vector<pair<char, int>> kek(m);
	for (auto& u : kek)
		cin >> u.first >> u.second;
	reverse(all(kek));
	for (int i = 0; i < m; i++) {
		char c = kek[i].first;
		int t = kek[i].second;
		for (int mask = 0; mask < (1 << m); mask++) {
			for (int j = 0; j < m; j++) {
				if ((1 << j) & mask) {
					if (dp[i][mask ^ (1 << j)] != 2e9) {
						int x = dp[i][mask ^ (1 << j)];
						if (c == 'p') {
							if (t == 1) {
								if (x + s[j] > dp[i + 1][mask] || dp[i + 1][mask] == 2e9) {
									dp[i + 1][mask] = x + s[j];
								}
							}
							else {
								if (x - s[j] < dp[i + 1][mask] || dp[i + 1][mask] == 2e9)
									dp[i + 1][mask] = x - s[j];
							}
						}
						else {
							if (t == 1) {
								if (x > dp[i + 1][mask] || dp[i + 1][mask] == 2e9)
									dp[i + 1][mask] = x;
							}
							else {
								if (x < dp[i + 1][mask] || dp[i + 1][mask] == 2e9)
									dp[i + 1][mask] = x;
							}
						}
					}
				}
			}
		}
	}
	cout << dp[m][(1 << m) - 1] << endl;
	return;
}