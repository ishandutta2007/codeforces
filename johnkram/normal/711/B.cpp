#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
ll r[505],c[505],A,B,C,D;
int n,a[505][505],x,y,i,j;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)
	{
		scanf("%d",a[i]+j);
		r[i]+=a[i][j];
		c[j]+=a[i][j];
		if(!a[i][j])
		{
			x=i;
			y=j;
		}
		if(i==j)A+=a[i][j];
		if(i+j==n+1)B+=a[i][j];
	}
	if(n==1)
	{
		puts("1");
		return 0;
	}
	if(x==1)C=r[2];
	else C=r[1];
	for(i=1;i<=n;i++)if(i!=x&&r[i]!=C)break;
	if(i<=n)
	{
		puts("-1");
		return 0;
	}
	for(i=1;i<=n;i++)if(i!=y&&c[i]!=C)break;
	if(i<=n)
	{
		puts("-1");
		return 0;
	}
	if(x!=y&&A!=C||x+y!=n+1&&B!=C||r[x]!=c[y]||r[x]>=C||x==y&&A!=r[x]||x+y==n+1&&B!=r[x])
	{
		puts("-1");
		return 0;
	}
	cout<<C-r[x]<<endl;
	return 0;
}