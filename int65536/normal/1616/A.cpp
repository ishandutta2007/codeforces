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
		unordered_set<int> s;
		for (int i = 0; i < n; ++i) {
			int v;
			cin >> v;
			if (!s.count(v)) {
				s.insert(v);
			} else {
				s.insert(-v);
			}
		}
		printf("%d\n", s.size());
	}
	return 0;
}