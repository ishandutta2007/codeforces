#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <cstring>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

const int maxn = 3030, mod = 998244353;
char s[maxn], t[maxn];
ll f[maxn][maxn];

int main () {
	scanf("%s", s + 1);
	int n = int(strlen(s + 1));
	scanf("%s", t + 1);
	int m = int(strlen(t + 1));

	auto match = [&] (int i, int j) {
		return j > m or s[i] == t[j];
	};

	f[n + 1][n] = 1;
	for (int l = n; l; l --) {
		f[l][l - 1] = 1;
		for (int r = l; r <= n; r ++) {
			int i = r - l + 1;
			if (match(i, l)) f[l][r] += f[l + 1][r];
			if (match(i, r)) f[l][r] += f[l][r - 1];
			f[l][r] %= mod;
		}
	}

	ll ans = 0;
	for (int i = m; i <= n; i ++)
		ans += f[1][i];
	ans %= mod;
	printf("%lld\n", ans);
}