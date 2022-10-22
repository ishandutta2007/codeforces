#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long lolong;

inline int input() { int x; scanf("%d", &x); return x; }
inline lolong linput() { lolong x; scanf("%lld", &x); return x; }

const int maxn = 1005;
char s[maxn];
int f[maxn], g[maxn], h[maxn];

inline bool chkmax(int &x, int y) {
	if(y > x) return x = y, 1;
	return 0;
}

int main() {
	int T = input();
	while(T --) {
		int n = input();
		scanf("%s", s + 1);
		int ans = 0;
		g[0] = - 1000000000;
		for(int i = 1; i <= n; i ++) {
			f[i] = std::max(f[i - 1], g[i - 1]) + (s[i] == '1' ? 2 : 1);
			g[i] = g[i - 1] + 2;
			h[i] = h[i - 1] + 2;
			if(s[i] == '1') {
				chkmax(g[i], 2);
				chkmax(ans, h[i]);
			}
			chkmax(ans, f[i]);
			chkmax(ans, g[i]);
			/* debug("%d %d %d\n", f[i], g[i], h[i]); */
		}
		printf("%d\n", ans);
	}
}