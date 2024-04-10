#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
	int T;
	scanf("%d", &T);
	while (T --) {
		int n;
		scanf("%d", &n);
		std::vector <int> a(n);
		int cnt = 0;
		rep(i, n) {
			scanf("%d", &a[i]);
			cnt += a[i] == 0;
		}
		int pre = 0;
		while (pre < n && a[pre] == 0) ++ pre;
		int suf = 0;
		while (suf < n && a[n - 1 - suf] == 0) ++ suf;
		if (cnt == n) puts("0");
		else if (cnt > pre + suf) puts("2");
		else puts("1");
	}
	return 0;
}