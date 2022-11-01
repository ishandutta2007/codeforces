#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=(a);i<(b);i++)
#define MOD 1000000007
#define MT make_tuple
#define PB push_back
typedef long long ll;

int Q, R, C, g[660][660], f[660][660], d1, d2;

int main () {
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d %d", &R, &C);
		fo(r, 0, R) fo(c, 0, C) scanf("%d", &g[r][c]);
		fo(r, 0, R) fo(c, 0, C) f[r][c] = g[(r + R/2) % R][c];
		int x = R/2 - 1, y = R/2;
		d1 = 0, d2 = 0;
		fo(c, 0, C) d1 += abs(g[x][c] - g[y][c]), d2 += abs(f[x][c] - f[y][c]);
		if (d1 < d2) puts("NO");
		else puts("YES");
	}
	return 0;
}