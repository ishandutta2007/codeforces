#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;
int n, a[mxn];

void Main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	int ans = 0;
	rep(x, n) {
		int i = std::upper_bound(a, a + n, a[x]) - a;
		int cur = i - x;
		while (i < n) {
			cur += 1;
			i = std::lower_bound(a + i + 1, a + n, a[i] + (a[i] - a[x])) - a;
		}
		ans = std::max(ans, cur);
	}
	printf("%d\n", n - ans);
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}