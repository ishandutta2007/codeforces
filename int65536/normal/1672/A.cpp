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
		int sg = 0;
		for (int i = 0; i < n; ++i) {
			int m;
			cin >> m;
			sg ^= (m + 1) % 2;
		}
		if (sg == 0) {
			printf("maomao90\n");
		} else {
			printf("errorgorn\n");
		}
	}
	return 0;
}