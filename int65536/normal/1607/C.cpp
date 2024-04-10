#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef _MSC_VER
	freopen("c.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	for (cin >> t; t > 0; --t) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		int ret = a[0];
		for (int i = 0; i < n - 1; ++i) {
			ret = max(ret, a[i + 1] - a[i]);
		}
		printf("%d\n", ret);
	}
	return 0;
}