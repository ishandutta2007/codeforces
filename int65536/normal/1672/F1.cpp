#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef _MSC_VER
	freopen("f1.in", "r", stdin);
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
			--a[i];
		}
		vector<int> c(n);
		vector<vector<int>> d(n);
		for (int i = 0; i < n; ++i) {
			d[c[a[i]]++].push_back(i);
		}
		vector<int> r(n);
		for (vector<int> p : d) {
			int n = p.size();
			if (n > 0) {
				sort(p.begin(), p.end(), [&](int x, int y) { return a[x] < a[y]; });
				for (int i = 0; i < n; ++i) {
					r[p[(i + 1) % n]] = a[p[i]];
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			if (i > 0) {
				printf(" ");
			}
			printf("%d", r[i] + 1);
		}
		printf("\n");
	}
	return 0;
}