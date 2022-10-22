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
	for (cin >> t; t > 0; --t) {
		string a, s;
		cin >> a >> s;
		int ret = 0;
		for (int i = 0; i + 1 < s.size(); ++i) {
			ret += abs((int)a.find(s[i]) - (int)a.find(s[i + 1]));
		}
		printf("%d\n", ret);
	}
	return 0;
}