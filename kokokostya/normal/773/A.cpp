#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <iomanip>

using namespace std;

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int test;
	cin >> test;
	while (test--) {
		long long x, y, p, q;
		cin >> x >> y >> p >> q;
		if (x != y && p == q) {
			cout << -1 << '\n';
			continue;
		}
		if (p == 0 && x != 0) {
			cout << -1 << '\n';
			continue;
		}
		long long d1 = (x == 0 ? 0 : (x - 1) / p + 1);
		long long d2 = ((y - 1) / q + 1);
		long long l = max(d1, d2) - 1, r = 1e9;
		while (l != r - 1) {
			long long m = (l + r) / 2;
			long long f1 = m * p, f2 = m * q;
			if (f1 - x <= f2 - y)
				r = m;
			else
				l = m;
		}
		cout << r * q - y << '\n';
	}

	return 0;
}