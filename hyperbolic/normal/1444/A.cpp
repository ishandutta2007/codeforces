#include <stdio.h>
#include <vector>

std::vector<int> prime;
int check[40010];

int main()
{
	for(int i=2;i<=40000;i++)
	{
		if(check[i]==0)
		{
			prime.push_back(i);
			for(int j=i;j<=40000;j+=i) check[j] = 1;
		}
	}
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		if(a%b!=0) printf("%lld\n",a);
		else
		{
			long long int ans = 1;
			for(int i=0;i<prime.size();i++)
			{
				if(b%prime[i]==0)
				{
					long long int s = a;
					while(s%prime[i]==0) s/=prime[i];
					b/=prime[i];
					while(b%prime[i]==0)
					{
						s*=prime[i];
						b/=prime[i];
					}
					ans = ans>s?ans:s;
				}
			}
			if(b>1)
			{
				while(a%b==0) a/=b;
				ans = ans>a?ans:a;
			}
			printf("%lld\n",ans);
		}
	}
}