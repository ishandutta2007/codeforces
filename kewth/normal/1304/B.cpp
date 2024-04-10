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

const int maxn = 105;
char s[maxn][maxn], t[maxn][maxn];
bool pal[maxn];
bool vis[maxn];
int ansl[maxn], ansr[maxn], ap;

bool check(char *a, char *b, int n) {
	for(int i = 1; i <= n; i ++)
		if(a[i] != b[i])
			return 0;
	return 1;
}

int main() {
	int n = read, m = read;
	for(int i = 1; i <= n; i ++) {
		scanf("%s", s[i] + 1);
		for(int j = 1; j <= m; j ++)
			t[i][m - j + 1] = s[i][j];
		pal[i] = check(s[i], t[i], m);
	}

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j < i; j ++)
			if(!vis[j] and check(s[i], t[j], m)) {
				vis[i] = vis[j] = 1;
				++ ap;
				ansl[ap] = i;
				ansr[ap] = j;
				break;
			}
	}

	int cen = 0;
	for(int i = 1; i <= n; i ++)
		if(!vis[i] and check(s[i], t[i], m)) {
			cen = i;
			break;
		}

	printf("%d\n", (ap + bool(cen) + ap) * m);
	for(int i = 1; i <= ap; i ++)
		printf("%s", s[ansl[i]] + 1);
	printf("%s", s[cen] + 1);
	for(int i = ap; i; i --)
		printf("%s", s[ansr[i]] + 1);
	puts("");
}