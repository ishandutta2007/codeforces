#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int n,m,x,y,M,i,j,k,h[MAXN],ne[MAXN<<1],p[MAXN<<1],d[MAXN][105],q[MAXN],a[MAXN],he,ta;
int main()
{
	scanf("%d%d%d%d",&n,&M,&x,&y);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	memset(d,-1,sizeof(d));
	while(M--)
	{
		scanf("%d%d",&i,&j);
		p[++m]=j;
		ne[m]=h[i];
		h[i]=m;
		p[++m]=i;
		ne[m]=h[j];
		h[j]=m;
	}
	for(i=1;i<=x;i++)
	{
		he=ta=0;
		for(j=1;j<=n;j++)if(a[j]==i)d[q[ta++]=j][i]=0;
		for(;he!=ta;)for(k=h[j=q[he++]];k;k=ne[k])if(!~d[p[k]][i])d[q[ta++]=p[k]][i]=d[j][i]+1;
	}
	for(i=1;i<=n;i++)
	{
		sort(d[i]+1,d[i]+x+1);
		for(j=1,k=0;j<=y;j++)k+=d[i][j];
		printf("%d ",k);
	}
	return 0;
}