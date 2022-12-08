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
#include <string>
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
#include <stack>
#include <ctime>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(43);

const double PI = acos((double)-1);
const double eps = 1e-5;
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

const int N = 2e3 + 7;

int ul[N][N], dl[N][N], ur[N][N], dr[N][N];
char f[N][N];

void solve(){
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> f[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!i || !j || (f[i][j] != f[i - 1][j]) || (f[i][j] != f[i][j - 1]))
				ul[i][j] = 1;
			else
				ul[i][j] = 1 + min(ul[i - 1][j], ul[i][j - 1]);
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			if ((i == n - 1) || !j || (f[i][j] != f[i + 1][j]) || (f[i][j] != f[i][j - 1]))
				dl[i][j] = 1;
			else
				dl[i][j] = 1 + min(dl[i + 1][j], dl[i][j - 1]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = m - 1; j >= 0; j--) {
			if (!i || (j == (m - 1)) || (f[i][j] != f[i - 1][j]) || (f[i][j] != f[i][j + 1]))
				ur[i][j] = 1;
			else
				ur[i][j] = 1 + min(ur[i - 1][j], ur[i][j + 1]);
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if ((i == (n - 1)) || (j == (m - 1)) || (f[i][j] != f[i + 1][j]) || (f[i][j] != f[i][j + 1]))
				dr[i][j] = 1;
			else
				dr[i][j] = 1 + min(dr[i + 1][j], dr[i][j + 1]);
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ans += min(min(ul[i][j], ur[i][j]), min(dl[i][j], dr[i][j]));
	cout << ans << endl;
	return;
}