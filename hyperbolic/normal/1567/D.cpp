#include <stdio.h>

long long int power[110];
int x[110];

int main()
{
	power[1] = 1;
	for(int i=2;i<=10;i++) power[i] = 10*power[i-1];
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=10;i++) x[i] = (a%10), a/=10;
		while(1)
		{
			int count = 0;
			for(int i=1;i<=10;i++) count += x[i];
			if(count<b)
			{
				for(int i=2;i<=10;i++)
				{
					if(x[i]>=1)
					{
						x[i]--;
						x[i-1]+=10;
						break;
					}
				}
			}
			else break;
		}
		
		for(int i=1;i<b;i++)
		{
			for(int j=1;j<=10;j++)
			{
				if(x[j]>=1)
				{
					x[j]--;
					printf("%lld ",power[j]);
					break;
				}
			}
		}
		long long int sum = 0;
		for(int i=1;i<=10;i++) sum += power[i]*x[i];
		printf("%lld\n",sum);
	}
}