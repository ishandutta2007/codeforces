#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> a) {
	int n = a.size();
	int first = -1;
	int last = -1;
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] == a[i + 1]) {
			if (first < 0) {
				first = i;
			}
			last = i;
		}
	}
	if (first < 0 || first == last) {
		return 0;
	}
	return max(1, last - first - 1);
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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		printf("%d\n", solve(a));
	}
	return 0;
}