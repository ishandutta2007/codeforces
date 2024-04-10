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


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, k, q;
	while (scanf("%d%d%d", &n, &k, &q) == 3) {
		vector<int> t(n);
		for (int i = 0; i < n; i++) scanf("%d", &t[i]);

		vector<pair<int, int> > vct;
		for (int i = 0; i < q; i++) {
			int type, id;
			scanf("%d%d", &type, &id);
			--id;
			if (type == 1) {
				vct.push_back(make_pair(-t[id], id));
				if (vct.size() > k) {
					sort(vct.begin(), vct.end());
					vct.pop_back();
				}
			}
			if (type == 2) {
				bool res = 0;
				for (int i = 0; i < (int)vct.size(); i++) {
					if (vct[i].second == id) {
						res = 1;
					}
				}
				if (res) printf("YES\n");
				else printf("NO\n");
			}
		}
	}

	return 0;
}