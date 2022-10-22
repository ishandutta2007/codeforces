#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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
		ll c0 = 0;
		ll c1 = 0;
		for (int i = 0; i < n; ++i) {
			int val;
			cin >> val;
			if (val == 0) {
				++c0;
			} else if (val == 1) {
				++c1;
			}
		}
		ll r = (c1 << c0);
		cout << r << endl;
	}
	return 0;
}