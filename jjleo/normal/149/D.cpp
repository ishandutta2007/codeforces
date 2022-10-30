#include <bits/stdc++.h>
#define maxn 705
using namespace std;

const int p = 1e9 + 7;

int n;
char s[maxn];
int R[maxn];
int sk[maxn], top;
int f[maxn][maxn][3][3];

int dfs(int l, int r, int x, int y){
	//printf("%d %d %d %d--\n", l, r, x, y);
	if(f[l][r][x][y] != -1) return f[l][r][x][y];
	if(l + 1 == r) return f[l][r][x][y] = (x | y) && (!x || !y);
	f[l][r][x][y] = 0;
	if(R[l] == r){
		if(!((x | y) && (!x || !y)) && l) return 0;
		for(int i = 0;i <= 2;i++){
			for(int j = 0;j <= 2;j++){//printf("%d %d %d %d--\n", (i == x && !i), (j == y && !j), !((i | j) && (!i || !j)), y);
				if((i == x && i) || (j == y && j)) continue;
				//if(l == 0) printf("%d %d--\n", i, j);
				f[l][r][x][y] += dfs(l + 1, r - 1, i, j);
				if(f[l][r][x][y] >= p) f[l][r][x][y] -= p;
			}
		}
	}else{
		for(int i = 0;i <= 2;i++){
			for(int j = 0;j <= 2;j++){
				if(i == j && i) continue;
				f[l][r][x][y] += 1ll * dfs(l, R[l], x, i) * dfs(R[l] + 1, r, j, y) % p;
				if(f[l][r][x][y] >= p) f[l][r][x][y] -= p;
			}
		}
	}
	return f[l][r][x][y];
}


int main(){
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 1;i <= n;i++){
		if(s[i] == '(') sk[++top] = i;
		else R[sk[top--]] = i;
	}
	R[0] = n + 1;
	memset(f, -1, sizeof(f));
	printf("%d", dfs(0, n + 1, 0, 0));
	/*for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			for(int a = 0;a <= 2;a++){
				for(int b = 0;b <= 2;b++){
					printf("%d %d %d %d %d--\n", i, j, a, b, f[i][j][a][b]);
				}
			}
		}
	}*/
}