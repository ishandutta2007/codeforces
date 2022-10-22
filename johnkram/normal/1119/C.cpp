#include<bits/stdc++.h>
using namespace std;
#define MAXN 1005
#define ll long long
int n,m,i,j,a[505][505],b[505][505];
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)
	{
		scanf("%d",a[i]+j);
		a[i][j]^=a[i-1][j]^a[i][j-1]^a[i-1][j-1];
	}
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)
	{
		scanf("%d",b[i]+j);
		b[i][j]^=b[i-1][j]^b[i][j-1]^b[i-1][j-1];
	}
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)if((i==n||j==m)&&a[i][j]!=b[i][j])
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	return 0;
}