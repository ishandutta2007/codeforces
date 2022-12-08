#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
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

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
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

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	vector<ll> dp(n);
	dp[0] = 1;
	if (s[0] == 'm' || s[0] == 'w') {
		cout << 0 << endl;
		return;
	}
	for (int i = 1; i < n; i++) {
		if (s[i] == 'm' || s[i] == 'w') {
			cout << 0 << endl;
			return;
		}
		if (i == 1 && s[i] == 'u' && s[i - 1] == 'u') dp[i] = 1;
		if (i == 1 && s[i] == 'n' && s[i - 1] == 'n') dp[i] = 1;
		if (i != 1 && s[i] == 'u' && s[i - 1] == 'u') dp[i] += dp[i - 2];
		if (i != 1 && s[i] == 'n' && s[i - 1] == 'n') dp[i] += dp[i - 2];
		dp[i] += dp[i - 1];
		dp[i] %= mod;
	}
	cout << dp.back() << endl;
}