#include <bits/stdc++.h>
using namespace std;

const int maxn = 1024, all = 1023;
int cost[200010];
int n, m, cnt[maxn], sum[maxn], cst[maxn], pos[maxn];

inline int getbit() {
	int k, x, res = 0;
	scanf("%d", &k);
	while (k--) {
		scanf("%d", &x), res |= 1 << (x - 1);
	}
	return res;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		cnt[getbit()]++;
	}
	memset(cst, 0x3f, sizeof cst);
	for (int i = 1, c; i <= m; i++) {
		scanf("%d", cost + i);
		int bit = getbit();
		if (cst[bit] > cost[i]) {
			cst[bit] = cost[i], pos[bit] = i;
		}
	}
	for (int S = 1; S <= all; S++) {
		for (int sub = S; sub; sub = S & (sub - 1)) {
			sum[S] += cnt[sub];
		}
	}
	int p = 1, q = 1;
	int ans1 = 0, ans2 = 1 << 30;
	for (int i = 1; i <= all; i++) {
		for (int j = 1; j <= all; j++) {
			int S = i | j;
			if (cst[i] > 1e9 || cst[j] > 1e9) continue;
			if (sum[S] > ans1 || (sum[S] == ans1 && cst[i] + cst[j] < ans2)) {
				ans1 = sum[S], ans2 = cst[i] + cst[j], p = pos[i], q = pos[j];
			}
		}
	}
	if (p == q) {
		printf("%d ", p), q = 0;
		for (int i = 1; i <= m; i++) {
			if (p != i && (cost[i] < cost[q] || !q)) {
				q = i;
			}
		}
		printf("%d", q);
	} else {
		printf("%d %d", p, q);
	}
  return 0;
}