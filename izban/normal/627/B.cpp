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

int n, k, a, b, q;

struct fenwick {
	int n;
	vector<int> f;

	fenwick() {}
	fenwick(int n) {
		this->n = n;
		f.assign(n, 0);
	}

	void add(int x, int y) {
		for (; x < n; x |= (x + 1)) f[x] += y;
	}

	int get(int x) {
		int res = 0;
		for (; x >= 0; x = (x & (x + 1)) - 1) res += f[x];
		return res;
	}

	int get(int l, int r) {
		return get(r) - get(l - 1);
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d%d%d%d%d", &n, &k, &a, &b, &q) == 5) {
		vector<int> cnt(n);
		fenwick f1(n), f2(n);
		for (int i = 0; i < q; i++) {
			int t;
			scanf("%d", &t);
			if (t == 1) {
				int d, na;
				scanf("%d%d", &d, &na);
				--d; 
				f1.add(d, -min(cnt[d], b));
				f2.add(d, -min(cnt[d], a));
				cnt[d] += na;
				f1.add(d, min(cnt[d], b));
				f2.add(d, min(cnt[d], a));
			}
			if (t == 2) {
				int p;
				scanf("%d", &p);
				--p;
				int ans = f1.get(0, p - 1) + f2.get(p + k, n - 1);
				printf("%d\n", ans);
			}
		}
	}

	return 0;
}