#include <bits/stdc++.h>
#define maxn 205

using namespace std;

int n, k;
char s[maxn], t[maxn];
int ans;
int f[maxn][maxn][maxn];

int main(){
	scanf("%d%d%s%s", &n, &k, s + 1, t + 1);
	if(t[1] == t[2]){
		for(int i = 1;i <= n;i++) ans += s[i] == t[1];
		ans = min(n, ans + k);
		printf("%d", ans * (ans - 1) / 2);
		return 0;
	}
	memset(f, -0x3f, sizeof(f));
	f[0][0][0] = 0; 
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= k;j++){
			for(int l = 0;l <= i;l++){
				f[i][j][l] = f[i - 1][j][l];
				if(s[i] == t[1]){
				 	if(l) f[i][j][l] = max(f[i][j][l], f[i - 1][j][l - 1]);
				}else if(s[i] == t[2]){
				 	f[i][j][l] = max(f[i][j][l], f[i - 1][j][l] + l);
				}
			 	if(j && l) f[i][j][l] = max(f[i][j][l], f[i - 1][j - 1][l - 1]);
			 	if(j) f[i][j][l] = max(f[i][j][l], f[i - 1][j - 1][l] + l);
			 	//printf("%d %d %d %d--\n", i, j, l, f[i][j][l]);
			 	if(i == n) ans = max(ans, f[i][j][l]);
			}
			
		}
	}
	printf("%d", ans);
}