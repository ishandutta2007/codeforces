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

const ll N = 1e3 + 1;
const int L = 50;

ll add(ll a, ll b) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

ll mul(ll a, ll b) {
	return a * b % mod;
}

ll bp(ll a, ll k) {
	ll res = 1;
	while (k) {
		if (k & 1)
			res = mul(res, a);
		a = mul(a, a);
		k >>= 1;
	}
	return res;
}

ll rev(ll a) {
	return bp(a, mod - 2);
}

ll fac[N], rv[N];

ll C[N][N];

ll comb(ll n, ll k) {
	if (k > n) return 0;
	return mul(fac[n], mul(rv[k], rv[n - k]));
}

void build() {
	fac[0] = 1;
	for (ll i = 1; i < N; i++)
		fac[i] = mul(fac[i - 1], i);
	rv[N - 1] = rev(fac[N - 1]);
	for (ll i = N - 2; i >= 0; i--)
		rv[i] = mul(rv[i + 1], i + 1);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			C[i][j] = comb(i, j);
}


int dp[N][L][N];

ll cnt[L][N];

ll ans[L][N];

ll tmp[L + 1][N];

void solve() {
	build();
	int t; cin >> t;
	for (int i = 0; i <= L; i++) {
		for (int j = 0; j < N; j++) {
			if (!i) tmp[i][j] = 1;
			else {
				for (int k = 0; k <= j; k++)
					tmp[i][j] = add(tmp[i][j], tmp[i - 1][j - k]);
				//cout << i << " " << j << " " << tmp[i][j] << " LOL\n";
			}
		}
	}
	cnt[0][0] = 1;
	for (int i = 0; i < N; i++) {
		if(i)
		for (int j = 0; j < L; j++) {
			for (int k = 0; k < N; k++) {
				if (j && k >= i) {
					dp[i][j][k] = add(dp[i][j][k], dp[i - 1][j - 1][k - i]);
					//cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
					cnt[j][k] = add(cnt[j][k], dp[i][j][k]);
				}
				dp[i][j][k] = add(dp[i][j][k], dp[i - 1][j][k]);
			}
		}
		dp[i][1][i] = add(dp[i][1][i], 1);
		cnt[1][i] = add(cnt[1][i], 1);
	}
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < N; j++) {
			//cout << i << " " << j << " " << cnt[i][j] << " --- CNT[i][j]" << endl;
			for (int k = 0; k <= j - i; k++) {
				ans[i][j] = add(ans[i][j], mul(cnt[i][k], mul(fac[i], tmp[i][j - k - i])));
				//cout << i << " " << j << " " << k << " " << cnt[i][k] << " " << fac[i] << " " << tmp[i][j - k] <<  " " << ans[i][j] << " --- ANS[i][j]" << endl;
			}
		}
	}
	while (t--) {
		int n, k; cin >> n >> k;
		if (k >= L) cout << 0 << endl;
		else {
			cout << ans[k][n] << endl;
		}
	}
	return;
}