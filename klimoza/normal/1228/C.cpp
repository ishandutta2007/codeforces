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
const double eps = 1e-6;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
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

ll bp(ll a, ll k, ll m) {
	ll res = 1;
	while (k) {
		if (k & 1) {
			res *= a;
			res %= m;
		}
		a *= a;
		a %= m;
		k >>= 1;
	}
	return res;
}

void solve() {
	ll x, n;
	cin >> x >> n;
	vector<int> primes;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) {
			primes.push_back(i);
			while (x % i == 0) {
				x /= i;
			}
		}
	}
	if (x != 1) primes.push_back(x);
	ll modd = 1e9 + 7;
	ll ans = 1;
	for (ll i : primes) {
		ll h = i;
		//cout << i << " " << h << endl;
		while (true) {
			ans *= bp(i, n / h, modd);
			//cout << h << " " << i << " " << ans << endl;
			ans %= modd;
			if (h > (n / i)) break;
			h *= i;
		}
	}
	cout << ans << endl;

}