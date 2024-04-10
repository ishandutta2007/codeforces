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

void solve() {
	int t; cin >> t;
	while (t--) {
		int n0, n1, n2; cin >> n0 >> n1 >> n2;
		if (!n0 && !n1) {
			for (int i = 0; i < (n2 + 1); i++)
				cout << 1;
		}
		else if (!n1 && !n2) {
			for (int i = 0; i < (n0 + 1); i++)
				cout << 0;
		}
		else if (!n0 && !n2) {
			if (n1 % 2 == 0) {
				cout << 0;
			}
			for (int i = 0; i < ((n1 + 1) / 2); i++)
				cout << 10;
		}
		else {
			for (int i = 0; i < (n0 + 1); i++)
				cout << 0;
			for (int i = 0; i < n2 + 1; i++)
				cout << 1;
			n1--;
			//cout << n1 / 2 << endl;
			for (int i = 0; i < n1 / 2; i++)
				cout << "01";
			if (n1 & 1)
				cout << 0;
		}
		cout << endl;
	}
	return;
}