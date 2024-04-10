#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

#define MOD (998244353)

int solve(int n) {
	if (n == 1) return 0;
	if (n == 2) return 1;
	if (n == 3) return 0;
	if (n == 4) return 4;
	if (n == 5) return 0;
	if (n == 6) return 36;
	if (n % 2 == 1) return 0;
	long long ret = 1;
	for (int i = 1; i <= n / 2; ++i) {
		ret = ret * i % MOD;
	}
	ret = ret * ret % MOD;
	return (int)ret;
}

int main()
{
#ifdef _MSC_VER
	freopen("b.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}