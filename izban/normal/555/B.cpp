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

struct item {
	int type;
	int id;
	ll x;

	item() {}
	item(int type, int id, ll x) : type(type), id(id), x(x) {}

	bool operator< (const item &it) const {
		return type < it.type;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, m;
	while (scanf("%d%d", &n, &m) == 2) {
		vector<ll> l(n), r(n);
		for (int i = 0; i < n; i++) {
			scanf("%I64d%I64d", &l[i], &r[i]);
		}
		vector<ll> a(m);
		for (int i = 0; i < m; i++) {
			scanf("%I64d", &a[i]);
		}

		vector<pair<ll, item> > vct;
		for (int i = 1; i < n; i++) {
			vct.push_back(make_pair(l[i] - r[i - 1], item(0, i - 1, r[i] - l[i - 1])));
		}
		for (int i = 0; i < m; i++) {
			vct.push_back(make_pair(a[i], item(1, i, -1)));
		}

		bool bad = 0;
		vector<int> ans(n - 1, -1);
		set<pair<ll, int> > st;
		sort(vct.begin(), vct.end());
		for (int i = 0; i < (int)vct.size(); i++) {
			if (vct[i].second.type == 0) {
				st.insert(make_pair(vct[i].second.x, vct[i].second.id));
			}
			if (vct[i].second.type == 1) {
				if (!st.empty()) {
					pair<ll, int> o = *st.begin();
					st.erase(st.begin());
					if (o.first < vct[i].first) {
						bad = 1;
					} else {
						ans[o.second] = vct[i].second.id + 1;
					}
				}
			}
		}
		bad |= !st.empty();

		if (bad) {
			printf("No\n");
			continue;
		}
		printf("Yes\n");
		for (int i = 0; i < n - 1; i++) printf("%d%c", ans[i], " \n"[i + 1 == n - 1]);
	}
	
	return 0;
}