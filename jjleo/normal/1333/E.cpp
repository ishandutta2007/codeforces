#include <bits/stdc++.h>
#define maxn 505

using namespace std;

int n;
int a[maxn][maxn];
int cnt;

int main(){
	scanf("%d", &n);
	if(n <= 2) return printf("-1"), 0;
	for(int i = 1;i <= n - 2;i++){
		if(i & 1) for(int j = 1;j <= n;j++) a[i][j] = ++cnt;
		else for(int j = n;j;j--) a[i][j] = ++cnt;
	}
	if((n - 1) & 1){
		for(int i = 1;i <= n - 3;i++) a[n - 1][i] = ++cnt;
		for(int i = n - 3;i;i--) a[n][i] = ++cnt;
		a[n][n - 1] = ++cnt;
		a[n - 1][n - 2] = ++cnt;
		a[n - 1][n - 1] = ++cnt;
		a[n][n] = ++cnt;
		a[n - 1][n] = ++cnt;
		a[n][n - 2] = ++cnt;
	}else{
		for(int i = 4;i <= n;i++) a[n - 1][i] = ++cnt;
		for(int i = n;i >= 4;i--) a[n][i] = ++cnt;
		a[n][2] = ++cnt;
		a[n - 1][1] = ++cnt;
		a[n - 1][2] = ++cnt;
		a[n][3] = ++cnt;
		a[n - 1][3] = ++cnt;
		a[n][1] = ++cnt;
	}
	swap(a[1][2], a[1][3]);//debug:n=3 
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			printf("%d ", a[i][j]);
		}
		puts("");
	}
}