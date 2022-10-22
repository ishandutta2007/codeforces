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
		string a, b;
		cin >> a >> b;
		vector<vector<int>> c(2, vector<int>(2));
		for (int i = 0; i < a.size(); ++i) {
			++c[a[i] - '0'][b[i] - '0'];
		}
		int ret = 2 * n + 1;
		if (c[0][1] == c[1][0]) {
			ret = min(ret, c[0][1] * 2);
		} 
		if (c[0][0] == c[1][1] - 1) {
			ret = min(ret, c[0][0] * 2 + 1);
		}
		if (ret > 2 * n) {
			ret = -1;
		}
		printf("%d\n", ret);
	}
	return 0;
}