#include <stdio.h>
int t=1,prime[1000010];
int func(int s, int t)
{
	int count = 0;
	while(1)
	{
		if(s%t==0) count++,s/=t;
		else return count;
	}
}
int x[1000010];
int main()
{
	int control;
	for(int i=2;i<=1000;i++)
	{
		control = 0;
		for(int j=1;j<t&&prime[j]*prime[j]<=i;j++)
		{
			if(i%prime[j]==0) control = 1;
		}
		if(control==0) prime[t] = i,t++;
	}
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int j=1;j<t;j++)
	{
		int max = func(x[1],prime[j]);
		for(int i=2;i<=a;i++)
		{
			int s = func(x[i],prime[j]);
			max = max>s?max:s;
		}
		
		if(max<func(b,prime[j]))
		{
			printf("No");
			return 0;
		}
	}
	for(int j=1;j<t;j++)
	{
		while(b%prime[j]==0) b/=prime[j];
	}
	if(b==1) printf("Yes");
	else
	{
		for(int i=1;i<=a;i++)
		{
			if(x[i]%b==0)
			{
				printf("Yes");
				return 0;
			}
		}
		printf("No");
	}
}