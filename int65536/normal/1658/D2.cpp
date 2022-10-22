#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int solve() {
	int l;
	int r;
	cin >> l >> r;
	int n = r - l + 1;
	map<int, int> d;
	for (int i = 0; i < n; ++i) {
		int val;
		cin >> val;
		std::function<void(int, int)> dfs = [&](int offset, int cur) {
			int w = (cur >> offset) ^ (val >> offset);
			int min_w = (w << offset);
			int max_w = ((w + 1) << offset) - 1;
			if (min_w > r || max_w < l) {
				++d[cur];
				--d[cur + (1 << offset)];
				return;
			}
			if (min_w >= l && max_w <= r) {
				return;
			}
			assert(offset > 0);
			dfs(offset - 1, cur);
			dfs(offset - 1, cur + (1 << (offset - 1)));
		};
		dfs(17, 0);
	}
	if (d.empty() || d.begin()->first > 0) {
		return 0;
	}
	int s = 0;
	for (auto p : d) {
		s += p.second;
		if (s == 0) {
			return p.first;
		}
	}
	return (1 << 17);
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
		printf("%d\n", solve());
	}
	return 0;
}