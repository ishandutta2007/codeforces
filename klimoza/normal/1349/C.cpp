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

const double PI = acos((double)-1);
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

const int N = 1e3 + 7;

char f[N][N];	

int a1[N][N], a2[N][N], a3[N][N], a4[N][N];
bool nice[N][N];
int ans[N][N];

void solve() {
	int n, m, t;
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> f[i][j];
			a1[i][j] = a2[i][j] = a3[i][j] = a4[i][j] = inf0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i && f[i][j] == f[i - 1][j])
				nice[i][j] = nice[i - 1][j] = true;
			if (j && f[i][j] == f[i][j - 1])
				nice[i][j] = nice[i][j - 1] = true;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (nice[i][j])
				a1[i][j] = a2[i][j] = a3[i][j] = a4[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = a1[i][j];
			if (i) x = min(x, a1[i - 1][j] + 1);
			if (j) x = min(x, a1[i][j - 1] + 1);
			a1[i][j] = x;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for(int j =0 ; j < m; j++){
			int x = a2[i][j];
			if (i < (n - 1)) x = min(x, a2[i + 1][j] + 1);
			if (j) x = min(x, a2[i][j - 1] + 1);
			a2[i][j] = x;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = m - 1; j >= 0; j--) {
			int x = a3[i][j];
			if (i) x = min(x, a3[i - 1][j] + 1);
			if (j < (m - 1)) x = min(x, a3[i][j + 1] + 1);
			a3[i][j] = x;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			int x = a4[i][j];
			if (i < (n - 1)) x = min(x, a4[i + 1][j] + 1);
			if (j < (m - 1)) x = min(x, a4[i][j + 1] + 1);
			a4[i][j] = x;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans[i][j] = min(min(a1[i][j], a2[i][j]), min(a3[i][j], a4[i][j]));
		}
	}
	while (t--) {
		int i, j;
		ll x; cin >> i >> j >> x; i--; j--;
	//	cout << ans[i][j] << " kek\n";
		if (ans[i][j] == inf0) cout << f[i][j] << endl;
		else {
			if (x <= ans[i][j]) cout << f[i][j] << endl;
			else {
				int a = f[i][j] - '0';
				//cout << x << " " << ans[i][j] << endl;
				a = a ^ ((x - ans[i][j]) & 1);
				cout << a << endl;
			}
		}
	}
	return;
}