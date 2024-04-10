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

mt19937 mrand(random_device{}());
//mt19937 mrand(228);

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

const int N = 3e3 + 2;
const int K = 3e3 + 2;
//divide and conquer NKlogN

ll dp[K];

ll ans = 0;

ll a[N][K];
pair<ll, int> s[N];

int k;

void relax(int l, int r) {
	for (int i = l; i < r; i++) {
		for (int j = K - 1; j >= 0; j--) {
			if (j < s[i].second)
				break;
			dp[j] = max(dp[j], dp[j - s[i].second] + s[i].first);
		}
	}
}

void getAns(int l, int r) {
	int m = l + r >> 1;
	if (r - l == 1) {
		for (int j = 0; j <= k; j++)
			ans = max(ans, dp[j] + a[l][k - j]);
	}
	else {
		vector<ll> kek(K);
		for (int i = 0; i < K; i++)
			kek[i] = dp[i];
		relax(m, r);
		getAns(l, m);
		for (int j = 0; j < K; j++)
			dp[j] = kek[j];
		relax(l, m);
		getAns(m, r);
		for (int j = 0; j < k; j++)
			dp[j] = kek[j];
			
	}
}

void solve() {
	int n; cin >> n >> k;
	vector<vector<ll>> t(n);
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		t[i].resize(c);
		a[i][0] = 0;
		ll tot = 0;
		for (int j = 0; j < c; j++) {
			cin >> t[i][j];
			tot += t[i][j];
			if (j <= K)
				a[i][j + 1] = a[i][j] + t[i][j];
		}
		for (int j = c; j < K; j++)
			a[i][j + 1] = a[i][j];
		s[i] = mp(tot, c);
	}
	fill(dp, dp + K, 0);
	getAns(0, n);
	cout << ans << endl;
	return;
}