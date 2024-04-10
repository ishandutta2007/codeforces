#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int p = 998244353;

int t, n;
int C[100][100];

int main(){
	for(int i = 0;i <= 60;i++){
		C[i][0] = 1;
		for(int j = 1;j <= i;j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int x = 0, y = 0;
		for(int i = 1;i * 2 <= n;i++){
			if(i & 1){
				x = (x + C[n - i * 2 + 1][(n - i * 2 + 1) / 2]) % p;
				y = (y + C[n - i * 2][(n - i * 2) / 2 - 1]) % p;
			}else{
				y = (y + C[n - i * 2 + 1][(n - i * 2 + 1) / 2]) % p;
				x = (x + C[n - i * 2][(n - i * 2) / 2 - 1]) % p;
			}
		}
		printf("%d %d %d\n", x, y, 1);
	}	
}