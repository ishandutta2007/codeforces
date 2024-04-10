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


string a;
int k;

int pw(int x, ll y) {
	if (y == 0) return 1;
	if (y == 1) return x % mod;
	int res = pw(x, y / 2);
	res = 1LL * res * res % mod;
	if (y & 1) res = 1LL * res * x % mod;
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> a >> k) {
		int n = a.length();
		ll ans = 0;
		for (int i = a.length() - 1; i >= 0; i--) {
			if (a[i] == '5' || a[i] == '0') {
				int res = 0;
				res = pw(2, 1LL * n * k) - 1; if (res < 0) res += mod;
				int o = pw(2, n) - 1; if (o < 0) o += mod;
				res = 1LL * res * pw(o, mod - 2) % mod;
				res = 1LL * res * pw(2, i) % mod;
				ans += res;
				//ans += pw(2, 1LL * i * n * k);
				//ans -= pw(2, 1LL * i * n);
				while (ans >= mod) ans -= mod;
				while (ans < 0) ans += mod;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}