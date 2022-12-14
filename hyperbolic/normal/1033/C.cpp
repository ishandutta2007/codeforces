#include <stdio.h>

int x[100010],check[100010];
int a;

int func(int k) // 1 : win 2 : lose
{
	if(check[k]) return check[k];
	int c = x[k];
	for(int j=k-c;j>=1;j-=c)
	{
		if(x[j]>x[k])
		{
			if(func(j)==2)
			{
				return check[k] = 1;
			}
		}
	}
	for(int j=k+c;j<=a;j+=c)
	{
		if(x[j]>x[k])
		{
			if(func(j)==2)
			{
				return check[k] = 1;
			}
		}
	}
	return check[k] = 2;
}

int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		printf("%c",func(i)==1?'A':'B');
	}
}