#include <cstdio>
#include <cstring>
#include <algorithm>

int n,k,p[101];
double f[2][101][101],C[110];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",p+i);
	for(int i=1;i<=n+1;i++)C[i]=(double)((i*(i-1))/2);
	int u=0;
	for(int i=1;i<=k&&i<=900;i++){
		u^=1;
		memset(f[u],0,sizeof f[u]);
		for(int j=1;j<=n;j++)
			for(int k=j+1;k<=n;k++){
				f[u][j][k]+=f[u^1][j][k]*(C[j]+C[k-j]+C[n-k+1]);
				for(int l=j+1;l<=k;l++)
					f[u][j][k]+=f[u^1][j][l]*((double)std::min(l-j,n-k+1));
				for(int l=k+1;l<=n;l++)
					f[u][j][k]+=f[u^1][j][l]*((double)std::min(k-j,n-l+1));
				for(int l=1;l<=j;l++)
					f[u][j][k]+=f[u^1][l][k]*((double)std::min(k-j,l));
				for(int l=j+1;l<k;l++)
					f[u][j][k]+=f[u^1][l][k]*((double)std::min(k-l,j));
				for(int l=1;l+k-j<=n;l++)
					f[u][j][k]+=(1.0-f[u^1][l][l+k-j])*((double)std::min(std::min(l,n-(l+k-j)+1),std::min(j,n-k+1)));
				f[u][j][k]/=C[n+1];
			}
	}
	double ans=0.;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			if(p[i]>p[j])ans+=(1.0-f[u][i][j]);
			else ans+=f[u][i][j];
		}
	printf("%.10lf\n",ans);
}