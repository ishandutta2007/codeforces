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
	int n; cin >> n;
	vector<pair<ll, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(all(a));
	vector<ll> dp(n);
	vector<pair<ll, int>> p(n, { inf, 0 });
	vector<int> pr(n, -1);
	for (int i = 2; i < n; i++) {
		p[i] = p[i - 1];
		if (i < 5) {
			dp[i] = a[i].first - a[0].first;
			if(i < n - 1)
			if (dp[i] - a[i + 1].first < p[i].first) {
				p[i] = { dp[i] - a[i + 1].first, i };
			}
		}
		else {
			dp[i] = a[i].first + p[i - 3].first;
			pr[i] = p[i - 3].second;
			if(i < n - 1)
			if (dp[i] - a[i + 1].first < p[i].first) {
				p[i] = { dp[i] - a[i + 1].first, i };
			}
		}
	}
	vector<int> ans(n);
	int cnt = 1;
	for (int i = n - 1; i >= 0; i = pr[i]) {
		for (int j = i; j > pr[i]; j--) {
			ans[a[j].second] = cnt;
		}
		cnt++;
	}
	cout << dp[n - 1] << " " << cnt - 1 << endl;
	for (int i : ans) cout << i << " ";
}