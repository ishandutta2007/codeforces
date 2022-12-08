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

ll bp(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) {
			res = (res * a) % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

void solve() {
	ll n, m, l, r;
	cin >> n >> m >> l >> r;
	ll k = r - l + 1;
	if (n * m & 1ll) cout << bp(k, n * m ) << endl;
	else if (k & 1ll) cout << (bp(k, n * m) + 1) * bp(2, mod - 2) % mod << endl;
	else cout << bp(k, n * m) * bp(2, mod - 2) % mod << endl;
	return;
}