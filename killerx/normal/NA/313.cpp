#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int n, K;
		scanf("%d %d", &n, &K);
		static int pr[1 << 16];
		rep(i, n / 2) pr[i] = n - 1 - i, pr[n - 1 - i] = i;
		if (K < n - 1) {
			pr[K] = n - 1, pr[n - 1] = K;
			pr[0] = n - 1 - K, pr[n - 1 - K] = 0;
		} else if (3 < n - 2) {
			pr[0] = n - 4, pr[n - 4] = 0;
			pr[3] = 1, pr[1] = 3;
			pr[n - 2] = n - 1, pr[n - 1] = n - 2;
		} else { puts("-1"); continue; }
		static bool vis[1 << 16];
		rep(i, n) vis[i] = 0;
		rep(i, n) if (!vis[i]) {
			vis[i] = vis[pr[i]] = 1;
			printf("%d %d\n", i, pr[i]);
		}
	}
	return 0;
}