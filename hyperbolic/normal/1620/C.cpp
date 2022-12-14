#include <stdio.h>
#define MAX (long long int)2e18

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k;
		k*=k;
		b/=2;
	}
	return ans;
}

int count[2010];
long long int y[2010];
char x[2010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		long long int c;
		scanf("%d%d%lld",&a,&b,&c);
		for(int i=0;i<=a+1;i++) count[i] = y[i] = 0;
		
		scanf("%s",x+1);
		
		int start = 1;
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='a') start = i+1;
			else count[start]+=b;
		}
		
		long long int S = 1;
		for(int i=a;i>=1;i--)
		{
			if(x[i]=='*')
			{
				y[i] = S;
				if(MAX/(count[i]+1) <= S) S = MAX;
				else S *= (count[i]+1);
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='a') printf("a");
			else
			{
				for(int j=0;j<=count[i];j++)
				{
					if((j+1)*y[i]>=c)
					{
						for(int k=1;k<=j;k++) printf("b");
						c -= j*y[i];
						goto u;
					}
				}
				for(int k=1;k<=count[i];k++) printf("b");
				c -= count[i]*y[i];
				u:;
			}
		}
		printf("\n");
	}
}