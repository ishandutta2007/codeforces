#include <bits/stdc++.h>
#define maxn 505

using namespace std;

int n, l, m;
int d[maxn], a[maxn];
int f[maxn][maxn], g[maxn][maxn];

int main(){
	scanf("%d%d%d", &n, &l, &m);
	for(int i = 1;i <= n;i++) scanf("%d", &d[i]);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	memset(f, 0x3f, sizeof(f)), memset(g, 0x3f, sizeof(g));
	f[1][0] = 0;
	for(int i = 2;i <= n;i++){
		for(int j = 1;j <= n;j++){
			for(int k = 0;k <= m;k++){
				g[i][k] = min(g[i][k], f[j][k] + (d[i] - d[i - 1]) * a[j]);
				g[j][k + 1] = min(g[j][k + 1], f[j][k] + (d[i] - d[i - 1]) * a[j]);
			}
		}
		memcpy(f, g, sizeof(g)), memset(g, 0x3f, sizeof(g));
	}
	int ans = 1e9;
	for(int i = 1;i <= n;i++) for(int j = 0;j <= m;j++) ans = min(ans, f[i][j] + (l - d[n]) * a[i]);
	printf("%d", ans);
}