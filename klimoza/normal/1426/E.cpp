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

void solve() { 
	int n; cin >> n;
	int x1, x2, x3; cin >> x1 >> x2 >> x3;
	int y1, y2, y3; cin >> y1 >> y2 >> y3;
	int mx = min(x1, y2) + min(x2, y3) + min(x3, y1);
	int an = inf0;
	for (int mask = 0; mask < 8; mask++) {
		int a1 = x1, a2 = x2, a3 = x3;
		int b1 = y1, b2 = y2, b3 = y3;
		int mn = 0;
		int t = 0;
		//
		if (mask & 1) {
			t = min(a1, b1);
			a1 -= t;
			b1 -= t;
			t = min(a2, b1);
			a2 -= t;
			b1 -= t;
		}
		else {
			t = min(a2, b1);
			a2 -= t;
			b1 -= t;
			t = min(a1, b1);
			a1 -= t;
			b1 -= t;
		}
		a3 -= b1;
		mn += b1;
		b1 = 0;
		//
		if (mask & 2) {
			t = min(a2, b2);
			a2 -= t;
			b2 -= t;
			t = min(a3, b2);
			a3 -= t;
			b2 -= t;
		}
		else {
			t = min(a3, b2);
			a3 -= t;
			b2 -= t;
			t = min(a2, b2);
			a2 -= t;
			b2 -= t;
		}
		a1 -= b2;
		mn += b2;
		b2 = 0;
		//
		if (mask & 4) {
			t = min(a3, b3);
			a3 -= t;
			b3 -= t;
			t = min(a1, b3);
			a1 -= t;
			b3 -= t;
		}
		else {
			t = min(a1, b3);
			a1 -= t;
			b3 -= t;
			t = min(a3, b3);
			a3 -= t;
			b3 -= t;
		}
		a2 -= b3;
		mn += b3;
		b3 = 0;
		an = min(an, mn);
	}
	cout << an << " " << mx << endl;
	return;
}