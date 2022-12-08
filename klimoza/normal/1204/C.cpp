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
#include <complex>

#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-6;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;

void solve();

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

void solve() {
	int n;
	cin >> n;
	vector<vector<ll>> g(n, vector<ll>(n));
	string st;
	for (int i = 0; i < n; i++) {
		cin >> st;
		for (int j = 0; j < n; j++) {
			if (st[j] == '1') g[i][j] = 1;
			else g[i][j] = inf0;
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j && g[i][k] < inf0 && g[k][j] < inf0 && g[i][k] + g[k][j] < g[i][j]) {
					g[i][j] = g[i][k] + g[k][j];
				}
			}
		}
	}
	int m;
	cin >> m;
	vector<int> ff(m);
	for (int i = 0; i < m; i++) cin >> ff[i];
	vector<ll> dp(m, inf0);
	vector<int> p(m);
	dp[0] = 1;
	p[0] = -1;
	vector<pair<ll, int>> curDP(n, { inf0, -1 });
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (j == ff[i] - 1) continue;
			if (curDP[j].second == -1) continue;
			if (g[j][ff[i] - 1] == (ll)(i - curDP[j].second) && curDP[j].first + 1 < dp[i]) {
				dp[i] = curDP[j].first + 1;
				p[i] = curDP[j].second;
			}
		}
		curDP[ff[i] - 1] = { dp[i], i };
	}
	int en = m - 1;
	vector<int> ans;
	while (en != -1) {
		ans.push_back(ff[en]);
		en = p[en];
	}
	reverse(all(ans));
	cout << dp[m - 1] << endl;
	for (int i : ans) cout << i << " ";
	cout << endl;
}