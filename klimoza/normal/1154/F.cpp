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

double PI = acos((double)-1);
const ld eps = 1e-7;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 9;
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

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> b(n);
	vector<ll> mn(n + 1, 0);
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < m; i++) {
		ll x, y; cin >> x >> y;
		mn[x] = max(mn[x], y);
	}
	vector<ll> a;
	sort(all(b));
	for (int i = 0; i < k; i++)
		a.push_back(b[i]);
	n = k;
	vector<ll> p(n + 1);
	for (int i = 1; i <= n; i++)
		p[i] = p[i - 1] + a[i - 1];
	vector<ll> dp(n + 1, inf);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int c = 1; c <= i; c++) {
			if (c == i && mn[c] == 0)
				dp[i] = min(dp[i], p[i]);
			else {
				int r = i;
				int l = i - c + 1 + mn[c];
				if (l > r) dp[i] = min(dp[i], dp[i - c]);
				else dp[i] = min(dp[i], dp[i - c] + p[r] - p[l - 1]);
			}
		}
	}
	cout << dp[n] << endl;
	return;
}