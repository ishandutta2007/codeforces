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

int n, q;

void add(int &a, int b) {
	a += b;
	if (a >= n) a -= n;
	if (a < 0) a += n;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d%d", &n, &q) == 2) {
		int pos0 = 0;
		int pos1 = 1;
		for (int i = 0; i < q; i++) {
			int t;
			scanf("%d", &t);
			if (t == 1) {
				int x;
				scanf("%d", &x);
				add(pos0, x);
				add(pos1, x);
			}
			if (t == 2) {
				pos0 ^= 1;
				pos1 ^= 1;
			}
		}
		vector<int> ans(n);
		ans[pos0] = 0;
		for (int i = 2; 0 + i < n; i += 2) {
			ans[(pos0 + i) % n] = i;
		}
		ans[pos1] = 1;
		for (int i = 2; 1 + i < n; i += 2) {
			ans[(pos1 + i) % n] = 1 + i;
		}

		for (int i = 0; i < n; i++) printf("%d%c", ans[i] + 1, " \n"[i + 1 == n]);
	}

	return 0;
}