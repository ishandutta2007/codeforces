#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#include <cstring>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 150005;
char s[maxn];
int f[maxn][7], g[maxn][7], h[maxn][7];
int ch[7][26];

int main () {
	for(int i = 0; i < 7; i ++) {
		ch[i]['o' - 'a'] = 1;
		ch[i]['t' - 'a'] = 4;
	}
	ch[1]['n' - 'a'] = 2;
	ch[2]['e' - 'a'] = 3;
	ch[4]['w' - 'a'] = 5;
	ch[5]['o' - 'a'] = 6;
	ch[6]['n' - 'a'] = 2;

	for(int j = 1; j < 7; j ++)
		f[0][j] = 1000000000;

	int T = read;
	while(T --) {
		scanf("%s", s + 1);
		int n = int(strlen(s + 1));
		for(int i = 1; i <= n; i ++) {
			for(int j = 0; j < 7; j ++)
				f[i][j] = 1000000000;
			for(int j = 0; j < 7; j ++) {
				int k = ch[j][s[i] - 'a'];
				if(f[i - 1][j] + 1 < f[i][j]) {
					f[i][j] = f[i - 1][j] + 1;
					g[i][j] = j;
					h[i][j] = 1;
				}
				if(f[i - 1][j] < f[i][k]) {
					f[i][k] = f[i - 1][j];
					g[i][k] = j;
					h[i][k] = 0;
				}
			}
			f[i][3] = f[i][6] = 1000000000;
		}
		int ans = 1000000000, x = 0;
		for(int i = 0; i < 7; i ++)
			if(f[n][i] < ans) {
				ans = f[n][i];
				x = i;
			}
		printf("%d\n", ans);
		for(int i = n; i; i --) {
			if(h[i][x]) printf("%d ", i);
			x = g[i][x];
		}
		puts("");
	}
}