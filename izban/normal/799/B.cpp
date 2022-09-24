#include <unordered_map>
#include <unordered_set>
#include <functional>
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
const int MAXN = 1 << MAXK;
const int MOD = 0; // 1000 * 1000 * 1000 + 7;
const int INF = 1.01e9;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	
	int n;
	while (scanf("%d", &n) == 1) {
		vector<int> p(n), a(n), b(n);
		for (int i = 0; i < n; i++) scanf("%d", &p[i]);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		for (int i = 0; i < n; i++) scanf("%d", &b[i]);

		vector<set<pair<int, int> > > st(4);
		for (int i = 0; i < n; i++) {
			st[a[i]].insert(make_pair(p[i], i));
			st[b[i]].insert(make_pair(p[i], i));
		}
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			int c;
			scanf("%d", &c);
			if (st[c].empty()) {
				printf("%d", -1);
			}
			else {
				int id = st[c].begin()->second;
				st[a[id]].erase(make_pair(p[id], id));
				st[b[id]].erase(make_pair(p[id], id));
				printf("%d", p[id]);
			}
			if (i + 1 == m) printf("\n");
			else printf(" ");
		}
	}

	return 0;
}