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

mt19937 mrand(random_device{}());
//mt19937 mrand(228);

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
	int t; cin >> t;
	while (t--) {
		ll a, b, c, d; cin >> a >> b >> c >> d;
		if (c <= d) {
			if (a > c * b) cout << -1 << endl;
			else {
				cout << a << endl;
			}
		}
		else {
			if (a > c * b) cout << -1 << endl;
			else {
				ll t = max(0ll, (2 * a - d * b) / (2 * d * b));
				ll ans1 = -(t * (t + 1) / 2 * d * b - (t + 1) * a);
				t = max(0ll, (2 * a - d * b + 2 * d * b - 1) / (2 * d * b));
				ll ans2 = -(t * (t + 1) / 2 * d * b - (t + 1) * a);
				cout << max(ans1, ans2) << endl;
			}
		}
	}
	return;
}