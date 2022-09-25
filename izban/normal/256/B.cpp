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

const int maxn = 1 << 12, maxk = 1 << 20;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[5] = {1, 0, -1, 0, 1};
const int dy[5] = {0, 1, 0, -1, 0};

int n, x, y;
ll c;

ll abs1(ll x) {
	return x >= 0 ? x : -x;
}

/*ll g(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll res = 0;
	ll d = abs1(x1 - x2) + abs1(y1 - y2) + 1;
	res = d * (d + 1) / 2;

}*/

ll h(ll k) {
	return k * (k + 1) / 2;
}

ll g(int x, int y, int t, int k) {
	if (!(1 <= x && x <= n && 1 <= y && y <= n)) return 0;
	ll res = h(t);
	if (k == 0) {
		if (n - x < t) res -= h(t - (n - x + 1));
		if (n - y < t) res -= h(t - (n - y + 1));
		if ((n + 1 - x) + (n + 1 - y) < t) res += h(t - (n + 1 - x) - (n + 1 - y));
	}
	if (k == 1) {
		if (x < t)		res -= h(t - x);
		if (n - y < t)	res -= h(t - (n - y + 1));
		if (x + (n + 1 - y) < t) res += h(t - x - (n + 1 - y));
	}
	if (k == 2) {
		if (x < t)		res -= h(t - x);
		if (y < t)		res -= h(t - y);
		if (x + y < t)	res += h(t - x - y);
	}
	if (k == 3) {
		if (n - x < t)	res -= h(t - (n - x + 1));
		if (y < t)		res -= h(t - y);
		if ((n + 1 - x) + y < t) res += h(t - (n + 1 - x) - y);
	}
	return res;
}

bool f(int t) {
	if (!t) return 1 >= c;
	ll a = 1;
	a += g(x + 1, y, t, 0);
	a += g(x, y + 1, t, 1);
	a += g(x - 1, y, t, 2);
	a += g(x, y - 1, t, 3);
	/*a += g(x + 1, y, x + t, y, x + 1, y + t - 1);
	a += g(x, y + 1, x, y + t, x - t + 1, y + 1);
	a += g(x - 1, y, x - t, y, x - 1, y - t + 1);
	a += g(x, y - 1, x, y - t, x + t - 1, y - 1);*/
	return a >= c;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n >> x >> y >> c) {
		int l = 0, r = 2e9;
		while (r - l > 1) {
			int m = (l + r) >> 1;
			if (f(m)) r = m;
			else l = m;
		}
		if (f(l)) cout << l << endl;
		else cout << r << endl;
	}

	return 0;
}