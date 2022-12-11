#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
struct point{
	int x,y;
}x[110][110];
int n,m,Q,ans[110][110];
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) x[i][j]=(point){i,j};
	for (;Q;Q--){
		int k1; scanf("%d",&k1);
		if (k1==1){
			int k2; scanf("%d",&k2);
			for (int i=1;i<=m;i++) x[k2][i-1]=x[k2][i];
			x[k2][m]=x[k2][0];
		} else if (k1==2){
			int k2; scanf("%d",&k2);
			for (int i=1;i<=n;i++) x[i-1][k2]=x[i][k2];
			x[n][k2]=x[0][k2];
		} else {
			int k2,k3,k4; scanf("%d%d%d",&k2,&k3,&k4);
			ans[x[k2][k3].x][x[k2][k3].y]=k4;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) printf("%d ",ans[i][j]); printf("\n");
	}
}