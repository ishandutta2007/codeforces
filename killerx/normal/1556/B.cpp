#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

void Main() {
	int n;
	scanf("%d", &n);
	std::vector <int> a(n);
	rep(i, n) scanf("%d", &a[i]), a[i] %= 2;
	int cnt[2] = {0, 0};
	rep(i, n) cnt[a[i]] ++;
	if (std::abs(cnt[0] - cnt[1]) > 1) printf("-1\n");
	else {
		long long ans = 1LL << 60;
		rep(c, 2) {
			int pos[2];
			pos[c] = 0;
			pos[c ^ 1] = 1;
			long long cur = 0;
			rep(i, n) {
				if (pos[a[i]] >= n) cur = 1LL << 60;
				cur += std::abs(i - pos[a[i]]);
				pos[a[i]] += 2;
			}
			ans = std::min(ans, cur);
		}
		printf("%lld\n", ans / 2);
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}