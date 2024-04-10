#include <bits/stdc++.h>
#define maxn 2086

using namespace std;

int T;
int n;
char s[maxn], t[maxn];
int sum[2][maxn][26];
int f[maxn][maxn];

int main(){
	scanf("%d", &T);
	for(int i = 1;i < maxn;i++) f[0][i] = 1e9;
	while(T--){
		scanf("%d%s%s", &n, s + 1, t + 1);
		reverse(s + 1, s + 1 + n), reverse(t + 1, t + 1 + n);
		for(int i = 1;i <= n;i++){
			for(int j = 0;j < 26;j++){
				sum[0][i][j] = sum[0][i - 1][j];
				sum[1][i][j] = sum[1][i - 1][j];
			}
			sum[0][i][s[i] - 'a']++, sum[1][i][t[i] - 'a']++;
			f[i][0] = 0;
			for(int j = 1;j <= n;j++) f[i][j] = 1e9;
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= i;j++){
				if(s[i] == t[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
				if(sum[0][i][t[j] - 'a'] >= sum[1][j][t[j] - 'a']) f[i][j] = min(f[i][j], f[i][j - 1] + 1);
				f[i][j] = min(f[i][j], f[i - 1][j]);
				//printf("%d %d %d--\n", i, j, f[i][j]);
			}
		}
		if(f[n][n] == 1e9) puts("-1");
		else printf("%d\n", f[n][n]);
	}
	
}