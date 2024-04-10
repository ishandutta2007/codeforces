#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5, mod = 1e9 + 7;

int n, a[mxn];
int cnt[30];
int pw[mxn];

int main() {
	rep(i, mxn) pw[i] = i ? 2LL * pw[i - 1] % mod : 1;
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) {
		int x = a[i];
		int c = 0;
		while (x % 2 == 0) x /= 2, ++ c;
		cnt[c] += 1;
	}
	int ans = 0;
	for (int mink = 0; mink < 30; ++ mink) if (cnt[mink]) {
		int cur = 0;
		if (mink == 0) cur = pw[cnt[mink]];
		else cur = pw[cnt[mink] - 1];
		cur = (cur + mod - 1) % mod;
		for (int i = mink + 1; i < 30; ++ i) {
			cur = 1LL * cur * pw[cnt[i]] % mod;
		}
		ans = (ans + cur) % mod;
	}
	printf("%d\n", ans);
	return 0;
}