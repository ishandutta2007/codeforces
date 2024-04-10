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

ll add(ll a, ll b) {
	a += b;
	if (a >= mod)
		a -= mod;
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

const int N = 2e5 + 6;

ll dp[N][2];

void solve() { 
	ll ans = 0;
	int n; cin >> n;
	string s; cin >> s;
	for (int i = 0; i < N; i++)
		dp[i][0] = dp[i][1] = 0;
	vector<ll> pref(n);
	vector<ll> suff(n);
	suff[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--) {
		suff[i] = suff[i + 1];
		if (s[i + 1] == '?')
			suff[i]++;
	}
	pref[0] = 0;
	for (int i = 1; i < n; i++) {
		pref[i] = pref[i - 1];
		if (s[i - 1] == '?')
			pref[i]++;
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a') {
			dp[i][0] = bp(3, pref[i]);
			if (i) {
				dp[i][0] = add(dp[i - 1][0], dp[i][0]);
				dp[i][1] = add(dp[i - 1][1], dp[i][1]);
			}
		}
		else if (s[i] == 'b') {
			if (i) {
				dp[i][0] = add(dp[i - 1][0], dp[i][0]);
				dp[i][1] = add(dp[i - 1][1], dp[i - 1][0]);
			}
		}
		else if (s[i] == 'c') {
			if (i) {
				dp[i][0] = add(dp[i - 1][0], dp[i][0]);
				dp[i][1] = add(dp[i - 1][1], dp[i][1]);
				ans = add(ans, mul(dp[i - 1][1], bp(3, suff[i])));
			}
		}
		else {
			dp[i][0] = bp(3, pref[i]);
			if (i)
				dp[i][0] = add(dp[i][0], mul(dp[i - 1][0], 3));
			
			if (i)
				dp[i][1] = add(dp[i - 1][0], mul(dp[i - 1][1], 3));

			if (i)
				ans = add(ans, mul(dp[i - 1][1], bp(3, suff[i])));
		}
		//cout << i << " " << dp[i][0] << " " << dp[i][1] << endl;
	}
	cout << ans << endl;
	return;
}