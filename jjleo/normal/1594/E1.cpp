#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int p = 1e9 + 7;

int n;
int f[100][10];

int main(){
	scanf("%d", &n);
	for(int i = 0;i < 6;i++) f[1][i] = 1;
	for(int i = 2;i <= n;i++){
		for(int j = 0;j < 6;j++){
			for(int k = 0;k < 6;k++) if(!(j == k || (j ^ k) == 1)){
				for(int l = 0;l < 6;l++) if(!(j == l || (j ^ l) == 1)){
					f[i][j] = (f[i][j] + 1ll * f[i - 1][k] * f[i - 1][l]) % p;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0;i < 6;i++) ans = (ans + f[n][i]) % p;
	printf("%d", ans); 
}