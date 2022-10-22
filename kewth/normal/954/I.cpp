#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <cstring>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

const int maxn = 125005, maxk = 6;
char s[maxn], t[maxn];
int fail[maxn];
int ans[maxn];

int bel[maxk];
void force (int x, int lim, int n, int m) {
	if (x == maxk) {
		fail[0] = -1;
		fail[1] = 0;
		for (int i = 1; i < m; i ++) {
			int j = fail[i];
			while (~j and bel[t[j + 1] - 'a'] != bel[t[i + 1] - 'a'])
				j = fail[j];
			fail[i + 1] = j + 1;
		}
		for (int i = 1, j = 0; i <= n; i ++) {
			if (j == m) j = fail[j];
			while (~j and bel[s[i] - 'a'] != bel[t[j + 1] - 'a'])
				j = fail[j];
			++ j;
			if (j == m)
				ans[i] = std::min(ans[i], maxk - lim);
		}
		return;
	}
	for (int i = 0; i <= lim; i ++) {
		bel[x] = i;
		force(x + 1, lim + (i == lim), n, m);
	}
}

int main () {
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	int n = int(strlen(s + 1)), m = int(strlen(t + 1));
	std::fill(ans, ans + n + 1, 1000000000);
	force(0, 0, n, m);
	for (int i = m; i <= n; i ++)
		printf("%d ", ans[i]);
	puts("");
}