#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
#define N 1099
int n,m,f[N][N],g[N][N],ans,cc,dd,ee,ff;
char a[N][N];
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)scanf("%s",a[i]+1);  /// //
	for(int i=1;i<=m;++i)f[n][i]=1;
	for(int i=n-1;i;--i)
	for(int j=1;j<=m;++j)if(a[i][j]==a[i+1][j])f[i][j]=f[i+1][j]+1;
		else f[i][j]=1;
	for(int i=1;i<=n;++i)g[i][m]=1;
	for(int i=1;i<=n;++i)
	for(int j=m-1;j;--j)if(a[i][j]==a[i][j+1])g[i][j]=g[i][j+1]+1;
		else g[i][j]=1;
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j){
		cc=f[i][j];
		dd=f[i+cc][j];
		ee=f[i+cc+dd][j];
		if(cc==dd&&ee>=dd){
			ff=g[i][j];
			for(int k=i+1;k<i+cc+dd+dd;++k)ff=min(ff,g[k][j]);
			ans+=ff;
		}
	}
	cout<<ans;
}