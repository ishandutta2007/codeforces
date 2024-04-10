#include <bits/stdc++.h>
#define maxn 10086

using namespace std;


int n, m;
char s[maxn], t[maxn];
int f[maxn][maxn];
int g[maxn];

int main(){
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1), m = strlen(t + 1);
	for(int i = 1;i <= n;i++){
		if(s[i] == '.') continue;
		int x = 0;
		for(int j = i;j <= n;j++){
			if(s[j] == '.') x++;
			else x--;
			if(x == 0){
				g[i] = j;
				break;
			}
		}
	}
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for(int i = 0;i < n;i++){ 
		for(int j = 0;j <= m;j++){
			f[i + 1][j] = min(f[i + 1][j], f[i][j] + 1);
			if(j < m && s[i + 1] == t[j + 1]) f[i + 1][j + 1] = min(f[i + 1][j + 1], f[i][j]);
			if(j && s[i + 1] == '.') f[i + 1][j - 1] = min(f[i + 1][j - 1], f[i][j] + 1);
			if(g[i + 1]) f[g[i + 1]][j] = min(f[g[i + 1]][j], f[i][j]);
			//printf("%d %d %d--\n", i, j, f[i][j]);
		}
	}
	printf("%d", f[n][m]);
}