#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 55, maxm = 20005;
int a[maxn][maxm];
int s[maxn][maxm];
int f[maxn][maxm];
int pre[maxm], suf[maxm];
 
int main() {
	int n = read, m = read, k = read;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++) {
			a[i][j] = read;
			s[i][j] = s[i][j - 1] + a[i][j];
		}

	for(int l = 1; l + k - 1 <= m; l ++) {
		int r = l + k - 1;
		f[1][l] = s[1][r] - s[1][l - 1];
	}

	for(int i = 2; i <= n; i ++) {
		for(int l = 1; l + k - 1 <= m; l ++) {
			int r = l + k - 1;
			pre[l] = std::max(pre[l - 1], f[i - 1][l] +
					s[i][r] - s[i][l - 1]);
		}
		for(int l = m - k + 1; l; l --) {
			int r = l + k - 1;
			suf[l] = std::max(suf[l + 1], f[i - 1][l] +
					s[i][r] - s[i][l - 1]);
		}

		for(int l = 1; l + k - 1 <= m; l ++) {
			int r = l + k - 1;
			f[i][l] = 0;
			for(int L = std::max(l - k + 1, 1);
					L <= r and L + k - 1 <= m; L ++) {
				int R = L + k - 1;
				f[i][l] = std::max(f[i][l], f[i - 1][L] +
						s[i][std::max(R, r)] - s[i][std::min(L, l) - 1]);
			}
			if(l - k >= 1)
				f[i][l] = std::max(f[i][l], pre[l - k] +
						s[i][r] - s[i][l - 1]);
			if(r + 1 <= m)
				f[i][l] = std::max(f[i][l], suf[r + 1] +
						s[i][r] - s[i][l - 1]);
			// debug("%d, %d-%d -> %d\n", i, l, r, f[i][l]);
		}
	}

	int ans = 0;
	for(int l = 1; l + k - 1 <= m; l ++)
		ans = std::max(ans, f[n][l]);
	printf("%d\n", ans);
}