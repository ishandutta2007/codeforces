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

using namespace std;

int m, c;
const long double eps = 1e-7;

long double g(long double a, long double b) {
	return (a + 1) * (b + 1) * (a + b) / 2;
}

long double f(long double x) {
	return g(x, m * (c - x));
}

long long g_whole(long long a, long long b) {
	return (a + 1) * (b + 1) * (a + b) / 2;
}

long long f_whole (long long x) {
	return g_whole (x, m * (c - x));
}

int main() {
	ios_base::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> m >> c;
	long double l = 0, r = c;
	for (int j = 0; j < 100; j++) { // ternary search
		long double lm = (2 * l + r) / 3, rm = (l + 2 * r) / 3;
		if (f(lm) > f(rm))
			r = rm;
		else
			l = lm;
	}
	int xl = int(l - 1e-1);
	int xr = xl + 1;
	cout << max(f_whole(xl), f_whole(xr));
	return 0;
}