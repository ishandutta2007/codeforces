#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXK = -1;
const int MAXN = -1;
const int MOD = 1000 * 1000 * 1000 + 7;

ll gcd(ll a, ll b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

ll f(ll n) {
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		ans += gcd(i, n - i) == 1;
	}
	return ans;
}

ll g(ll n) {
	ll ans = 0;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ans += f(i);
			if (i * i != n) ans += f(n / i);
		}
	}
	return ans;
}

ll phi(ll n) {
	ll res = n;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0) n /= i;
			res -= res / i;
		}
	}
	if (n > 1) res -= res / n;
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	//for (int i = 1; i <= 20; i++) cout << f(i) << " " << phi(i) << endl;

	ll n, k;
	while (cin >> n >> k) {
		while (k > 0 && n > 1) {
			if (k % 2 == 0) {
				k--;
			}
			else {
				k--;
				n = phi(n);
			}
		}
		cout << n % MOD << endl;
	}

	return 0;
}