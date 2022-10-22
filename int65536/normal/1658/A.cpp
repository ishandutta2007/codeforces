#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	string a;
	cin >> n >> a;
	int result = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == '0') {
			int j = i + 1;
			for (; j < n && a[j] != '0'; ++j);
			if (j < n) {
				if (j == i + 1) {
					result += 2;
				} else if (j == i + 2) {
					result += 1;
				}
			}
		}
	}
	printf("%d\n", result);
}

int main()
{
#ifdef _MSC_VER
	freopen("a.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}