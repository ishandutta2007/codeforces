#include <stdio.h>
#include <vector>
#define MOD 998244353

int check[100010];
std::vector<int> prime,prime2,V;

long long int func(int k, int max)
{
	if(k>=V.size()) return max;
	long long int s1 = func(k+1,max);
	long long int s2 = func(k+1,max/V[k]);
	return s1-s2;
}

int x[200010];
int main()
{
	for(int i=2;i<=100000;i++)
	{
		if(check[i]==0)
		{
			prime.push_back(i);
			for(int j=i;j<=100000;j+=i) check[j] = 1;
		}
	}
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		prime2.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int control = 0;
		for(int i=2;i<=a;i++) if(x[i-1]%x[i]!=0) control = 1;
		if(control)
		{
			printf("0\n");
			continue;
		}
		
		int val = x[1];
		for(int i=0;i<prime.size();i++)
		{
			if(val%prime[i]==0)
			{
				prime2.push_back(prime[i]);
				while(val%prime[i]==0) val/=prime[i];
			}
		}
		if(val>1) prime2.push_back(val);
		
		long long int ans = 1;
		for(int i=2;i<=a;i++)
		{
			int g = x[i-1]/x[i];
			int max = b/x[i];
			
			V.clear();
			for(int j=0;j<prime2.size();j++) if(g%prime2[j]==0) V.push_back(prime2[j]);
			
			long long int val = func(0,max);
			ans *= val, ans %= MOD;
		}
		printf("%lld\n",ans);
	}
}