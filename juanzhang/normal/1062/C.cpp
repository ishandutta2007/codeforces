#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, p = 1e9 + 7;
int n, m, sum[maxn];

inline int qp(int a, int k) {
	int res = 1;
	for (; k; k >>= 1, a = 1ll * a * a % p) {
		if (k & 1) res = 1ll * res * a % p;
	}
	return res;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%1d", sum + i), sum[i] += sum[i - 1];
	}
	int l, r;
	while (m--) {
		scanf("%d %d", &l, &r);
		int len = r - l + 1, s1 = sum[r] - sum[l - 1], s0 = len - s1;
		int ans1 = (qp(2, s1) + p - 1) % p, ans0 = (1ll * (qp(2, s0) - 1) * (qp(2, s1) - 1) % p + p) % p;
		printf("%d\n", (ans1 + ans0) % p);
	}
	return 0;
}