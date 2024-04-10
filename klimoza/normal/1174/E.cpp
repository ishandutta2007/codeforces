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

int n;

const int N = 1e6 + 7;
const int L = 20;

ll f(int x, int y) {
	int h = 1;
	if (y) h = 3;
	return n / ((1 << x) * h);
}

int dp[N][L][2];

void add(int& x, int d) {
	x += d;
	if (x >= mod) x -= mod;
}

void solve() {
	cin >> n;
	int l = log2(n);
	dp[0][l][0] = 1;
	if ((1 << (l - 1)) * 3 <= n) dp[0][l - 1][1] = 1;
	for (int i = 0; i < n - 1; i++) {
		for (int x = l; x >= 0; x--) {
			for (int y = 1; y >= 0; y--) {
				add(dp[i + 1][x][y], (dp[i][x][y] * 1LL * (f(x, y) - i - 1LL)) % mod);
				if(x)
					add(dp[i + 1][x - 1][y], (dp[i][x][y] * 1LL * (f(x - 1, y) - f(x, y))) % mod);
				if (y)
					add(dp[i + 1][x][y - 1], (dp[i][x][y] * 1LL * (f(x, y - 1) - f(x, y))) % mod);
				//cout << i + 1 << " " << x << " " << y << "  " << dp[i][x][y] << endl;
			}
		}
	}
	cout << dp[n - 1][0][0] << endl;
}