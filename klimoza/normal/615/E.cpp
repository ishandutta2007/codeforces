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

ll f(ll x) {
	return x * (10 + (x - 1) * 6) / 2;
}

void solve() {
	ll n; cin >> n;
	ll tp = 0;
	ll l = 0, r = 1e9;
	if (n < 5) tp = 0;
	else {
		while (r - l > 1) {
			ll mid = (l + r) / 2;
			if (f(mid) <= n) l = mid;
			else r = mid;
		}
		tp = l;
	}
	ll x = tp, y = -2 * tp;
	if(tp)
	n -= f(tp);
	ll h = min(n, tp + 1);
	n -= h;
	x += h, y += 2 * h;
	h = min(n, tp);
	n -= h;
	x -= h, y += 2 * h;
	h = min(n, tp + 1);
	n -= h;
	x -= 2 * h;
	h = min(n, tp + 1);
	n -= h;
	x -= h, y -= 2 * h;
	h = min(n, tp + 1);
	n -= h;
	x += h, y -= 2 * h;
	h = min(n, tp + 1);
	x += 2 * h;
	cout << x << " " << y << endl;
}