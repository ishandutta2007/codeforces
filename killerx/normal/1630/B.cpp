#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;
int n, K, a[mxn], b[mxn];

void Main() {
	scanf("%d %d", &n, &K);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) b[i] = a[i];
	std::sort(b, b + n);
	int ansx = 1, ansy = n;
	for (int x = 1; x <= n; ++ x) {
		int lb = x, rb = n + 1;
		while (lb < rb) {
			int md = (lb + rb) >> 1;
			if ((std::lower_bound(b, b + n, md + 1) - std::lower_bound(b, b + n, x)) * 2 >= n + K) {
				rb = md;
			} else {
				lb = md + 1;
			}
		}
		if (lb <= n) {
			if (lb - x + 1 < ansy - ansx + 1) {
				ansx = x, ansy = lb;
			}
		}
	}
	printf("%d %d\n", ansx, ansy);
	int last = 0, cur = 0, cnt = 0;
	rep(i, n) {
		cur += ansx <= a[i] && a[i] <= ansy ? +1 : -1;
		if (cur == cnt + 1 && cnt != K - 1) {
			printf("%d %d\n", last + 1, i + 1);
			last = i + 1;
			++ cnt;
		}
	}
	printf("%d %d\n", last + 1, n);
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}