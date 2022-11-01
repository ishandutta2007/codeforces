#include <bits/stdc++.h>
#define maxn 82

using namespace std;

int n;
int pos[maxn], x;
int cnt, ans;
int f[maxn][maxn][maxn * maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		if(x){
			pos[++cnt] = i;
		}else{
			ans++;
		}
	}
	if(!cnt){//debug 
		for(int i = 0;i <= n * (n - 1) / 2;i++) printf("0 ");
		return 0;
	} 
	ans = ans * (ans - 1) / 2;
	memset(f, 0x3f, sizeof(f));
	f[0][0][0] = 0;
	for(int i = 1;i <= cnt;i++){
		for(int j = 1;j <= n;j++){
			for(int k = 0;k <= n * (n - 1) / 2;k++){
				if(k) f[i][j][k] = f[i][j][k - 1];
				for(int t = 0;t < j;t++){
					if(k - abs(pos[i] - j) >= 0) f[i][j][k] = min(f[i][j][k], f[i - 1][t][k - abs(pos[i] - j)] + (j - t - 1) * (j - t - 2) / 2);
				}
			}
		}
	}
	for(int i = 0;i <= n * (n - 1) / 2;i++){
		int sum = 1e9;
		for(int j = 1;j <= n;j++) sum = min(sum, f[cnt][j][i] + (n - j) * (n - j - 1) / 2);//debug:0  
		printf("%d ", ans - sum);
	}
}