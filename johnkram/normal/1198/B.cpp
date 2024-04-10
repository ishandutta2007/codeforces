#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 400005
int n,m,q,i,j,k,a[MAXN],b[MAXN],c[MAXN],d[MAXN];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d",&j,&k);
		if(j==1)
		{
			scanf("%d",&j);
			a[k]=j;
			b[k]=i;
		}
		else
		{
			c[++m]=k;
			d[m]=i;
		}
	}
	for(i=m;i;i--)c[i]=max(c[i],c[i+1]);
	for(i=1;i<=n;i++)
	{
		j=lower_bound(d+1,d+m+1,b[i])-d;
		a[i]=max(a[i],c[j]);
		printf("%d ",a[i]);
	}
	return 0;
}