#include<bits/stdc++.h>
using namespace std;
int n,i,j,k,ans,a[2005],f[2005][2],g[2005][2],h[2005][2005][2];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)a[i]--;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<2;j++)f[i][j]=f[i-1][j];
		for(j=a[i];~j;j--)f[i][a[i]]=max(f[i][a[i]],f[i-1][j]+1);
	}
	for(i=n;i;i--)
	{
		for(j=0;j<2;j++)g[i][j]=g[i+1][j];
		for(j=a[i];j<2;j++)g[i][a[i]]=max(g[i][a[i]],g[i+1][j]+1);
	}
	for(k=1;k<=n;k++)for(i=k;i<=n;i++)
	{
		for(j=0;j<2;j++)h[k][i][j]=h[k][i-1][j];
		for(j=a[i];j<2;j++)h[k][i][a[i]]=max(h[k][i][a[i]],h[k][i-1][j]+1);
	}
	ans=max(f[n][0],f[n][1]);
	for(i=1;i<=n;i++)for(j=i+1;j<=n;j++)ans=max(ans,f[i-1][0]+g[j+1][1]+max(h[i][j][0],h[i][j][1]));
	cout<<ans<<endl;
	return 0;
}