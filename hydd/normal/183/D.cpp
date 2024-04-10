#include<cstdio>
using namespace std;
int n,m,x,now[3100];
double ans,p[3100][310],f[3100][310],g[3100][310],s[3100][310],tmp[3100];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&x),p[i][j]=x*0.001;
	//ij0 
	for (int j=1;j<=m;j++){
		f[0][j]=1;
		for (int i=1;i<=n;i++) f[i][j]=f[i-1][j]*(1-p[i][j]);
	}
	for (int j=1;j<=m;j++){
		g[1][j]=1-f[n][j];//1j 
		now[j]=1;// 
		s[0][j]=f[n][j];//jn0 
	}
	for (int i=1;i<=n;i++){
		int pos=1;
		double d,mx=g[now[1]][1]-g[now[1]-1][1];//(now[1]-1)now[1]j 
		for (int j=2;j<=m;j++){
			d=g[now[j]][j]-g[now[j]-1][j];//(now[j]-1)now[j]j 
			if (d>mx) pos=j,mx=d;
		}
		ans+=mx;
		int k=now[pos]++;
		for (int j=0;j<=n;j++) tmp[j]=f[j][pos];//posj(k-1)
		f[0][pos]=0;
		for (int j=1;j<=n;j++) f[j][pos]=tmp[j-1]*p[j][pos]+f[j-1][pos]*(1-p[j][pos]);
		//posjk
		s[k][pos]=f[n][pos];// 
		double sum=1;
		for (int i=0;i<=k;i++) sum-=s[i][pos];
		g[now[pos]][pos]=sum+g[k][pos]; 
	}
	printf("%.12lf\n",ans);
	return 0;
}
/*
3 3
233 233 534
123 456 421
100 200 700

*/