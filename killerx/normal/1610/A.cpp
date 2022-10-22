#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int n, m;
		scanf("%d %d", &n, &m);
		if (n == 1 && m == 1) puts("0");
		else if (n == 1 || m == 1) puts("1");
		else puts("2");
	}
	return 0;
}