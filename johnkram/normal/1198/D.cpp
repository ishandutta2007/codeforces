#include<bits/stdc++.h>
using namespace std;
int n,u,v,i,j,k,l,m,f[55][55][55][55],s[55][55];
char c[55][55];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%s",c[i]+1);
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(c[i][j]=='#');
	for(u=1;u<=n;u++)for(v=1;v<=n;v++)for(i=0;i+u<=n;i++)for(k=0;k+v<=n;k++)
	{
		j=i+u;
		l=k+v;
		if(s[j][l]+s[i][k]==s[i][l]+s[j][k])continue;
		f[i][j][k][l]=max(u,v);
		for(m=i+1;m<j;m++)f[i][j][k][l]=min(f[i][j][k][l],f[i][m][k][l]+f[m][j][k][l]);
		for(m=k+1;m<l;m++)f[i][j][k][l]=min(f[i][j][k][l],f[i][j][k][m]+f[i][j][m][l]);
	}
	cout<<f[0][n][0][n]<<endl;
	return 0;
}