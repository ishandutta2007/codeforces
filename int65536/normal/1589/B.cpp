#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int calc(int n) {
	if (n % 3 == 0){
		return n / 3;
	}
	return n / 3 + 1;
}

int solve(int n, int m, int depth) {
	if (n * m <= 1) {
		return 1e9;
	}
	int ret = 1e9;
	if (m > 1) {
		ret = min(ret, n * calc(m));
	}
	if (n > 1) {
		ret = min(ret, m * calc(n));
	}
	if (depth < 2) {
		if (m > 1) {
			for (int i = 1; i < n && i <= 4; ++i) {
				ret = min(ret, solve(n - i, m, depth + 1) + i * calc(m));
			}
		}
		if (n > 1) {
			for (int i = 1; i < m && i <= 4; ++i) {
				ret = min(ret, solve(n, m - i, depth + 1) + i * calc(n));
			}
		}
	}
	return ret;
}

int main()
{
#ifdef _MSC_VER
	freopen("b.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	for (cin >> t; t > 0; --t) {
		int n, m;
		cin >> n >> m;
		cout << solve(n, m, 0) << endl;
	}
	return 0;
}