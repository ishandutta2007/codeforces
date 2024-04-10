#include <unordered_map>
#include <unordered_set>
#include <functional>
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
const int MAXN = 1 << MAXK;
const int MOD = 0; // 1000 * 1000 * 1000 + 7;
const int INF = 1.01e9;

ll solve(ll x, ll y, ll p, ll q) {
	if (x > 0 && p == 0) return -1;
	if (x < y && p == q) return -1;
	// min k: p*k >= x, q*k >= y, 0 <= p*k-x <= q*k-y
	ll L = -1, R = INF;
	while (R - L > 1) {
		ll k = (L + R) / 2;
	
		bool ok = 1;
		ok &= p * k >= x;
		ok &= q * k >= y;
		ok &= 0 <= p * k - x;
		ok &= p * k - x <= q * k - y;

		if (ok) R = k;
		else L = k;
	}
	return R * q - y;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	
	int T;
	cin >> T;
	while (T--) {
		ll x, y, p, q;
		cin >> x >> y >> p >> q;
		cout << solve(x, y, p, q) << endl;
	}

	return 0;
}