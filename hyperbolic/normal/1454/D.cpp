#include <stdio.h>

long long int count[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=50;i++) count[i] = 1;
		long long int a,b;
		scanf("%lld",&a);
		b = a;
		for(long long int i=2;i*i<=a;i++)
		{
			for(int j=1;b%i==0;j++)
			{
				count[j] *= i;
				b/=i;
			}
		}
		if(b>1) count[1]*=b;
		for(int i=1;i<=50;i++)
		{
			if(count[i]==1)
			{
				printf("%d\n",i-1);
				for(int j=i-1;j>=1;j--) printf("%lld ",count[j]);
				printf("\n");
				break;
			}
		}
	}
}