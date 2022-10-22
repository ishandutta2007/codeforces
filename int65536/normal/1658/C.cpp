#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	reverse(a.begin(), a.end());
	int p = -1;
	for (int i = 0; i < n; ++i) {
		if (a[i] == 1) {
			p = i;
		}
	}
	if (p < 0) {
		return 0;
	}
	for (int i = 0; i < n - 1; ++i) {
		int cur = a[(p - i + n) % n];
		int prev = a[(p - i - 1 + n) % n];
		if (prev == 1) {
			return 0;
		}
		if (prev > cur + 1) {
			return 0;
		}
	}
	return 1;
}

int main()
{
#ifdef _MSC_VER
	freopen("c.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		if (solve()) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}