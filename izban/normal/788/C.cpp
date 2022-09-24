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

const int INF = (int)1e9;
const int T = 1005;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, k;
	while (scanf("%d%d", &n, &k) == 2) {
		vector<int> a(k);
		vector<int> b(T);
		for (int i = 0; i < k; i++) {
			scanf("%d", &a[i]);
			b[a[i]] = 1;
		}
		vector<int> vct;
		for (int i = 0; i < T; i++) if (b[i]) vct.push_back(n - i);

		vector<int> d(2 * T + 1, INF);
		queue<int> q;
		q.push(T);
		while (!q.empty()) {
			int v = q.front();
			int cd = v == T ? 0 : d[v];
			q.pop();
			for (int delta : vct) {
				int to = v + delta;
				if (to >= 0 && to <= 2 * T && d[to] > cd + 1) {
					d[to] = cd + 1;
					q.push(to);
				}
			}
		}
		int ans = d[T];
		if (ans == INF) ans = -1;
		printf("%d\n", ans);
	}

	return 0;
}