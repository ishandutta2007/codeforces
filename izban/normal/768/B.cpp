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
const int MOD = 0; // 1000 * 1000 * 1000 + 7;

map<ll, ll> len;

ll getLen(ll x) {
	if (len.count(x)) return len[x];
	if (x <= 1) return 1;
	return len[x] = 2 * getLen(x / 2) + 1;
}

int cnt = 0;

void solve(ll n, ll tl, ll tr, ll l, ll r) {
	l = max(l, tl);
	r = min(r, tr);
	if (l > r) {
		return;
	}
	if (tl == tr) {
		cnt += n == 1;
		return;
	}
	ll len = tr - tl + 1;
	ll x = (len - 1) / 2;
	solve(n / 2, tl, tl + x - 1, l, r);
	solve(n % 2, tl + x, tl + x, l, r);
	solve(n / 2, tl + x + 1, tl + x + x, l, r);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	/*for (int i = 1; i <= 100; i++) {
		cerr << i << " " << getLen(i) << endl;
	}*/

	ll n, l, r;
	while (cin >> n >> l >> r) {
		cnt = 0;
		solve(n, 1, getLen(n), l, r);
		cout << cnt << endl;
	}

	return 0;
}