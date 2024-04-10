#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef _MSC_VER
	freopen("f.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	for (cin >> t; t > 0; --t) {
		int sx;
		int sy;
		cin >> sx >> sy;
		vector<string> a(sx);
		for (int x = 0; x < sx; ++x) {
			cin >> a[x];
		}
		int n = sx * sy;
		vector<int> next(n);
		for (int x = 0; x < sx; ++x) {
			for (int y = 0; y < sy; ++y) {
				int next_x = x;
				int next_y = y;
				if (a[x][y] == 'L') {
					--next_y;
				} else if (a[x][y] == 'R') {
					++next_y;
				} else if (a[x][y] == 'U') {
					--next_x;
				} else {
					++next_x;
				}
				if (next_x < 0 || next_x >= sx || next_y < 0 || next_y >= sy) {
					next[x * sy + y] = -1;
				} else {
					next[x * sy + y] = next_x * sy + next_y;
				}
			}
		}
		vector<int> d(n);
		for (int p : next) {
			if (p >= 0) {
				++d[p];
			}
		}
		vector<int> q;
		for (int i = 0; i < n; ++i) {
			if (d[i] == 0) {
				q.push_back(i);
			}
		}
		for (int i = 0; i < q.size(); ++i) {
			int cur = q[i];
			int z = next[cur];
			if (z >= 0) {
				--d[z];
				if (d[z] == 0) {
					q.push_back(z);
				}
			}
		}
		vector<int> ret(n, -1);
		for (int i = 0; i < n; ++i) {
			if (d[i] > 0 && ret[i] < 0) {
				int count = 1;
				for (int j = next[i]; j != i; j = next[j]) {
					++count;
				}
				ret[i] = count;
				for (int j = next[i]; j != i; j = next[j]) {
					ret[j] = count;
				}
			}
		}
		for (int i = q.size() - 1; i >= 0; --i) {
			int cur = q[i];
			int z = next[cur];
			if (z < 0) {
				ret[cur] = 1;
			} else {
				ret[cur] = ret[z] + 1;
			}
		}
		int at = max_element(ret.begin(), ret.end()) - ret.begin();
		printf("%d %d %d\n", at / sy + 1, at % sy + 1, ret[at]);
	}
	return 0;
}