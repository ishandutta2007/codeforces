#include<cstdio>
#include<algorithm>

int a[500];
int b[1000];
int c[500];
int d[500];
int v[500];

int main()
{
	int i,j,n,m,r=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	for(i=0;i<m;i++)scanf("%d",&b[i]);

	for(i=0;i<n;i++)c[i]=-1;
	j=0;
	for(i=0;i<m;i++)if(!v[b[i]-1])
	{
		d[j++]=b[i]-1;
		v[b[i]-1]=1;
	}
	for(i=0;i<n;i++)if(!v[i])d[j++]=i;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(d[j]==b[i]-1)break;
            r+=a[d[j]];
		}
        while(j)
		{
			d[j]=d[j-1];
			j--;
		}
        d[0]=b[i]-1;
	}
	printf("%d",r);
}