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

const double eps = 1e-9;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, m;
	while (scanf("%d%d", &n, &m) == 2) {
		vector<int> x(n);
		for (int i = 0; i < n; i++) scanf("%d", &x[i]);

		vector<pair<int, int> > a;
		for (int i = 0; i < n; i++) a.push_back(make_pair(x[i], i));
		sort(a.begin(), a.end());
		vector<int> o(n);
		for (int i = 0; i < n; i++) o[a[i].second] = i;

		for (int it = 0; it < m; it++) {
			int id, len;
			scanf("%d%d", &id, &len);
			id = o[--id];

			int last = -1;
			while (1) {
				int ii = lower_bound(a.begin(), a.end(), make_pair(a[id].first + len + 1, -1)) - a.begin() - 1;

				int nxt = -1;
				if (ii > id) {
					nxt = ii;
				} else {
					ii = lower_bound(a.begin(), a.end(), make_pair(a[id].first - len, -1)) - a.begin();
					if (ii < id) {
						nxt = ii;
					} else {
						break;
					}
				}
				if (nxt == last) {
					len %= 2 * abs(a[id].first - a[nxt].first);
					last = -1;
					continue;
				}
				len -= abs(a[id].first - a[nxt].first);
				last = id;
				id = nxt;
			}
			printf("%d\n", a[id].second + 1);
		}
	}

	return 0;
}