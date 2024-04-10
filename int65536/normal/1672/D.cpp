#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> a, vector<int> b) {
	int n = a.size();
	vector<int> c(n + 1);
	int p = 0;
	for (int i = 0; i < n; ++i) {
		while (1) {
			if (p >= n) {
				return 0;
			}
			if (a[p] != b[i]) {
				++c[a[p]];
				++p;
				continue;
			}
			if (i + 1 < n && b[i + 1] == b[i] && c[b[i]] > 0) {
				--c[b[i]];
			} else {
				++p;
			}
			break;
		}
	}
	return 1;
}

int main()
{
#ifdef _MSC_VER
	freopen("d.in", "r", stdin);
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
		vector<int> b(n);
		for (int i = 0; i < n; ++i) {
			cin >> b[i];
		}
		if (solve(a, b)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}