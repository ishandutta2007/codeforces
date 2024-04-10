#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef _MSC_VER
	freopen("f2.in", "r", stdin);
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
			--a[i];
		}
		vector<int> b(n);
		for (int i = 0; i < n; ++i) {
			cin >> b[i];
			--b[i];
		}
		vector<int> c(n);
		for (int i = 0; i < n; ++i) {
			++c[a[i]];
		}
		int maxc = *max_element(c.begin(), c.end());
		int suc = 0;
		for (int top = 0; top < n; ++top) {
			if (c[top] != maxc) {
				continue;
			}
			vector<vector<int>> g(n);
			vector<int> d(n);
			for (int i = 0; i < n; ++i) {
				int x = a[i];
				int y = b[i];
				if (x == top || y == top) {
					continue;
				}
				g[x].push_back(y);
				++d[y];
			}
			vector<int> que;
			for (int i = 0; i < n; ++i) {
				if (d[i] == 0) {
					que.push_back(i);
				}
			}
			for (int cur = 0; cur < que.size(); ++cur) {
				for (int next : g[que[cur]]) {
					--d[next];
					if (d[next] == 0) {
						que.push_back(next);
					}
				}
			}
			if (que.size() == n) {
				suc = 1;
				break;
			}
			break;
		}
		if (suc) {
			printf("AC\n");
		}
		else {
			printf("WA\n");
		}
	}
	return 0;
}