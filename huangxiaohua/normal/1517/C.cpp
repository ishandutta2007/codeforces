#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res,a[505][505];

void dfs(int x,int y,int a1){
	
	if(!k||a[x][y]){return;}
	a[x][y]=a1;k--;
	dfs(x+1,y,a1);
	dfs(x,y-1,a1);
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i][i]);
	}
	for(i=0;i<=n+1;i++){
		a[n+1][i]=a[i][0]=114514;
	}
	for(i=n;i>=1;i--){
		int tmp=k=a[i][i];
		a[i][i]=0;
		dfs(i,i,tmp);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			printf("%d ",a[i][j]);
		}puts("");
	}
}