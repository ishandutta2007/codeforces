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
typedef complex<double> cd;
typedef vector<complex<double>> vcd;

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

void add(int &a, ll b) {
	b += a;
	if (b >= mod) b -= mod;
	a = b;
}

const int N = 1e5 + 1;

ll fac[N];

ll mul(ll a, ll b) {
	return a * b % mod;
}

void solve(){
	int n, m, x; cin >> n >> m >> x;
	if (n > m) cout << 0 << endl;
	else {
		fac[0] = 1;
		for (ll i = 1; i < N; i++) {
			fac[i] = mul(fac[i - 1], i);
		}
		vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));
		dp[0][0][0] = 1;
		for (int pos = 1; pos <= m; pos++) {
			for (int cnt = 0; cnt <= n; cnt++) {
				for (int bal = 0; bal <= cnt; bal++) {
					// want pos; cnt; bal
					// if x:
					if (pos == x) {
						// only left
						if(cnt && bal)
							add(dp[pos][cnt][bal], dp[pos - 1][cnt - 1][bal - 1]);
						// left and right
						if(cnt)
							add(dp[pos][cnt][bal], dp[pos - 1][cnt - 1][bal]);
					}
					else {
						add(dp[pos][cnt][bal], dp[pos - 1][cnt][bal]);
						if (bal != cnt)
							add(dp[pos][cnt][bal], dp[pos - 1][cnt][bal + 1]);
						if(cnt && bal)
							add(dp[pos][cnt][bal], dp[pos - 1][cnt - 1][bal - 1]);
						if(cnt)
							add(dp[pos][cnt][bal], dp[pos - 1][cnt - 1][bal]);
					}
					//cout << pos << " " << cnt << " " << bal << " " << dp[pos][cnt][bal] << endl;
				}
			}
		}
		cout << mul(dp[m][n][0], fac[n]) << endl;
	}
	return;
}