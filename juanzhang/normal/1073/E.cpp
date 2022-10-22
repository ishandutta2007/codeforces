#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int p = 998244353;
int k, a[20], pw[20];
struct pr {
	int tot, sum;
	pr() {}
	pr(int a, int b) : tot(a), sum(b) {}
	void clr() { tot = sum = 0; }
	bool chk() { return ~tot && ~sum; }
} dp[2][2][20][1 << 10];

void add(pr& a, pr b, int num, int pos) {
	a.tot = (a.tot + b.tot) % p;
	a.sum = (a.sum + 1ll * num * pw[pos] % p * b.tot % p + b.sum) % p;
}

pr dfs(bool lim, bool zero, int pos, int mark) {
	if (!pos) return pr(1, 0);
	pr& res = dp[lim][zero][pos][mark];
	if (res.chk()) return res;
	res.clr();
	for (int i = 0; i <= (lim ? a[pos] : 9); i++) {
		if (__builtin_popcount(zero && !i ? 0 : mark | 1 << i) <= k) {
			add(res, dfs(lim && i == a[pos], zero && !i, pos - 1, zero && !i ? 0 : mark | 1 << i), i, pos - 1);
		}
	}
	return res;
}

int calc(ll x) {
	int len = 0;
	memset(dp, -1, sizeof dp);
	while (x) a[++len] = x % 10, x /= 10;
	return dfs(1, 1, len, 0).sum;
}

int main() {
	pw[0] = 1;
	for (int i = 1; i < 19; i++) {
		pw[i] = 10ll * pw[i - 1] % p;
	}
	ll l, r;
	scanf("%lld %lld %d", &l, &r, &k);
	printf("%d", (calc(r) - calc(l - 1) + p) % p);
	return 0;
}