#include <bits/stdc++.h>
#define maxn 3086
using namespace std;

const int p = 1e9 + 7;

int n, m;
char s[maxn][maxn];
int a, b, c, d;
int f[maxn][maxn];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%s", s[i] + 1);
	f[1][2] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(s[i][j] != '#') f[i][j] = (1ll * f[i][j] + f[i - 1][j] + f[i][j - 1]) % p;
			else f[i][j] = 0;
		}
	}
	a = f[n - 1][m], b = f[n][m - 1];
	memset(f, 0, sizeof(f));
	f[2][1] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(s[i][j] != '#') f[i][j] = (1ll * f[i][j] + f[i - 1][j] + f[i][j - 1]) % p;
			else f[i][j] = 0;
		}
	}
	c = f[n - 1][m], d = f[n][m - 1];
	printf("%d", ((1ll * a * d - 1ll * b * c) % p + p) % p);
}