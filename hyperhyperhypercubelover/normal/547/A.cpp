#include<cstdio>

int main()
{
	long long t;
    int i,j,k,l,m;
    int a,b,c,d,e,f,g,h;
    scanf("%d%d%d%d%d%d%d%d%d",&m,&a,&b,&c,&d,&e,&f,&g,&h);
    for(i=0;i<=m;i++)
	{
        if(a==b)break;
        a=(1LL*c*a+d)%m;
	}
	if(i>m)
	{
		puts("-1");
		return 0;
	}
	a=(1LL*c*a+d)%m;
	for(j=1;j<=m;j++)
	{
        if(a==b)break;
        a=(1LL*c*a+d)%m;
	}
	if(j>m)j=0;

    for(k=0;k<=m;k++)
	{
        if(e==f)break;
        e=(1LL*g*e+h)%m;
	}
	if(k>m)
	{
		puts("-1");
		return 0;
	}
	e=(1LL*g*e+h)%m;
	for(l=1;l<=m;l++)
	{
        if(e==f)break;
		e=(1LL*g*e+h)%m;
	}
	if(l>m)l=0;

	for(t=0;t<=m;t++)
	{
		if(l==0)
		{
			if(i+t*j==k)
			{
				printf("%I64d\n",i+t*j);
				return 0;
			}
		}
		else
		{
			if(i+t*j-k>=0&&(i+t*j-k)%l==0)
			{
				printf("%I64d\n",i+t*j);
				return 0;
			}
		}
	}
	puts("-1");
}