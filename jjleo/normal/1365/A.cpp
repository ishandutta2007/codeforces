#include <bits/stdc++.h>
#define maxn 186

using namespace std;

int t, n, m;
char a[maxn][maxn];
int x, y;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		x = y = 0;
		for(int i = 1;i <= n;i++){
			int sum = 0;
			for(int j = 1;j <= m;j++){
				scanf("%d", &a[i][j]);
				sum += a[i][j];
			}
			if(!sum) x++;
		}
		for(int j = 1;j <= m;j++){
			int sum = 0;
			for(int i = 1;i <= n;i++){
				sum += a[i][j];
			}
			if(!sum) y++;
		}
		puts(min(x, y) & 1 ? "Ashish" : "Vivek");
	}
	
}