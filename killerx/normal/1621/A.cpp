#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

void Main() {
	int n, k;
	scanf("%d %d", &n, &k);
	if (k > (n + 1) / 2) puts("-1");
	else {
		static char ans[55][55];
		rep(i, n) {
			rep(j, n) ans[i][j] = '.';
			ans[i][n] = 0;
		}
		rep(i, k) ans[i * 2][i * 2] = 'R';
		rep(i, n) puts(ans[i]);
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}