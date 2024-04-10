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

const int MAXK = -1;
const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (scanf("%d", &n) == 1) {
		vector<int> a(n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		sort(a.begin(), a.end());

		vector<int> b;
		for (int i = 0; i < n; i++) {
			int x = a[i];
			while (x) {
				b.push_back(x);
				x /= 2;
			}
		}
		sort(b.begin(), b.end());
		b.resize(unique(b.begin(), b.end()) - b.begin());

		vector<vector<int> > c(n);
		for (int i = 0; i < n; i++) {
			int x = a[i];
			while (x) {
				c[i].push_back(lower_bound(b.begin(), b.end(), x) - b.begin());
				x /= 2;
			}
		}

		vector<int> used(b.size(), 0);
		int tmr = 0;

		int l = -1, r = (int)b.size();
		while (r - l > 1) {
			int m = (l + r) / 2;

			tmr++;
			bool ok = 1;
			for (int i = n - 1; i >= 0; i--) {
				int j = 0;
				while (j < (int)c[i].size() && (c[i][j] > m || used[c[i][j]] == tmr)) j++;
				if (j < (int)c[i].size()) used[c[i][j]] = tmr;
				else ok = 0;
			}
			if (ok) r = m;
			else l = m;
		}
		tmr++;
		bool ok = 1;
		for (int i = n - 1; i >= 0; i--) {
			int j = 0;
			while (j < (int)c[i].size() && (c[i][j] > r || used[c[i][j]] == tmr)) j++;
			if (j < (int)c[i].size()) used[c[i][j]] = tmr;
			else ok = 0;
		}
		assert(ok);

		vector<int> ans;
		for (int i = 0; i < (int)b.size(); i++) if (used[i] == tmr) ans.push_back(b[i]);
		assert((int)ans.size() == n);

		for (int i = 0; i < n; i++) {
			printf("%d%c", ans[i], " \n"[i + 1 == n]);
		}
	}

	return 0;
}