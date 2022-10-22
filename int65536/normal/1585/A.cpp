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
		int h = 1;
		for (int i = 0; i < n; ++i) {
			if (a[i]) {
				if (i > 0 && a[i - 1]) {
					h += 5;
				} else {
					h += 1;
				}
			} else if (i > 0 && !a[i - 1]) {
				h = -1;
				break;
			}			
		}
		printf("%d\n", h);
	}
	return 0;
}