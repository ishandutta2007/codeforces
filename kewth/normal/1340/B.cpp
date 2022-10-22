#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 2020;
bool f[maxn][maxn];
int g[maxn][10];
char s[maxn][10];
char t[10][10] = {
	"1110111",
	"0010010",
	"1011101",
	"1011011",
	"0111010",
	"1101011",
	"1101111",
	"1010010",
	"1111111",
	"1111011",
};

int main () {
	int n = read, m = read;
	for (int i = 1; i <= n; i ++)
		scanf("%s", s[i]);

	for (int i = 1; i <= n; i ++)
		for (int x = 0; x < 10; x ++)
			for (int k = 0; k < 7; k ++) {
				if (s[i][k] == '1' and t[x][k] == '0') {
					g[i][x] = 1000000000;
					break;
				}
				if (s[i][k] == '0' and t[x][k] == '1')
					++ g[i][x];
			}

/* 	for (int i = 1; i <= n; i ++) { */
/* 		for (int x = 0; x < 10; x ++) */
/* 			debug(" %d", g[i][x]); */
/* 		debug("\n"); */
/* 	} */

	f[n + 1][0] = 1;
	for (int i = n; i; i --) {
		for (int x = 0; x < 10; x ++)
			for (int j = g[i][x]; j <= m; j ++)
				f[i][j] |= f[i + 1][j - g[i][x]];
	}

	if (!f[1][m]) return puts("-1"), 0;
	for (int i = 1, j = m; i <= n; i ++)
		for (int x = 9; x >= 0; x --)
			if (g[i][x] <= j and f[i + 1][j - g[i][x]]) {
				printf("%d", x);
				j -= g[i][x];
				break;
			}
	puts("");
}