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
		int s = 0;
		for (int i = 0; i < n; ++i) {
			int h;
			cin >> h;
			s += h;
		}
		printf("%d\n", s % n ? 1 : 0);
	}
	return 0;
}