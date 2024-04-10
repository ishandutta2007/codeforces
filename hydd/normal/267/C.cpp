#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-9;
int n,m,u[11000],v[11000],cost[11000];
double ans,a[110][110],Ans[11000],x[11000];
void Gauss(){
    for (int i=1;i<=n;i++){
        int k=i;
        for (int j=k+1;j<=n;j++)
            if (fabs(a[k][i])<fabs(a[j][i])) k=j;
         if (fabs(a[k][i])<eps) continue;           
        if (i!=k) swap(a[i],a[k]);
        for (int j=i+1;j<=n+1;j++) a[i][j]/=a[i][i];
        a[i][i]=1;
        for (int j=1;j<=n;j++){
            if (i==j) continue;
            for (int k=i+1;k<=n+1;k++) a[j][k]-=a[j][i]*a[i][k];
            a[j][i]=0;
        }
    }
    for (int i=1;i<=n;i++) x[i]=a[i][n+1];
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&cost[i]);
		if (u[i]>1&&u[i]<n) a[u[i]][v[i]]--,a[u[i]][u[i]]++;
		if (v[i]>1&&v[i]<n) a[v[i]][u[i]]--,a[v[i]][v[i]]++;
	}
	a[1][1]=1; a[1][n+1]=2;
	a[n][n]=1; a[n][n+1]=1;
	Gauss(); 
	double now=1e18;
	for (int i=1;i<=m;i++) now=min(now,cost[i]/fabs(x[u[i]]-x[v[i]]));
	if (now>=1e18) now=0;
	ans=0;
	for (int i=1;i<=m;i++){
		Ans[i]=(x[u[i]]-x[v[i]])*now;
		if (u[i]==1||v[i]==1) ans+=fabs(Ans[i]);
	}
	printf("%.5lf\n",ans);
	for (int i=1;i<=m;i++) printf("%.5lf\n",Ans[i]);
	return 0;
}