#include<cstdio>

int rev(int x)
{
	int res=0;
	while(x)
	{
		res=res*10+x%10;
		x/=10;
	}
	return res;
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d",a+rev(b));
}