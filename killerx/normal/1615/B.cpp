#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;

int sum[mxn][20];

void Main() {
	int l, r;
	scanf("%d %d", &l, &r);
	static int s[20];
	rep(i, 20) s[i] = sum[r][i] - (l ? sum[l - 1][i] : 0);
	int ans = r - l;
	rep(i, 20) ans = std::min(ans, (r - l + 1) - s[i]);
	printf("%d\n", ans);
}

int main() {
	rep(i, mxn) {
		rep(j, 20) sum[i][j] = i ? sum[i - 1][j] : 0;
		rep(j, 20) sum[i][j] += i >> j & 1;
	}
	int T;
	scanf("%d", &T);
	while (T --) Main();
	return 0;
}