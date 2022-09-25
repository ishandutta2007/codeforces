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
const int mod = 1000000009;


int pw(int x, int y) {
	if (!y) return 1;
	if (y == 1) return x;
	int res = pw(x, y / 2);
	res = 1LL * res * res % mod;
	if (y % 2) res = 1LL * res * x % mod;
	return res;
}

int slowsolve(int n, int m, int k) {
		if (n - n / k >= m) {
			return m % mod;
		}
		int ost = m - (n - n / k);
		int res = 0;
		for (int i = 0; i < ost; i++) {
			res = (res + k) % mod;
			res = (res + res) % mod;
		}
		res = (pw(2, ost + 1) - 2 + mod) % mod;
		res = 1LL * res * k % mod;

		res += n - n / k - ost * (k - 1);
		res %= mod;
		return res;
}

int fastsolve(int n, int m, int k) {
		if (n - n / k >= m) {
			return m % mod;
		}
		int ost = m - (n - n / k);
		int res = 0;
		res = (pw(2, ost + 1) - 2 + mod) % mod;
		res = 1LL * res * k % mod;

		res += n - n / k - ost * (k - 1);
		res %= mod;
		return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m, k;
	/*for (int it = 0; it < 10000; it++) {
		n = rand() % 2000 + 1;
		m = rand() % n;
		k = rand() % n + 1;
		if (fastsolve(n, m, k) != slowsolve(n, m, k)) {
			cout << "fail";
			exit(0);
		}
	}*/
	while (cin >> n >> m >> k) {
		cout << fastsolve(n, m, k) << endl;
	}

	return 0;
}