#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

const int p = 1e9 + 7;

int f[10][maxn];

int dfs(int i, int j){
	if(j == 0) return 1;
	if(f[i][j] != -1) return f[i][j];
	f[i][j] = 0;
	if(i < 9) f[i][j] = dfs(i + 1, j - 1);
	else f[i][j] = (dfs(1, j - 1) + dfs(0, j - 1)) % p;
	return f[i][j];
}

int t, n, m;

int main(){
	memset(f, -1, sizeof(f));
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		int ans = 0;
		while(n) ans = (ans + dfs(n % 10, m)) % p, n /= 10;
		printf("%d\n", ans); 
	}
}