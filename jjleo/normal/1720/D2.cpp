#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int t, n;
int a[maxn];
int son[maxn * 32][2];
int mx[maxn * 32][2][2];
int cnt;

int main(){
	scanf("%d", &t);
	while(t--){
		for(int i = 1;i <= cnt;i++) memset(son[i], 0, sizeof(son[i])), memset(mx[i], 0, sizeof(mx[i]));
		cnt = 1;
		scanf("%d", &n);
		int ans = 0;
		for(int i = 0;i < n;i++){
			scanf("%d", &a[i]);
			int sum = 0;
			int now = 1;
			for(int j = 29;~j;j--){
				int X = (i >> j) & 1, Y = (a[i] >> j) & 1;
				int k = X ^ Y;
				for(int x = 0;x <= 1;x++){
					int y = x ^ k ^ 1;
					if((X ^ y) < (x ^ Y)) sum = max(sum, mx[now][x][y] + 1);		
				}
				now = son[now][k];
				if(!now) break;
			}
			ans = max(ans, sum);
			now = 1;
			for(int j = 29;~j;j--){
				int X = (i >> j) & 1, Y = (a[i] >> j) & 1;
				mx[now][X][Y] = max(mx[now][X][Y], sum); 
				int k = X ^ Y;
				if(!son[now][k]) son[now][k] = ++cnt;
				now = son[now][k];
			}
		}
		printf("%d\n", ans);
	}	
}