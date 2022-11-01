#include <bits/stdc++.h>

using namespace std;

int n;
char s[55];
int f[255][255][65], g[255][255][65];

int main(){
	scanf("%s", s + 1);
	n = strlen(s + 1);
	reverse(s + 1, s + 1 + n), s[++n] = '0';
	memset(f, 0x3f, sizeof(f));
	for(int i = 0;i <= 250;i++) for(int j = 0;j <= 250;j++) f[i][j][30] = 0;
	for(int i = 1;i <= n;i++){
		memset(g, 0x3f, sizeof(g));
		for(int j = 0;j <= 250;j++){
			for(int k = 0;k <= 250;k++){
				for(int l = 0;l <= 60;l++){
					if((l - 30 + j - k + 300) % 10 == s[i] - '0'){
						g[j][k][(l - 30 + j - k - (s[i] - '0')) / 10 + 30] = min(g[j][k][(l - 30 + j - k - (s[i] - '0')) / 10 + 30], f[j][k][l] + j + k);
					}
				}
			}
		}
		for(int j = 250;~j;j--){
			for(int k = 250;~k;k--){
				for(int l = 0;l <= 60;l++){
					if(j) g[j - 1][k][l] = min(g[j - 1][k][l], g[j][k][l]);
					if(k) g[j][k - 1][l] = min(g[j][k - 1][l], g[j][k][l]);
					f[j][k][l] = g[j][k][l];
				}
			}
		}
	}
	printf("%d", f[0][0][30]);
}