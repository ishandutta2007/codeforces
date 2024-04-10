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

using namespace std;

#define ll long long

const int maxn = 1 << 17;
const int mod = 1000000007;
const int inf = 1 << 30;

#pragma comment(linker, "/STACK:16000000")

int a[40] = {2,3,5,7,13,17,19,31,61,89,107,127,521,607,1279,2203,2281,3217,4253,4423,9689,9941,11213,19937,21701,23209,44497,
             86243,110503,132049,216091,756839,859433,1257787,1398269,2976221,3021377,6972593,13466917,20996011};

int n;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	ll ans = 1;
	for (int i = 1; i < a[n-1]; i++) {
		ans *= 2;
		if (ans >= mod) ans -= mod;
	}
	ans = (ans - 1 + mod) % mod;
	cout << ans << endl;

	return 0;
}