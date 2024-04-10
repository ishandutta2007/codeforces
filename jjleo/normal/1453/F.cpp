#include <bits/stdc++.h>
#define maxn 3086

using namespace std;

int t;
int n;
int a[maxn];
int f[maxn][maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		memset(f, 0x3f, sizeof(f));
		for(int i = 1;i <= n;i++) f[1][i] = 0;
		for(int i = 2;i <= n;i++){
			int cnt = 0;
			for(int j = i - 1;~j;j--){
				if(j + a[j] >= i){
					f[i][j + a[j]] = min(f[i][j + a[j]], f[j][i - 1] + (cnt++));
				}
			}
			for(int j = i + 1;j <= n;j++){
				f[i][j] = min(f[i][j], f[i][j - 1]);
			}
		}
		printf("%d\n", f[n][n]);
	}
}