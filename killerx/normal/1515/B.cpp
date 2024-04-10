#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int n; scanf("%d", &n);
		int c = 0;
		while (n % 2 == 0) n /= 2, ++ c;
		if (c == 0) printf("NO\n");
		else {
			int x = std::sqrt(n) + 0.5;
			if (x * x == n) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}