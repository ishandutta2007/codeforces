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

const int N = 11;
const int M = N * N + 5;
const int F = 1e3;
pair<int, int> d[F][F];

pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
	return make_pair(a.first + b.first, a.second + b.second);
}

int id(int x, int y, int type) {
	return 3 * N * x + 3 * y + type;
}

int n;

bool isOn(int x, int y) {
	if (x >= 0 && y >= 0 && x < n && y < n) return true;
	return false;
}

void solve() {
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	vector<int> ver;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			ver.push_back(id(i, j, 0));
			ver.push_back(id(i, j, 1));
			ver.push_back(id(i, j, 2));
		}
	}
	for (int i = 0; i < F; i++) {
		fill(d[i], d[i] + F, make_pair( 2e9, 2e9 ));
	}
	sort(all(ver));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// Type 1  :
			int t = id(i, j, 0);
			for (int i1 = 0; i1 < n; i1++) {
				for (int j1 = 0; j1 < n; j1++) {
					if ((abs(i1 - i) == 1 && abs(j1 - j) == 2) || (abs(i1 - i) == 2 && abs(j1 - j) == 1)) {
						int h = id(i1, j1, 0);
						d[t][h] = { 1, 0 };
					}
				}
			}
			//Type 2  :
			t = id(i, j, 1);
			for (int i1 = 0; i1 < n; i1++) {
				for (int j1 = 0; j1 < n; j1++) {
					if (i1 == i || j1 == j) {
						int h = id(i1, j1, 1);
						d[t][h] = { 1, 0 };
					}
				}
			}
			//Type 3  :
			t = id(i, j, 2);
			for (int i1 = 0; i1 < n; i1++) {
				for (int j1 = 0; j1 < n; j1++) {
					if (abs(i1 - i) == abs(j1 - j)) {
						int h = id(i1, j1, 2);
						d[t][h] = { 1, 0 };
					}
				}
			}
			//Type 4:
			for (int i1 = 0; i1 < 3; i1++) {
				for (int j1 = 0; j1 < 3; j1++) {
					t = id(i, j, i1);
					int h = id(i, j, j1);
					if (i1 == j1) d[t][h] = { 0, 0 };
					else d[t][h] = { 1, 1 };
				}
			}
		}
	}
	int m = ver.size();
	for (int k1 = 0; k1 < m; k1++) {
		for (int i1 = 0; i1 < m; i1++) {
			for (int j1 = 0; j1 < m; j1++) {
				int i = ver[i1], j = ver[j1], k = ver[k1];
				//cout << i << " " << k << " " << d[i][k] << endl;
				if (d[i][k].first != 2e9 && d[k][j].first != 2e9 && (d[i][k] + d[k][j] < d[i][j])) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
	vector<pair<int, int>> ans(n * n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[a[i][j] - 1] = { i, j };
		}
	}
	vector<vector<pair<int, int>>> dp(n * n, vector<pair<int, int>>(3,  { 2e9, 2e9 }));
	dp[0][0] = dp[0][1] = dp[0][2] = { 0, 0 };
	for (int i = 1; i < n * n; i++) {
		for (int t1 = 0; t1 < 3; t1++) {
			for (int t2 = 0; t2 < 3; t2++) {
				int h1 = id(ans[i - 1].first, ans[i - 1].second, t2);
				int h2 = id(ans[i].first, ans[i].second, t1);
				dp[i][t1] = min(dp[i][t1], dp[i - 1][t2] + d[h1][h2]);
			}
		}
	}
	pair<int, int> b = min(dp.back()[0], min(dp.back()[1], dp.back()[2]));
	cout << b.first << " " << b.second << endl;
}