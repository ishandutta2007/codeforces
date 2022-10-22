#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#include <cstring>
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
int seg[maxm << 2], tag[maxm << 2];

void modi(int now, int x) {
	seg[now] += x;
	tag[now] += x;
}

void push_down(int now) {
	if(tag[now]) {
		modi(now << 1, tag[now]);
		modi(now << 1 | 1, tag[now]);
		tag[now] = 0;
	}
}

void modify(int now, int L, int R, int l, int r, int x) {
	if(l > R or r < L) return;
	if(l <= L and R <= r) return modi(now, x);
	push_down(now);
	int M = (L + R) >> 1;
	modify(now << 1, L, M, l, r, x);
	modify(now << 1 | 1, M + 1, R, l, r, x);
	seg[now] = std::max(seg[now << 1], seg[now << 1 | 1]);
}

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
		memset(seg, 0, sizeof seg);
		memset(tag, 0, sizeof tag);

		for(int l = 1; l + k - 1 <= m; l ++) {
			int r = l + k - 1;
			modify(1, 1, m - k + 1, l, l, f[i - 1][l] +
					s[i][r] - s[i][std::max(l - 1, k)]);
		}

		for(int l = 1; l + k - 1 <= m; l ++) {
			int r = l + k - 1;
			f[i][l] = seg[1] + s[i][r] - s[i][l - 1];
			modify(1, 1, m - k + 1, l - k + 1, l, a[i][l]);
			modify(1, 1, m - k + 1, l + 1, r + 1, - a[i][r + 1]);
			// debug("%d, %d-%d -> %d\n", i, l, r, f[i][l]);
		}
	}

	int ans = 0;
	for(int l = 1; l + k - 1 <= m; l ++)
		ans = std::max(ans, f[n][l]);
	printf("%d\n", ans);
}