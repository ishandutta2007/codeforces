#include<cstdio>

int main()
{
	int i,n,t,r=0,res=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
        r+=t;
	}
	for(i=1;i<=5;i++)if((i+r)%(n+1)!=1)res++;
	printf("%d",res);
}