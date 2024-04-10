#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
	int T;
	scanf("%d", &T);
	while (T --) {
		int n, z;
		scanf("%d %d", &n, &z);
		int ans = 0;
		rep(i, n) {
			int x;
			scanf("%d", &x);
			ans = std::max(ans, x);
			ans = std::max(ans, x | z);
		}
		printf("%d\n", ans);
	}
	return 0;
}