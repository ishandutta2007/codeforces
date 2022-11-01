#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, q;
int x, y;
int f[maxn];
int p[maxn], cnt;
int pos[maxn];
int g[maxn][25];

int main(){
	for(int i = 2;i < maxn;i++){
		if(!f[i]) p[++cnt] = i, f[i] = i;
		for(int j = 1;j <= cnt && p[j] * i < maxn;j++){
			f[p[j] * i] = p[j];
			if(i % p[j] == 0) break;
		}
	}
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n;i++) {
		scanf("%d", &x);
		g[i][0] = g[i - 1][0];
		int last = 0;
		while(x ^ 1){
			if(f[x] ^ last){
				g[i][0] = max(g[i][0], pos[f[x]]);
				pos[f[x]] = i;
				last = f[x];
			}
			x /= f[x];
		}
	}	
	for(int i = 1;i <= n;i++) for(int j = 1;j <= 20;j++) g[i][j] = g[g[i][j - 1]][j - 1];
	while(q--){
		scanf("%d%d", &x, &y);
		int ans = 0;
		for(int i = 20;~i;i--) if(g[y][i] >= x) y = g[y][i], ans += 1 << i;
		printf("%d\n", ans + 1);
	}
	 
}