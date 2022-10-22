#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
#define MAXM 1000005
bool b[MAXN];
int t,n,m,M,X,Y,i,j,k,h[MAXN],ne[MAXM],p[MAXM],w[MAXM],x[MAXN],y[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&M);
		m=0;
		fill(h+1,h+3*n+1,0);
		fill(b+1,b+3*n+1,0);
		for(k=1;k<=M;k++)
		{
			scanf("%d%d",&i,&j);
			p[++m]=j;
			ne[m]=h[i];
			w[m]=k;
			h[i]=m;
			p[++m]=i;
			ne[m]=h[j];
			w[m]=k;
			h[j]=m;
		}
		X=Y=0;
		for(i=1;i<=3*n;i++)if(!b[i])
		{
			for(j=h[i];j;j=ne[j])if(!b[p[j]])break;
			if(j)
			{
				x[++X]=w[j];
				b[i]=b[p[j]]=1;
			}
			else y[++Y]=i;
		}
		if(X>=n)
		{
			puts("Matching");
			for(i=1;i<=n;i++)printf("%d ",x[i]);
			puts("");
		}
		else
		{
			puts("IndSet");
			for(i=1;i<=n;i++)printf("%d ",y[i]);
			puts("");
		}
	}
	return 0;
}