#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e5 + 5, mxm = 333;

int n, m;
std::vector <int> a[mxn];

std::unordered_map <int, int> cnt[mxm];
std::unordered_map <int, long long> sum[mxm];

int main() {
	scanf("%d %d", &n, &m);
	rep(i, n) {
		a[i].resize(m);
		rep(j, m) scanf("%d", &a[i][j]);
	}
	if (n < m) {
		std::swap(n, m);
		static std::vector <int> b[mxn];
		rep(i, n) {
			b[i].resize(m);
			rep(j, m) b[i][j] = a[j][i];
		}
		rep(i, m) a[i].clear();
		rep(i, n) a[i] = b[i];
	}
	long long ans = 0;
	rep(i, n) rep(j, m) {
		rep(nj, m) if (cnt[nj].find(a[i][j]) != cnt[nj].end())
			ans += 1LL * (std::abs(j - nj) + i) * cnt[nj][a[i][j]] - sum[nj][a[i][j]];
		cnt[j][a[i][j]] += 1;
		sum[j][a[i][j]] += i;
	}
	printf("%lld\n", ans);
	return 0;
}