#include <bits/stdc++.h>
#define maxn 186

using namespace std;

int n, m, k;
int x, y;
pair<int, int> a[maxn][maxn];

int f[maxn][maxn];

int dfs(int i, int j){
	if(i > j) return 0;
	if(f[i][j] ^ -1) return f[i][j];
	for(int k = i;k <= j;k++){
		int sum = dfs(i, k - 1) + dfs(k + 1, j);
		int y = 0;
		for(int x = 1;x <= n;x++){
			if(i <= a[x][k].first && a[x][k].second <= j) y++;
		}
		sum += y * y;
		f[i][j] = max(f[i][j], sum);
	}
	return f[i][j];
	
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%d", &k);
		while(k--){
			scanf("%d%d", &x, &y);
			for(int j = x;j <= y;j++) a[i][j] = {x, y};
		}
	}
	memset(f, -1, sizeof(f));
	printf("%d", dfs(1, m));
}