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

const int maxn = 1010;
char map[maxn][maxn];
int s[maxn][maxn];
int A[maxn], B[maxn];
bool vis[maxn][maxn];

void dfs (int x, int y) {
	if (map[x][y] != '#' or vis[x][y]) return;
	vis[x][y] = 1;
	dfs(x - 1, y);
	dfs(x + 1, y);
	dfs(x, y - 1);
	dfs(x, y + 1);
}

int main () {
	int n = read, m = read;
	for (int i = 1; i <= n; i ++)
		scanf("%s", map[i] + 1);

	/* for (int i = 1; i <= n; i ++) */
	/* 	for (int j = 1; j <= m; j ++) */
	/* 		a[i][j] = (map[i][j] == '#') - S(1, 1, i, j); */

	for (int i = 1; i <= n; i ++) {
		int l = 0, r = -1, tot = 0;
		for (int j = 1; j <= m; j ++)
			if (map[i][j] == '#') {
				if (!l) l = j;
				r = j;
				++ tot;
			}
		if (tot != r - l + 1)
			return puts("-1"), 0;
		if (!tot)
			l = 1, r = m;
		for (int j = l; j <= r; j ++)
			++ s[i][j];
	}

	for (int j = 1; j <= m; j ++) {
		int l = 0, r = -1, tot = 0;
		for (int i = 1; i <= n; i ++)
			if (map[i][j] == '#') {
				if (!l) l = i;
				r = i;
				++ tot;
			}
		if (tot != r - l + 1)
			return puts("-1"), 0;
		if (!tot)
			l = 1, r = n;
		for (int i = l; i <= r; i ++)
			++ s[i][j];
	}

	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			if (s[i][j] == 2)
				++ A[i], ++ B[j];

	for (int i = 1; i <= n; i ++)
		if (!A[i])
			return puts("-1"), 0;
	for (int j = 1; j <= m; j ++)
		if (!B[j])
			return puts("-1"), 0;

	int ans = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			if (map[i][j] == '#' and !vis[i][j]) {
				++ ans;
				dfs(i, j);
			}

	printf("%d\n", ans);
}