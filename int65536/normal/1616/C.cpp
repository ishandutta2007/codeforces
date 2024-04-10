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
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		int ret = n - 1;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int count = 0;
				for (int k = 0; k < n; ++k) {
					if ((a[k] - a[i]) * (j - i) != (a[j] - a[i]) * (k - i)) {
						++count;
					}
				}
				ret = min(ret, count);
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}