#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int f[maxn], g[maxn][2];

int main(){
	g[0][0] = g[0][1] = g[1][1] = 1;
	for(int i = 2;i <= 1000;i++){
		f[i] = 1e9;
		for(int j = 0;j < i;j++) f[i] = min(f[i], f[j] + f[i - 1 - j] + i - 1);
		for(int j = 0;j < i;j++) if(f[j] + f[i - 1 - j] + i - 1 == f[i]){
			int x = j + 1;
			if(x & 1) g[i][1] += g[j][0] * g[i - j - 1][0];
			else g[i][0] += g[j][1] * g[i - j - 1][0];
		}
		//if(g[i][0] + g[i][1]) printf("%d\n", i);
	}
	scanf("%d", &n);
	int x = 1;
	while(x <= n){
		if(x == n || x + 1 == n) return printf("1"), 0;
		if(x & 1) x = x * 2 + 2;
		else x = x * 2 + 1;
	}
	printf("0");
}