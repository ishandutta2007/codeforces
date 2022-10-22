#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef _MSC_VER
	freopen("a.in", "r", stdin);
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
		int r = 0;
		int h = a[n - 1];
		for (int i = n - 2; i >= 0; --i) {
			if (a[i] > h) {
				h = a[i];
				++r;
			}
		}
		printf("%d\n", r);
	}
	return 0;
}