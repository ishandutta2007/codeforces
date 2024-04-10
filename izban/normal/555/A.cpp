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

const int MAXN = 1024;
const int MOD = 1000 * 1000 * 1000 + 7;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, k;
	while (scanf("%d%d", &n, &k) == 2) {
		vector<vector<int> > a(k);
		for (int i = 0; i < k; i++) {
			int m;
			scanf("%d", &m);
			a[i].resize(m);
			for (int j = 0; j < m; j++) {
				scanf("%d", &a[i][j]);
			}
		}

		int ans = 0;

		ans += n - 1;
		ans -= k - 1;

		for (int i = 0; i < k; i++) {
			if (a[i][0] != 1) continue;
			for (int j = 1; j < (int)a[i].size(); j++) {
				ans -= 2 * (a[i][j] == j + 1);
			}
		}

		ans += n - 1;

		printf("%d\n", ans);
	}

	return 0;
}