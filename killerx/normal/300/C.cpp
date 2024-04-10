#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mod = 1e9 + 7;
int qp(int x, int n) {
	int ans = 1;
	for (; n; n >>= 1, x = 1LL * x * x % mod)
		if (n & 1) ans = 1LL * ans * x % mod;
	return ans;
}
int inv(int x) {return qp(x, mod - 2);}

const int maxn = 1e6 + 5;
int fac[maxn], ifac[maxn];
int C(int n, int m) {
	return 1LL * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

bool check(int a, int b, int x) {
	for (; x; x /= 10) if (x % 10 != a && x % 10 != b) return 0;
	return 1;
}

int main() {
	rep(i, maxn) fac[i] = i ? 1LL * i * fac[i - 1] % mod : 1;
	ifac[maxn - 1] = inv(fac[maxn - 1]);
	for (int i = maxn - 1; i; -- i)
		ifac[i - 1] = 1LL * i * ifac[i] % mod;
	int a, b, n;
	scanf("%d %d %d", &a, &b, &n);
	int ans = 0;
	rep(i, n + 1) {
		int sum = a * i + b * (n - i);
		if (check(a, b, sum)) (ans += C(n, i)) %= mod;
	}
	printf("%d\n", ans);
	return 0;
}