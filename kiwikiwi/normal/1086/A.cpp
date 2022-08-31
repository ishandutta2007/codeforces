#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

pair<int, int> p[10];
set<pair<int, int>> ans;

int main() {
	for (int i = 0; i < 3; i++) {
		scanf("%d%d", &p[i].first, &p[i].second);
	}
	sort(p, p + 3);
	auto findpath = [&](pair<int, int> a, pair<int, int> b) {
		if (a.first < b.first) {
			for (int i = a.first; i < b.first; i++)
				ans.insert(make_pair(i, a.second));
		} else {
			for (int i = a.first; i > b.first; i--)
				ans.insert(make_pair(i, a.second));
		}
		if (a.second < b.second) {
			for (int i = a.second; i <= b.second; i++)
				ans.insert(make_pair(b.first, i));
		} else {
			for (int i = a.second; i >= b.second; i--)
				ans.insert(make_pair(b.first, i));
		}

	};
	findpath(p[0], p[1]);
	findpath(p[2], p[1]);
	printf("%d\n", (int)ans.size());
	for (auto p : ans) {
		printf("%d %d\n", p.first, p.second);
	}
}