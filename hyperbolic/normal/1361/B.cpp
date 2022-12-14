#include <stdio.h>
#include <algorithm>

#define MOD 1000000007

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		k*=k, k%=MOD;
		b/=2;
	}
	return ans;
}

int x[1000010],check[1000010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		if(b==1)
		{
			printf("%d\n",a%2);
			continue;
		}
		
		std::sort(x+1,x+a+1);
		
		check[a] = 1;
		int type = 1;
		long long int t = 1;
		for(int i=a-1;i>=1;i--)
		{
			if(type>0)
			{
				if(x[i+1]-x[i]>=20)
				{
					for(int j=1;j<=i;j++) check[j] = 3-type;
					goto u;
				}
				else
				{
					for(int j=x[i];j<x[i+1];j++)
					{
						t*=b;
						if(t>=i)
						{
							for(int j=1;j<=i;j++) check[j] = 3-type;
							goto u;
						}
					}
				}
				
				t--;
				check[i] = 3-type;
				if(t==0) type = 0;
			}
			else if(type==0)
			{
				t++;
				check[i] = 1;
				type = 1;
			}
		}
		u:;
		
		long long int s1 = 0, s2 = 0;
		for(int i=1;i<=a;i++)
		{
			if(check[i]==1) s1 += power(b,x[i]), s1%=MOD;
			if(check[i]==2) s2 += power(b,x[i]), s2%=MOD;
		}
		printf("%lld\n",(s1-s2+MOD)%MOD);
	}
}