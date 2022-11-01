#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int f[10][100];

int main(){
	scanf("%d", &t);
	memset(f, 0x3f, sizeof(f)), f[0][0] = 0;
	for(int i = 1;i <= 9;i++){
		for(int j = 0;j <= 50;j++){
			f[i][j + i] = min(f[i][j + i], f[i - 1][j] * 10 + i);
			f[i][j] = min(f[i][j], f[i - 1][j]);
		}
	}
	while(t--){
		scanf("%d", &n);
		printf("%d\n", f[9][n] > 1e9 ? -1 : f[9][n]);
	}
}