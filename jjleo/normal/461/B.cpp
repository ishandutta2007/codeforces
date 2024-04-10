#include <bits/stdc++.h>
#define maxn 100086
using namespace std;

const int p = 1e9 + 7;

vector<int> v[maxn]; 
int f[maxn][2];
int ans;

void dfs(int i){
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		dfs(to);
		f[i][1] = (1ll * f[i][1] * (f[to][0] + f[to][1]) + 1ll * f[i][0] * f[to][1]) % p;
		f[i][0] = 1ll * f[i][0] * (f[to][0] + f[to][1]) % p;
	}	
}

int n, x;

int main(){
	scanf("%d", &n);
	for(int i = 2;i <= n;i++) scanf("%d", &x), v[++x].push_back(i);
	for(int i = 1;i <= n;i++) scanf("%d", &x), f[i][x] = 1;
	dfs(1);
	printf("%d", f[1][1]); 
}