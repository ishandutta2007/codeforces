//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
//#pragma GCC target("avx2")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
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
const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
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

const int N = 5e3 + 2;

ll dp[N][N];
ll tot[N];
ll a[N];

ll add(ll a, ll b) {
	a += b;
	if (a >= mod)
		a -= mod;
	return a;
}

ll sub(ll a, ll b) {
	a -= b;
	if (a < 0)
		a += mod;
	return a;
}

ll mul(ll a, ll b) {
	return a * b % mod;
}

void solve() {
	int n, k, q; cin >> n >> k >> q;
	k++;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i][0] = 1;
		for (int j = 1; j <= k; j++) {
			dp[i][j] = 0;
		}
	}
	for (int j = 1; j <= k; j++) {
		for (int i = 0; i < n; i++) {
			if (j == 1) {
				dp[i][j] = 1;
				continue;
			}
			if (i)
				dp[i][j] = add(dp[i][j], dp[i - 1][j - 1]);
			if (i < n - 1)
				dp[i][j] = add(dp[i][j], dp[i + 1][j - 1]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++)
			tot[i] = add(tot[i], mul(dp[i][j], dp[i][k - j + 1]));
	}
	ll s = 0;
	for (int i = 0; i < n; i++)
		s = add(s, mul(tot[i], a[i]));
	while (q--) {
		int i; ll x; cin >> i >> x;
		i--;
		s = sub(s, mul(tot[i], a[i]));
		a[i] = x;
		s = add(s, mul(tot[i], a[i]));
		cout << s << endl;
	}
	return;
}