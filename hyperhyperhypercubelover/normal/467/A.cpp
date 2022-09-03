#include<cstdio>

int main()
{
	int i,n,a,b,r=0;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&a,&b);
		if(a+2<=b)r++;
	}
	printf("%d",r);
}