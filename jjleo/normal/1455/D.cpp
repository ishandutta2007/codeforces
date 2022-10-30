#include <bits/stdc++.h>
#define maxn 505

using namespace std;

int t, n, x;
int f[maxn][maxn], g[maxn][maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &x);
		memset(f, 0x3f, sizeof(f));
		f[0][x] = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d", &x);
			memset(g, 0x3f, sizeof(g));
			for(int j = 0;j < maxn;j++){
				for(int k = 0;k < maxn;k++){
					if(x >= j) g[x][k] = min(g[x][k], f[j][k]); 
					if(x > k && k >= j){
						g[k][x] = min(g[k][x], f[j][k] + 1);
					}
				}
			}
			memcpy(f, g, sizeof(g));
		}
		int ans = 1e9;
		for(int j = 0;j < maxn;j++) for(int k = 0;k < maxn;k++) ans = min(ans, f[j][k]);
		printf("%d\n", ans == 1e9 ? -1 : ans);
			
	}
}