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


vector<char> p;

void go(int& x, int& y, int n, int m) {
	if (x % 2 == 0) {
		if (y == m - 1) x++;
		else y++;
	}
	else {
		if (y == 0) x++;
		else y--;
	}
}

void solve() {
	int t; cin >> t;
	for (char c = 'a'; c <= 'z'; c++) p.push_back(c);
	for (char c = 'A'; c <= 'Z'; c++)p.push_back(c);
	for (char c = '0'; c <= '9'; c++) p.push_back(c);
	while (t--) {
		int n, m, k; cin >> n >> m >> k;
		vector<string> f(n);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> f[i];
			for (int j = 0; j < m; j++) {
				if (f[i][j] == 'R') cnt++;
			}
		}
		int g = cnt / k;
		int r = cnt % k;
		int l = k - r;
		int id = 0;
		vector<vector<char>> ans(n, vector<char>(m));
		int x = 0, y = 0;
		int cur = 0;
		while (true) {
			//cout << x << " " << y << endl;
			if (x == n) break;
			ans[x][y] = p[id];
			if (f[x][y] == 'R') cur++;
			if (cur == g && id < l) {
				id++;
				cur = 0;
			}
			else if (cur == (g + 1) && id >= l) {
				cur = 0;
				id++;
			}
			if (id == k) id--;
			go(x, y, n, m);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << ans[i][j];
			}
			cout << endl;
		}
	}
}