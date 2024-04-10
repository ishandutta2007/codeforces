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
		vector<int> a(256);
		for (int i = 0; i < n; ++i) {
			int v;
			cin >> v;
			++a[v + 128];
		}
		vector<int> b(256);
		for (int i = 0; i < n; ++i) {
			int v;
			cin >> v;
			++b[v + 128];
		}
		for (int i = 1; i < 256; ++i) {
			if (b[i] && a[i - 1]) {
				int c = min(b[i], a[i - 1]);
				b[i] -= c;
				a[i - 1] -= c;
			}
			if (b[i] && a[i]) {
				int c = min(b[i], a[i]);
				b[i] -= c;
				a[i] -= c;
			}
		}
		if (accumulate(a.begin(), a.end(), 0) == 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}