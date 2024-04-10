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
	string s;
	cin >> s;
	vector<pair<int, int>> b;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'B') {
			b.push_back({ 1, a[i] });
		}
		else {
			b.push_back({ a[i], n });
		}
	}
	for (auto w : b) {
		if (w.first > w.second) {
			return 0;
		}
	}
	sort(b.begin(), b.end());
	multiset<int> limits;
	int last = 0;
	for (int val = 1; val <= n; ++val) {
		for (; last < n && b[last].first <= val; ++last) {
			limits.insert(b[last].second);
		}
		if (limits.empty() || *limits.begin() < val) {
			return 0;
		}
		limits.erase(limits.begin());
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
	for (cin >> t; t > 0; --t) {
		if (solve()) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}