#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int solve(const string& s) {
	int n = s.size();
	if (s[0] != 'A') {
		return 0;
	}
	if (s[n - 1] != 'B') {
		return 0;
	}
	vector<int> a;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'A') {
			a.push_back(i);
		} else {
			if (a.empty()) {
				return 0;
			}
			a.pop_back();
		}
	}
	return 1;
}

int main()
{
#ifdef _MSC_VER
	freopen("b.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		if (solve(s)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}