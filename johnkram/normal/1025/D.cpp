#include<bits/stdc++.h>
using namespace std;
bool f[705][705][2],g[705][705],ans;
int a[705],n,i,j,k,l;
int gcd(int x,int y)
{
	if(!y)return x;
	return gcd(y,x%y);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)g[i][j]=gcd(a[i],a[j])>1;
	for(i=0;i<=n;i++)f[i+1][i][0]=f[i+1][i][1]=1;
	for(l=0;l<n;l++)for(i=1;i+l<=n;i++)for(j=i+l,k=i;k<=j;k++)
	{
		f[i][j][0]=f[i][j][0]||i>1&&g[i-1][k]&&f[i][k-1][1]&&f[k+1][j][0];
		f[i][j][1]=f[i][j][1]||j<n&&g[j+1][k]&&f[i][k-1][1]&&f[k+1][j][0];
	}
	for(i=1;i<=n;i++)ans=ans||f[1][i-1][1]&&f[i+1][n][0];
	if(ans)puts("Yes");
	else puts("No");
	return 0;
}