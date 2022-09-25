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

const int maxn = 8;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
ll a[maxn];
int b[maxn];
int dp[1 << maxn];

int getmax(int mask) {
	int res = -1;
	for (int i = 0; i < n; i++) if (mask & (1 << i)) res = i;
	return res;
}

int cur, res;
vector<int> v;

int getdp(int mask);

void rec(int mask) {
	if (!mask) {
		ll x = 1;
		int y = b[cur];
		for (int i = 0; i < v.size(); i++) x *= a[getmax(v[i])], y -= b[getmax(v[i])];
		if (!(x != 0 && a[cur] % x == 0)) return;
		int Res = 1;
		if (b[cur] != 1) Res += y;
		for (int i = 0; i < v.size(); i++) {
			int z = getdp(v[i]);
			if (z == -1) return;
			Res += z;
		}
		res = min(res, Res);
		return;
	}

	for (int s = mask; s; s = (s - 1) & mask) {
		v.push_back(s);
		rec(mask ^ s);
		v.pop_back();
	}
}

int getdp(int mask) {
	if (dp[mask] != -1) return dp[mask];
	res = inf;
	cur = getmax(mask);
	rec(mask ^ (1 << cur));
	dp[mask] = res;
}

int o;

void rec2(int mask) {
	if (!mask) {
		int res = 0;
		for (int i = 0; i < v.size(); i++) {
			int z = getdp(v[i]);
			if (z == -1 || z > 1e8) return;
			res += z;
		}
		o = min(o, res + 1);
		return;
	}
	for (int s = mask; s; s = (s - 1) & mask) {
		v.push_back(s);
		rec2(mask ^ s);
		v.pop_back();
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n) {
		memset(b, 0, sizeof(b));
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n; i++) {
			ll x = a[i];
			for (int j = 2; 1LL * j * j <= x; j++) {
				while (x % j == 0) {
					x /= j;
					b[i]++;
				}
			}
			if (x != 1) b[i]++;
		}

		memset(dp, -1, sizeof(dp));
		for (int mask = 1; mask < 1 << n; mask++) getdp(mask);
		int ans = inf;
		if (dp[(1 << n) - 1] != -1) ans = dp[(1 << n) - 1];
		o = inf;
		rec2((1 << n) - 1);
		ans = min(ans, o);
		cout << ans << endl;
	}

	return 0;
}