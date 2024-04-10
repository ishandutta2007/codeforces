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


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 20;
const int mod = 1000000007;

int a, b, n, ans;
int f[maxn];

bool good(int x) {
	while (x) {
		if (x % 10 != a && x % 10 != b) return 0;
		x /= 10;
	}
	return 1;
}

int Pow(int n, int k) {
	if (!k) return 1;
	if (k == 1) return n % mod;
	int res = Pow(n, k / 2);
	res = 1LL * res * res % mod;
	if (k & 1)
		res = 1LL * res * n % mod;
	return res;
}

int c(int k, int n) {
	int res = 1;
	res = 1LL * res * f[n] % mod;
	res = 1LL * res * Pow(f[k], mod - 2) % mod;
	res = 1LL * res * Pow(f[n - k], mod - 2) % mod;
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	f[0] = 1;
	for (int i = 1; i < maxn; i++) f[i] = 1LL * f[i - 1] * i % mod;

	cin >> a >> b >> n;
	for (int i = 0; i <= n; i++) {
		int j = n - i;
		int sum = a * i + b * j;
		if (good(sum)) {
			ans = (ans + c(i, n)) % mod;
		}
	}
	cout << ans << endl;

	return 0;
}