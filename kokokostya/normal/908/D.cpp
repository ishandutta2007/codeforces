



#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

//#define FAST_ALLOCATOR_MEMORY 1e8
#undef LOCAL
//#include "optimization.h"

const int mod = 1000 * 1000 * 1000 + 7;

const int MX = 1007;
vector< vector< long long > > dp(MX, vector<long long>(MX));
long long k, pa, pb;

long long up(long long val, int n) {
	long long now = val;
	long long res = 1;
	while (n) {
		if (n & 1)
			res = (res * now) % mod;
		now = (now * now) % mod;
		n >>= 1;
	}
	return res;
}

long long gcd(long long a, long long b) {
	while (a) {
		b %= a;
		swap(a, b);
	}
	return b;
}

long long is(long long a, long long b) {
	a %= mod;
	b %= mod;
	b = up(b, mod - 2);
	return (a * b) % mod;
}

long long get(int i, int j) {
	if (j <= 0) {
		return -j + k;
	}
	if (i >= j) {
		return is((i - j + k) * pb + pa, pb);
	}
	if (dp[i][j])
		return dp[i][j];
	long long x = get(i + 1, j);
	x = is(x * pa, pa + pb);
	long long y = get(i, j - i);
	y = is(y * pb, pa + pb);
	long long res = (x + y) % mod;

	return dp[i][j] = res;
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> k >> pa >> pb;
	long long d = gcd(pa, pb);
	pa /= d;
	pb /= d;
	long long res = get(1, k);
	cout << res;
	return 0;
}