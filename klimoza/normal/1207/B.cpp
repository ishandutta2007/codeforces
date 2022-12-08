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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	vector<vector<int>> b(n, vector<int>(m));
	vector<pair<int, int>> ans;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			if (a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1]) {
				ans.push_back({ i + 1, j + 1 });
				b[i][j] = b[i + 1][j + 1] = b[i + 1][j] = b[i][j + 1] = 1;
			}
		}
	}
	if (a != b) cout << -1 << endl;
	else {
		cout << ans.size() << endl;
		for (auto u : ans) cout << u.first << " " << u.second << endl;
	}
}