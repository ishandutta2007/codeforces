#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

#define size(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

using namespace std;

typedef long long ll;

const ll inf0 = 2 * 1024 * 1024 * 1023;
const ll inf = inf0 * inf0;
const double eps = 1e-6;
const ll mod = 998244353;

mt19937 mrand(random_device{} ());

ll len(ll a) {
	ll cnt = 0;
	while (a) {
		cnt++;
		a /= 10;
	}
	return cnt;
}

ll pw(ll a, ll b) {
	if (b == 0) return 1;
	return (pw(a, b - 1) * a) % mod;
}

ll smart(ll n, vector<ll> a) {
	ll ans = 0;
	vector<ll> cn(12);
	for (int i = 0; i < n; i++) {
		ll l = len(a[i]);
		cn[l]++;
	}
	vector<ll> pref(12);
	for (int i = 1; i < 12; i++) {
		pref[i] = pref[i - 1] + cn[i];
	}
	for (int i = 0; i < n; i++) {
		ll cnt = 1;
		ll ff = 1;
		while (a[i]) {
			ll h = pref[11] - pref[ff - 1];
			ans += (a[i] % 10) * 1LL * cnt * 1LL * h;
			ans %= mod;
			ans += (a[i] % 10) * 1LL * (10 * cnt) * 1LL * h;
			ans %= mod;
			for (int j = 0; j < ff; j++) {
				ans += 2 * (((((((a[i] % 10) * pw(10, ff - 1)) % mod) * pw(10, j)) % mod) * cn[j]) % mod);
				ans %= mod;
			}
			a[i] /= 10;
			cnt *= 100;
			cnt %= mod;
			ff++;
		}
	}
	return ans;
}



int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout.precision(15);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a) cin >> i;
	cout << smart(n, a) << endl;
	return 0;
}