#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

bool cmp(const vector<int> &a, const vector<int> &b) {
	if (a.size() != b.size()) return a.size() < b.size();
	return a < b;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (scanf("%d", &n) == 1) {
		vector<int> p(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &p[i]);
			--p[i];
		}

		vector<char> used(n);
		vector<vector<int> > v;
		for (int i = 0; i < n; i++) {
			if (used[i]) continue;
			vector<int> vct;
			int x = i;
			do {
				used[x] = 1;
				vct.push_back(x);
				x = p[x];
			} while (x != i);
			v.push_back(vct);
		}
		sort(v.begin(), v.end(), cmp);

		if (v[0].size() >= 3) {
			printf("NO\n");
			continue;
		}
		vector<pair<int, int> > ans;
		if (v[0].size() == 2) {
			ans.push_back(make_pair(v[0][0], v[0][1]));
		}

		bool ok = 1;
		for (int i = 1; i < (int)v.size(); i++) {
			if (v[i].size() % v[0].size()) {
				ok = 0;
			}
			else {
				for (int j = 0; j < (int)v[i].size(); j++) {
					ans.push_back(make_pair(v[i][j], v[0][j % v[0].size()]));
				}
			}
		}
		if (!ok) {
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for (int i = 0; i < (int)ans.size(); i++) {
			printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
		}
	}

	return 0;
}