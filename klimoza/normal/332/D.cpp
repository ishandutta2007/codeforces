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

const int N = 2e3 + 1;

ll c[N][N];

void solve() {
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		c[i][i] = -1;
		for (int j = i + 1; j < n; j++) {
			cin >> c[i][j];
			c[j][i] = c[i][j];
		}
	}
	if (k != 2) {
		ll a = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (c[i][j] != -1)
					a += 2 * c[i][j];
			}
		}
		cout << a / n << endl;
	}
	else {
		ll a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			ll x = 0;
			ll t = 0;
			for (int j = 0; j < n; j++) {
				if (c[i][j] != -1) {
					a += x + t * c[i][j];
					x += c[i][j];
					//cout << i << " " << j << " " << a << " " << x << " " << c[i][j] << endl;
					t++;
				}
			}
			b += t * (t - 1) / 2;
		}
		//cout << a << " " << b << endl;
		cout << a / b << endl;
	}
	return;
}