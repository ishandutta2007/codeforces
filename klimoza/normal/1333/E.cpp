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
const double eps = 1e-7;
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
	if (n < 3) cout << -1 << endl;
	else if (n == 3) {
		cout << "1 2 4\n";
		cout << "5 3 8\n";
		cout << "9 6 7\n";
	}
	else if (n == 4) {
		cout << "4 3 6 12\n7 5 9 15\n14 1 11 10\n13 8 16 2\n";
	}
	else {
		int k = n * n;
		vector<vector<int>> ans(n, vector<int>(n));
		if (n & 1) {
			ans[n - 1][1] = k - 3;
			ans[n - 1][3] = k;
			ans[n - 3][3] = k - 2;
			ans[n - 3][2] = k - 1;
		}
		else {
			ans[n - 1][n - 2] = k - 3;
			ans[n - 1][n - 4] = k;
			ans[n - 3][n - 4] = k - 2;
			ans[n - 3][n - 3] = k - 1;
		}
		int t = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (!ans[i][j]) {
					ans[i][j] = t;
					t++;
				}
			}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << ans[i][j] << " ";
			cout << endl;
		}
	}
	return;
}