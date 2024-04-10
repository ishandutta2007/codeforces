#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <memory.h>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

const int maxn = -1;


int main() {
/*#ifndef _ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif*/
	
	int m, k;
	while (scanf("%d%d", &m, &k) == 2) {
		vector<int> vct;
		map<pair<int, int>, bool> mp;
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			vct.push_back(u);
			vct.push_back(v);
			mp[make_pair(u, v)] = 1;
			mp[make_pair(v, u)] = 1;
		}

		sort(vct.begin(), vct.end());
		vct.resize(unique(vct.begin(), vct.end()) - vct.begin());
		for (int i = 0; i < (int)vct.size(); i++) {
			int v = vct[i];
			printf("%d: ", v);

			vector<int> ans;
			int cnt = 0;
			for (int j = 0; j < (int)vct.size(); j++) cnt += mp[make_pair(v, vct[j])];
			for (int j = 0; j < (int)vct.size(); j++) {
				int u = vct[j];
				if (u == v) continue;
				if (mp[make_pair(v, u)]) continue;
				int ccnt = 0;
				for (int kk = 0; kk < (int)vct.size(); kk++) {
					int w = vct[kk];
					ccnt += w != u && w != v && mp[make_pair(u, w)] && mp[make_pair(v, w)];
				}
				if (ccnt * 100 >= cnt * k) {
					ans.push_back(u);
				}
			}
			printf("%d", (int)ans.size());
			for (int j = 0; j < (int)ans.size(); j++) {
				printf(" %d", ans[j]);
			}
			printf("\n");
		}
	}

	return 0;
}