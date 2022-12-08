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

ll bp(ll a, ll k) {
	ll res = 1;
	while (k) {
		if (k & 1) {
			res = res * a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		k >>= 1;
	}
	return res;
}

ll f(ll a) {
	return (a * (a + 1) / 2) % mod;
}

void solve() {
	ll n, m, a; cin >> n >> m >> a;
	vector<ll> b(m);
	for (ll& i : b) cin >> i;
	ll ans = (bp(a, n - 2 * b.back()) * f(bp(a, b[0]))) % mod;
	for (int i = 1; i < m; i++) {
		ans *= f(bp(a, b[i] - b[i - 1]));
		ans %= mod;
	}
	cout << ans << endl;
}