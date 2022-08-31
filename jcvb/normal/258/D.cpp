#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
int n,m;
int a[1005];
typedef double db;
db f[1005][1005];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)if(j!=i){
			f[i][j]=(db)(a[i]>a[j]);
		}
	while(m--){
		int i,j;
		scanf("%d%d",&i,&j);
		f[i][j]=f[j][i]=0.5;
		for (int k=1;k<=n;k++)if(k!=i && k!=j){
			f[k][i]=f[k][j]=(f[k][i]+f[k][j])*0.5;
			f[i][k]=f[j][k]=1-f[k][i];
		}
	}
	db ans=0.0;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)ans+=f[i][j];
	printf("%.10lf\n",ans);
	return 0;
}