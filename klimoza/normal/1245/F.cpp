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
const ld eps = 1e-7;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 9;
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

int maxBit(int n) {
	int cnt = -1;
	while (n) {
		cnt++;
		n >>= 1;
	}
	return cnt;
}

const int L = 32;

int minBit(int n) {
	for (int i = 0; i < L; i++) {
		if ((1 << i) & n)
			return i;
	}
}

ll g(int x, int n) {
	if (n < 0) return 0;
	else if (n == 0) return 1;
	int t = maxBit(n);
	int i = minBit(n);
	for (int j = i + 1; j < L; j++) {
		if (((1 << j) & n) && ((1 << j) & x))
			return g(x, n - (1 << i));
	}
	ll ans = g(x, n - (1 << i)) - 1;
	ll res = 1;
	for (int j = i - 1; j >= 0; j--) {
		if (((1 << j) & x) == 0)
			res <<= 1;
	}
	ans += res;
	if (((1 << i) & x) == 0) ans++;
	return ans;
}

ll f(int l, int r) {
	//cout << l << "  " << r << endl;
	if (l == 0)
		return 2 * 1ll * r - 1 + f(l + 1, r);
	if (l == r) {
		if (!l) return 1;
		else return 0;
	}
	if (l & 1) {
		ll kek = f(l + 1, r);
		//cout << kek << endl;
		return kek + 2 * (g(l, r - 1) - g(l, l - 1));
	}
	if (r & 1) {
		return f(l, r - 1) + 2 * (g(r - 1, r - 1) - g(r - 1, l - 1));
	}
	return 3 * f(l >> 1, r >> 1);
}

void solve() {
	int t; cin >> t;
	while (t--) {
		int l, r; cin >> l >> r;
		cout << f(l, r + 1) << endl;
	}
	return;
}