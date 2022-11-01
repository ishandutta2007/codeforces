#include <bits/stdc++.h>
#define maxn 1086

using namespace std;

const int p = 1e9 + 7;

int t;
int n, k;
int f[maxn][maxn][2];

int dfs(int i, int j, int k){
	if(!j) return 0;
	if(i > n || i < 1) return 1;
	if(f[i][j][k] != -1) return f[i][j][k];
	int ans = 0;
	if(k == 0){
		ans = dfs(i + 1, j, 0) + dfs(i - 1, j - 1, 1);
	}else{
		ans = dfs(i - 1, j, 1) + dfs(i + 1, j - 1, 0);
	}
	if(ans >= p) ans -= p;
	return f[i][j][k] = ans;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1;i <= n;i++) for(int j = 1;j <= k;j++) f[i][j][0] = f[i][j][1] = -1;
		printf("%d\n", dfs(1, k, 0));
	}
}