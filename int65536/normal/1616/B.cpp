#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef _MSC_VER
	freopen("b.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		string ret;
		auto update = [&](int at) {
			string x = s.substr(0, at + 1);
			string y = x;
			reverse(y.begin(), y.end());
			x += y;
			if (ret.empty() || x < ret) {
				ret = x;
			}
		};
		update(0);
		update(n - 1);
		for (int i = 0; i + 1 < n; ++i) {
			if (s[i] < s[i + 1]) {
				update(i);
				break;
			}
			if (s[i] > s[i + 1]) {
				update(i + 1);
			}
		}
		printf("%s\n", ret.c_str());
	}
	return 0;
}