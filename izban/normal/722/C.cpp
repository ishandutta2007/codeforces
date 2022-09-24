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

const int MAXK = 17;
const int MAXN = 1 << MAXK;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

int n;
int a[MAXN];
int p[MAXN];
int perm[MAXN];
ll sum[MAXN];

int get(int x) {
	if (x == p[x]) return x;
	return p[x] = get(p[x]);
}

void uni(int u, int v) {
	u = get(u);
	v = get(v);
	p[v] = u;
	sum[u] += sum[v];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	bool first = 1;
	while (scanf("%d", &n) == 1) {
		if (first) first = 0;
		else printf("\n");

		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		for (int i = 0; i < n; i++) scanf("%d", &perm[i]);

		for (int i = 0; i < n; i++) {
			p[i] = -1;
			sum[i] = 0;
		}

		ll cur = 0;
		vector<ll> ans(n + 1);
		for (int i = n - 1; i >= 0; i--) {
			int id = perm[i] - 1;

			p[id] = id;
			sum[id] = a[id];
			if (id > 0 && p[id - 1] != -1) uni(id, id - 1);
			if (id + 1 < n && p[id + 1] != -1) uni(id, id + 1);
			
			cur = max(cur, sum[get(id)]);
			ans[i] = cur;
		}

		for (int i = 1; i <= n; i++) {
			printf("%I64d\n", ans[i]);
		}
	}

	return 0;
}