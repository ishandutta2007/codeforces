#include <algorithm>
#include <cstring>
using namespace std;

const int N = 5010;

char s[N];
int n, q, f[N][N], g[N][N];
bool pal[N][N];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int l, r;
	for(int i = 1; i <= n; i ++) {
		l = r = i;
		for(; l >= 1 && r <= n && s[l] == s[r]; l --, r ++) pal[l][r] = 1;
		l = i; r = i + 1;
		for(; l >= 1 && r <= n && s[l] == s[r]; l --, r ++) pal[l][r] = 1;
	}
	for(int i = 1; i <= n; i ++) {
		f[i][i] = 1;
		for(int j = i + 1; j <= n; j ++)
			f[i][j] = f[i][j - 1] + pal[i][j];
	}
	for(int j = n; j >= 1; j --) {
		g[j][j] = 1;
		for(int i = j + 1; i >= 1; i --)
			g[i][j] = g[i + 1][j] + f[i][j];
	}
	for(scanf("%d", &q); q --; ) {
		scanf("%d%d", &l, &r);
		printf("%d\n", g[l][r]);
	}
	return 0;
}