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

#define int long long

#define endl '\n'
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
void scan();

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	int t;
	t = 1;
	//cin >> t;
	while (t--)
		solve();
	return 0;
}

const int N = 2e5 + 7;
const int K = 10;
int dp[N][K];
pair<int, int> a[N], f1[N], f2[N], f3[N];
pair<int, int> b[5];

bool bet(int l, int i, int r) {
	l %= K; r %= K;
	if (l > r) r += K;
	if (i < l) i += K;
	return (l <= i && i <= r);
}

int md(int i, int m) {
	if (i >= m) i -= m;
	return i;
}

void solve() {
	int n; cin >> n;
	//int n = 1e4;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < K; j++)
			dp[i][j] = -2e18;
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		//int k = 5;
		//cout << i << endl;
		int sz1 = 0, sz2 = 0, sz3 = 0, sz4 = 0;
		for (int j = 0; j < k; j++) {
			int u, v; cin >> u >> v;
			//int u = 1, v = 5;
			if (u == 1) f1[sz1++] = { u, v };
			else if (u == 2) f2[sz2++] = { u, v };
			else f3[sz3++] = { u, v };
		}
		if (sz1) sort(f1, f1 + sz1);
		if (sz2) sort(f2, f2 + sz2);
		if (sz3) sort(f3, f3 + sz3);
		if (sz1) for (int i = sz1 - 1; i >= max((int)0, (int)sz1 - 4); i--) a[sz4++] = f1[i];
		if (sz2) a[sz4++] = f2[sz2 - 1];
		if (sz3) a[sz4++] = f3[sz3 - 1];
		k = sz4;
		for (int j = 0; j < K; j++) {
			for (int f = 0; f < (1 << k); f++) {
				int sz = 0;
				for (int c = 0; c < k; c++) {
					if ((1 << c) & f) b[sz++] = a[c];
				}
				int s = 0;
				for (int u = 0; u < sz; u++) s += b[u].first;
				if (s > 3) continue;
				s = 0;
				int maxi = 0;
				for (int u = 0; u < sz; u++) {
					s += b[u].second;
					maxi = max(maxi, b[u].second);
				}
				int cnt = sz;
				/*if (i == 0) {
					cout << "LOL : " << i << " " << j << " " << s << " " << cnt << endl;
				}*/
				int h = 0;
				if (i) h = dp[i - 1][j];
				else if (j) break;
				if (bet(j + 1, 0, cnt + j)) dp[i][md(j + cnt, K)] = max(dp[i][md(j + cnt, K)], h + s + maxi);
				else dp[i][md(j + cnt, K)] = max(dp[i][md(j + cnt, K)], h + s);
			}
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < K; j++) {
			cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}*/
	int maxi = 0;
	for (int i = 0; i < K; i++) {
		maxi = max(maxi, dp[n - 1][i]);
	}
	cout << maxi << endl;
}