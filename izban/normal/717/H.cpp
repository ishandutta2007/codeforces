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


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, m;
	while (scanf("%d%d", &n, &m) == 2) {
		vector<vector<int> > e(n);
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u; --v;
			if (u > v) swap(u, v);
			e[v].push_back(u);
		}
		vector<vector<int> > b(n);
		int T = -1;
		for (int i = 0; i < n; i++) {
			int k;
			scanf("%d", &k);
			b[i].resize(k);
			for (int j = 0; j < k; j++) {
				scanf("%d", &b[i][j]);
				b[i][j]--;
				T = max(T, b[i][j] + 1);
			}
			random_shuffle(b[i].begin(), b[i].end());
		}

		vector<int> tp(n);
		vector<int> team(n, -1);
		for (int i = 0; i < n; i++) tp[i] = -1;
		vector<int> tp2(T, -1);

		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int to : e[i]) sum += tp[to];
			tp[i] = (sum * 2 >= e[i].size()) ^ 1;
			
			bool found = 0;
			for (int j : b[i]) {
				if (tp2[j] == tp[i]) {
					found = 1;
					team[i] = j;
					break;
				}
			}
			if (found) continue;
			for (int j : b[i]) {
				if (tp2[j] == -1) {
					found = 1;
					tp2[j] = tp[i];
					team[i] = j;
					break;
				}
			}
			assert(found);
		}
		for (int i = 0; i < n; i++) printf("%d%c", team[i] + 1, " \n"[i + 1 == n]);
		for (int i = 0; i < T; i++) printf("%d%c", max(0, tp2[i]) + 1, " \n"[i + 1 == T]);
	}

	return 0;
}