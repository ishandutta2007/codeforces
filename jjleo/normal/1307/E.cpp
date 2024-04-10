#include <bits/stdc++.h>
#define maxn 5086

using namespace std;

const int p = 1e9 + 7;

int n, m;
int f[maxn][maxn], g[maxn][maxn];
int s[maxn];
int x, y;
int mx, ans = 1;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%d", &s[i]);
		for(int j = 1;j <= n;j++){
			g[i][j] = g[i - 1][j] + (s[i] == j);
		}
	}
	while(m--){
		scanf("%d%d", &x, &y);
		f[x][y]++;
	}
	for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) f[i][j] += f[i][j - 1];
	for(int i = 1;i <= n;i++){
		if(f[i][g[n][i]]) mx++, ans = 1ll * ans * f[i][g[n][i]] % p;
	}
	for(int i = 1;i <= n;i++){//debug:n n+1  
		if(!g[i][s[i]]) continue;
		x = f[s[i]][g[i][s[i]]] - f[s[i]][g[i][s[i]] - 1];
		if(!x) continue;
		int sum = 1, cnt = 0;
		y = f[s[i]][g[n][s[i]] - g[i][s[i]]];
		if(g[i][s[i]] <= g[n][s[i]] - g[i][s[i]]) y--;
		//printf("%d %d %d--\n", i, x, y);
		sum = 1ll * sum * x % p, cnt++;
		if(y) sum = 1ll * sum * y % p, cnt++;
		for(int j = 1;j <= n;j++){
			if(j == s[i]) continue;
			x = f[j][g[i][j]], y = f[j][g[n][j] - g[i][j]];
			if(!x && !y) continue;
			if(x == 1 && y == 1) sum = 1ll * sum * 2 % p, cnt++;
			else if(x && y) sum = 1ll * sum * (1ll * x * y - min(x, y)) % p, cnt += 2;
			else if(x) sum = 1ll * sum * x % p, cnt++;
			else sum = 1ll * sum * y % p, cnt++;
		}
		if(cnt > mx) mx = cnt, ans = sum;
		else if(cnt == mx) ans = (ans + sum) % p;
	}
	printf("%d %d", mx, ans);
}