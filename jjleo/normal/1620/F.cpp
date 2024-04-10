#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int t, n;
int a[maxn];
int f[maxn][2][2];
pair<int, int> g[maxn][2][2];

inline void update(int i, int j, int k, int x, int jj, int kk){
	if(f[i][j][k] > x){
		f[i][j][k] = x;
		g[i][j][k] = {jj, kk};
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 1;i <= n;i++) memset(f[i], 0x3f, sizeof(f[i]));
		f[1][0][0] = f[1][0][1] = -maxn;
		for(int i = 2;i <= n;i++){
			for(int j = 0;j <= 1;j++){
				for(int k = 0;k <= 1;k++){
					int x = a[i] * (k ? -1 : 1), y = a[i - 1] * (j ? -1 : 1);
					if(x > f[i - 1][0][j]){
						if(x < y) update(i, 1, k, y, 0, j);
						else update(i, 0, k, f[i - 1][0][j], 0, j);
					}
					if(x > y){
						if(x < f[i - 1][1][j]) update(i, 1, k, f[i - 1][1][j], 1, j);
						else update(i, 0, k, y, 1, j);
					}
				}
			}
		}
		int j = -1, k = -1;
		for(int jj = 0;jj <= 1;jj++) for(int kk = 0;kk <= 1;kk++) if(f[n][jj][kk] <= n) j = jj, k = kk;
		if(j == -1 && k == -1){
			puts("NO");
			continue;
		}
		for(int i = n;i;i--){
			if(k) a[i] *= -1;
			pair<int, int> p = g[i][j][k];
			j = p.first, k = p.second;
		}
		puts("YES");
		for(int i = 1;i <= n;i++) printf("%d ", a[i]);
		puts("");
	}
}