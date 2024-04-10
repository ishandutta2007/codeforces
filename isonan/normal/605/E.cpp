#include <cstdio>

double E[1001],prod[1001],p[1001][1001];
bool vis[1001];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1,tem;j<=n;j++){
			scanf("%d",&tem);
			p[i][j]=(double)tem/100.0;
		}
	if(n==1){puts("0");return 0;}
	for(int i=0;i<=n;i++)E[i]=1,prod[i]=1-p[i][n];
	E[n]=0,vis[n]=1;
	for(int i=1;i<=n;i++){
		int p=0;
		double M=1e18;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&E[j]/(1-prod[j])<M)p=j,M=E[j]/(1-prod[j]);
		vis[p]=1;
		if(p==1){
			printf("%.10lf\n",E[1]/(1-prod[1]));
			return 0;
		}
		for(int j=1;j<=n;j++)
			E[j]+=(E[p]/(1-prod[p]))*::p[j][p]*prod[j],prod[j]*=(1-::p[j][p]);
	}
}