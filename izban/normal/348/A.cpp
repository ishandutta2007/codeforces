#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n, a[maxn];
ll sum;

bool f(ll x) {
	ll res = 0;
	for (int i = 0; i < n; i++) {
		res += x - a[i];
	}
	return res >= sum || res * (n - 1) >= sum || 1.0 * res * (n - 1) >= sum;
}

bool g(ll x) {
	ll res = 0;
	for (int i = 0; i < n; i++) {
		res += x - a[i];
	}
	return res >= x && x * (n - 1) >= sum;
}

ll solve1() {
	sum = 0;
	sort(a, a + n);
	ll l = a[n - 1], r = 2.1e9;
	while (r - l > 1) {
		ll m = (l + r) >> 1;
		if (f(m)) {
			r = m;
		} else {
			l = m;
		}
	}
	if (f(l)) return l;
	return r;
}

ll solve2() {
	sum = 0;
	sort(a, a + n);
	ll l = a[n - 1], r = 2.1e9;
	while (r - l > 1) {
		ll m = (l + r) >> 1;
		if (g(m)) {
			r = m;
		} else {
			l = m;
		}
	}
	if (g(l)) return l;
	return r;
}

void gen() {
	n = rand() % 5 + 3;
	for (int i = 0; i < n; i++) a[i] = rand() % 5 + 1;
}

void stress(bool f) {
	if (!f) return;
	for (int it = 0; it < 10000; it++) {
		gen();
		ll ans1 = solve1();
		ll ans2 = solve2();
		if (ans1 != ans2) {
			cout << ans1 << " instead of " << ans2 << endl;
			cout << n << endl;
			for (int i = 0; i < n; i++) cout << a[i] << " \n"[i + 1 == n];
			break;
		}
		cerr << it << endl;
	}
	exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	stress(0);

	while (cin >> n) {
		for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];

		cout << solve2() << endl;
	}

	return 0;
}