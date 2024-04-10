#include<cstdio>

int f(int x,int y,int z)
{
    if(y==0)return 1;
    if(y&1)return 1LL*x*f(x,y-1,z)%z;
	x=f(x,y>>1,z);
	return 1LL*x*x%z;
}

int main()
{
	int i,n;
	scanf("%d",&n);
    if(n==4)puts("YES\n1\n3\n2\n4");
    else
	{
		for(i=2;i<n;i++)if(n%i==0)
		{
			puts("NO");
			return 0;
		}
		puts("YES\n1");
        for(i=2;i<=n;i++)printf("%I64d\n",(1LL*i*f(i-1,n-2,n)-1)%n+1);
	}
}