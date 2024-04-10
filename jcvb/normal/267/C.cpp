#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cmath>
#define eps 1e-7
using namespace std;
typedef long double db;
int n;
struct edge{
	int u,v,w;
}e[5005];
db a[105][105];
void gau(int n){
	for (int i=1;i<=n;i++){
		int l=i;
		for (int k=i+1;k<=n;k++)if(fabs(a[k][i])>fabs(a[l][i]))l=k;
		for (int k=i;k<=n+1;k++)swap(a[l][k],a[i][k]);
		if(fabs(a[i][i])<eps)continue;
		for (int k=i+1;k<=n;k++){
			db tmp=a[k][i]/a[i][i];
			for (int s=i;s<=n+1;s++)a[k][s]-=tmp*a[i][s];
		}
	}
	for (int i=n;i>=1;i--){		
		if(fabs(a[i][i])<eps)continue;
		a[i][n+1]/=a[i][i];
		for (int j=i-1;j>=1;j--){
			a[j][n+1]-=a[j][i]*a[i][n+1];
		}
	}
}
		
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		a[e[i].u][e[i].v]-=1.0;
		a[e[i].u][e[i].u]+=1.0;
		a[e[i].v][e[i].v]+=1.0;
		a[e[i].v][e[i].u]-=1.0;
	}
	a[1][1]=10000.0;
	for (int j=2;j<=n+1;j++)a[1][j]=0.0;
	a[n][n]=1.0;
	for (int j=1;j<n;j++)a[n][j]=0.0;a[n][n+1]=1.0;
	gau(n);
	db x=100000000000000000.0;
	for (int i=1;i<=m;i++){
		db d=a[e[i].v][n+1]-a[e[i].u][n+1];
		x=min(x,fabs(e[i].w/d));
	}
	db ans=0.0;
	for (int j=1;j<=m;j++){
		if(e[j].u==1){
			ans+=a[e[j].v][n+1]*x;
		}else if(e[j].v==1){
			ans+=a[e[j].u][n+1]*x;
		}
	}
	printf("%.10lf\n",double(ans));
	if(ans>0){
		for (int i=1;i<=m;i++){
			printf("%.10lf\n",double((a[e[i].v][n+1]-a[e[i].u][n+1])*x));
		}
	}else {
		for (int i=1;i<=m;i++){
			printf("%.10lf\n",0.0);
		}
	}
	return 0;
}