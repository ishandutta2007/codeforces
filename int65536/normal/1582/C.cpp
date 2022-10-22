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
		string a;
		cin >> n >> a;
		int r = n + 1;
		for (char c = 'a'; c <= 'z'; ++c) {
			int tot = 0;
			int s = 0;
			int t = n - 1;
			while (s < t) {
				if (a[s] == a[t]) {
					++s;
					--t;
				}
				else if (a[s] == c) {
					++tot;
					++s;
				}
				else if (a[t] == c) {
					++tot;
					--t;
				}
				else {
					tot = n + 1;
					break;
				}
			}
			r = min(r, tot);
		}
		if (r > n) {
			r = -1;
		}
		printf("%d\n", r);
	}
	return 0;
}