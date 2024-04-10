#include<cstdio>

int main()
{
    int i,n,m;
	scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
	{
		if(i%2)printf("%d ",i/2+1);
        else printf("%d ",n-i/2+1);
	}
	for(i=m+1;i<=n;i++)
	{
		if(m%2)printf("%d ",i-m/2);
		else printf("%d ",n-i+m/2+1);
	}
}