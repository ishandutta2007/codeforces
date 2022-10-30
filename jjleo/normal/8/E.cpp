#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll k;

int a[100];
ll f[100][2][2];


ll dfs(int i, int j, int k){
	if(f[i][j][k] != -1) return f[i][j][k];
	if(i > n - i + 1) return f[i][j][k] = 1;
	f[i][j][k] = 0;
	for(int x = 0;x <= 1;x++){
		for(int y = 0;y <= 1;y++){
			if((a[i] != -1 && a[i] != x) || (a[n + 1 - i] != -1 && a[n + 1 - i] != y)) continue;
			if(i == n + 1 - i && x != y) continue;// 
			if(!j && !k){
				f[i][j][k] += dfs(i + 1, j, k);
				continue;
			}
			if(j && k){
				if(x == 0 && y == 0) f[i][j][k] += dfs(i + 1, j, 0);
				else if(x == 0 && y == 1) f[i][j][k] += dfs(i + 1, 0, j);
				continue;
			}
			if(j){
				if(x == y) f[i][j][k] += dfs(i + 1, j, k);
				else if(x < y) f[i][j][k] += dfs(i + 1, 0, k);
			}else{
				if(x != y) f[i][j][k] += dfs(i + 1, j, k);
				else if(!x) f[i][j][k] += dfs(i + 1, j, 0);
			}
		}
	}
	return f[i][j][k];
	
}

int main(){
	memset(a, -1, sizeof(a));
	scanf("%d%lld", &n, &k), ++k;
	for(int i = 1;i <= n;i++){
		memset(f, -1, sizeof(f));
		a[i] = 0;
		ll sum = dfs(1, 1, 1);
		if(k > sum) k -= sum, a[i] = 1;
		if(i == 1 && a[i] == 1) return printf("-1"), 0;//debug:k 
		printf("%d", a[i]);
		//printf("%lld--\n", sum);
	}
	
	
}