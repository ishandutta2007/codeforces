#include <stdio.h>
int x[100010],G[100010];
int func(int k)
{
	int i;
	if(k==0) return 0;
	int check[5]={};
	if(k%2==0)
	{
		int s1 = func(k/2);
		int s2 = func(k-1);
		if(s1<=3) check[s1] = 1;
		if(s2<=3) check[s2] = 1;
		for(i=0;i<=4;i++) if(check[i]==0) return i;
	}
	else
	{
		if(k==1) return 1;
		else if(k==3) return 1;
		else return 0;
	}
}
int main()
{
	int a,b,i;
	scanf("%d%d",&a,&b);
	for(i=1;i<=a;i++) scanf("%d",&x[i]);
	if(b%2==0)
	{
		for(i=1;i<=a;i++)
		{
			if(x[i]%2==0)
			{
				if(x[i]==2) G[i] = 2;
				else G[i] = 1;
			}
			else
			{
				if(x[i]==1) G[i] = 1;
				else G[i] = 0;
			}
		}
	}
	else
	{
		for(i=1;i<=a;i++) G[i] = func(x[i]);
	}
	
	int ans = G[1];
	for(i=2;i<=a;i++)
	{
		ans = ans^G[i];
	}
	if(ans>0)
	{
		printf("Kevin");
		return 0;
	}
	else
	{
		printf("Nicky");
		return 0;
	}
}