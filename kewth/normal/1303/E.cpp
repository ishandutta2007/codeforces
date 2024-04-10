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

const int maxn = 405;
char s[maxn], t[maxn];
int f[maxn][maxn];
int nxt[maxn][26];

int main() {
	int T = read;
	while(T --) {
		scanf("%s", s + 1);
		scanf("%s", t + 1);
		int n = int(strlen(s + 1));
		int m = int(strlen(t + 1));

		for(int x = 0; x < 26; x ++)
			nxt[n + 1][x] = nxt[n][x] = n + 1;
		for(int i = n; i; i --) {
			for(int x = 0; x < 26; x ++)
				nxt[i - 1][x] = nxt[i][x];
			nxt[i - 1][s[i] - 'a'] = i;
		}

		for(int p = 1; p <= m; p ++) {
			for(int i = 0; i <= p; i ++)
				for(int j = 0; j <= m - p; j ++) {
					if(i or j) f[i][j] = n + 1;
					if(i)
						f[i][j] = std::min(f[i][j],
							nxt[f[i - 1][j]][t[i] - 'a']);
					if(j)
						f[i][j] = std::min(f[i][j],
							nxt[f[i][j - 1]][t[p + j] - 'a']);
				}
			if(f[p][m - p] <= n) {
				puts("YES");
				break;
			}
			if(p == m)
				puts("NO");
		}
	}
}