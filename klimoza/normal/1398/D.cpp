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

const int N = 201;

ll dp[N][N][N];

void solve(){
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				dp[i][j][k] = 0;
	int r, g, b; cin >> r >> g >> b;
	dp[r][g][b] = 0;
	vector<ll> x(r), y(g), z(b);
	for (ll &i : x)
		cin >> i;
	for (ll& i : y)
		cin >> i;
	for (ll& i : z)
		cin >> i;
	sort(all(x));
	sort(all(y));
	sort(all(z));
	ll ans = 0;
	for (int i = r; i >= 0; i--) {
		for (int j = g; j >= 0; j--) {
			for (int k = b; k >= 0; k--) {
				if (i && j)
					dp[i - 1][j - 1][k] = max(dp[i - 1][j - 1][k], dp[i][j][k] + x[i - 1] * y[j - 1]);
				if(i && k)
					dp[i - 1][j][k - 1] = max(dp[i - 1][j][k - 1], dp[i][j][k] + x[i - 1] * z[k - 1]);
				if (j && k)
					dp[i][j - 1][k - 1] = max(dp[i][j - 1][k - 1], dp[i][j][k] + y[j - 1] * z[k - 1]);
				//cout << i << " " << j << " " << k << endl;
				//cout << i << " " << j << " " << k << endl;
				//cout << i << " " << j << " " << k << endl;
				ans = max(ans, dp[i][j][k]);
			}
		}
	}
	cout << ans << endl;
	return;
}