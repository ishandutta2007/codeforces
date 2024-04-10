#include <bits/stdc++.h>
#define maxn 20086

using namespace std;

int n, q;
int a[maxn];
int lg[maxn], f[maxn][16], g[maxn][16][32], h[32], H[32];
int l, r, x;

inline int get(int l, int r){
	int x = f[l][lg[r - l + 1]], y = f[r - (1 << lg[r - l + 1]) + 1][lg[r - l + 1]];
	return x + a[x] > y + a[y] ? x : y;
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 2;i <= n;i++) lg[i] = lg[i >> 1] + 1;
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), f[i][0] = i;
	for(int j = 1;j <= 15;j++){
		for(int i = 1;i + (1 << j) - 1 <= n;i++){
			int x = f[i][j - 1], y = f[i + (1 << (j - 1))][j - 1]; 
			f[i][j] = x + a[x] > y + a[y] ? x : y;
		}
	}
	for(int i = 1;i <= n;i++) for(int j = 0;j <= 30;j++) g[i][0][j] = min(n, i + a[i] + j);
	for(int j = 1;j <= 15;j++){
		for(int i = 1;i <= n;i++){
			for(int k = 0;k <= 30;k++){
				g[i][j][k] = i;
				for(int l = 0;l <= k;l++){
					g[i][j][k] = max(g[i][j][k], g[get(i, g[i][j - 1][l])][j - 1][k - l]);
				}
			}
		}
	}
	while(q--){
		scanf("%d%d%d", &l, &r, &x);
		if(l == r){
			puts("0");
			continue;
		}
		if(l + a[l] + x >= r){
			puts("1");
			continue;
		}
		for(int i = 0;i <= x;i++) h[i] = l + a[l] + i;
		int ans = 2;
		for(int i = 15;~i;i--){
			for(int j = 0;j <= x;j++) H[j] = l;
			bool tag = false;
			for(int j = 0;j <= x && !tag;j++){
				for(int k = 0;k <= j && !tag;k++){
					H[j] = max(H[j], g[get(l, h[k])][i][j - k]);
					if(H[j] >= r) tag = true;
				}
			}
			if(tag) continue;
			ans += 1 << i;
			for(int j = 0;j <= x;j++) h[j] = H[j];
		}
		printf("%d\n", ans);
	}
}