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

#define int long long

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

const int N = 1e5 + 2;

int c[N], f[N], h[N];

const int  M = 502;
const int K = 12;

ll dp[M][M * K];

void bl() {
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M * K; j++)
			dp[i][j] = -inf;
	dp[0][0] = 0;
}

int k;

//x    y   k
ll getAns(int x, int y) {
	if (!x || !y) return 0;
	bl();
	int c = 0;
	for (int i = 1; i <= y; i++) {
		for (int j = 0; j <= x; j++) {
			for (int t = max(j - k, 0ll); t <= j; t++)
				dp[i][j] = max(dp[i][j], dp[i - 1][t] + h[j - t]);
			c = max(c, dp[i][j]);
		}
	}
	return c;
}

void solve() {
	fill(c, c + N, 0);
	fill(f, f + N, 0);
	fill(h, h + N, 0);
	int n; cin >> n >> k;
	for (int i = 0; i < n * k; i++) {
		int x; cin >> x;
		c[x]++;
	}
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		f[x]++;
	}
	h[0] = 0;
	for (int i = 0; i < k; i++)
		cin >> h[i + 1];
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		ans += getAns(c[i], f[i]);
	}
	cout << ans << endl;
	return;
}