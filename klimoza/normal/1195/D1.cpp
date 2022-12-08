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
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll cnt = 1;
		while (a[i]) {
			ans += (a[i] % 10) * 1LL * cnt * 1LL * n;
			ans %= mod;
			ans += (a[i] % 10) * 1LL * (10 * cnt) * 1LL * n;
			ans %= mod;
			a[i] /= 10;
			cnt *= 100;
			cnt %= mod;
		}
	}
	cout << ans << endl;
	return 0;
}