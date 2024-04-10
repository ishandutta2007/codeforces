#include<cstdio>
#include<algorithm>

int d[16777216];
int p[16777216];
int q[16777216];
int x[24];
int y[24];

void dfs(int x)
{
	if(x)
	{
		dfs(q[x]>0?((x&~(1<<p[x]))&~(1<<q[x])):(x&~(1<<p[x])));
		printf("%d ",p[x]+1);
		if(q[x]>0)printf("%d ",q[x]+1);
	}
	printf("0 ");
}

int main()
{
	int i,j,k,n;
	scanf("%d%d%d",&i,&j,&n);
	for(k=0;k<n;k++)
	{
		scanf("%d%d",&x[k],&y[k]);
		x[k]-=i;y[k]-=j;
	}
    for(i=1;i<(1<<n);i++)d[i]=1e9;
    for(i=0;i<(1<<n)-1;i++)
	{
		for(j=0;(i>>j)&1;j++);
		if(d[i|(1<<j)]>d[i]+2*(x[j]*x[j]+y[j]*y[j]))
		{
			d[i|(1<<j)]=d[i]+2*(x[j]*x[j]+y[j]*y[j]);
			p[i|(1<<j)]=j;
			q[i|(1<<j)]=-1;
		}
		for(k=j+1;k<n;k++)if(((i>>k)&1)==0)
		{
			if(d[i|(1<<j)|(1<<k)]>d[i]+x[j]*x[j]+y[j]*y[j]+x[k]*x[k]+y[k]*y[k]+(x[j]-x[k])*(x[j]-x[k])+(y[j]-y[k])*(y[j]-y[k]))
			{
				d[i|(1<<j)|(1<<k)]=d[i]+x[j]*x[j]+y[j]*y[j]+x[k]*x[k]+y[k]*y[k]+(x[j]-x[k])*(x[j]-x[k])+(y[j]-y[k])*(y[j]-y[k]);
				p[i|(1<<j)|(1<<k)]=j;
				q[i|(1<<j)|(1<<k)]=k;
			}
		}
	}
	printf("%d\n",d[(1<<n)-1]);
	dfs((1<<n)-1);
}