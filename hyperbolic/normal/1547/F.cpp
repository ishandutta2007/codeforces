#include <stdio.h>
#include <vector>

std::vector<int> prime;
int check[400010];
int count[400010];
int x[400010];

int main()
{
	for(int i=2;i<=1000;i++)
	{
		if(check[i]==0)
		{
			prime.push_back(i);
			for(int j=i;j<=1000;j+=i) check[j] = 1;
		}
	}
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int ans = 0;
		for(int i=0;i<prime.size();i++)
		{
			int p = prime[i];
			
			for(int j=1;j<=2*a;j++) count[j] = 0;
			for(int j=1;j<=a;j++)
			{
				int t = x[j];
				while(t%p==0) count[j]++,t/=p;
			}
			for(int j=a+1;j<=2*a;j++) count[j] = count[j-a];
			
			int min = count[1];
			for(int j=2;j<=a;j++) min = min<count[j]?min:count[j];
			for(int j=1;j<=2*a;j++) count[j] -= min;
			
			int last = 2*a+1;
			for(int j=2*a;j>=1;j--)
			{
				if(count[j]==0) last = j;
				check[j] = (last-j);
			}
			
			for(int j=1;j<=a;j++) ans = ans>check[j]?ans:check[j];
		}
		
		for(int i=1;i<=a;i++) for(int j=0;j<prime.size();j++) while(x[i]%prime[j]==0) x[i]/=prime[j];
		
		for(int i=a+1;i<=2*a;i++) x[i] = x[i-a];
		
		for(int i=2*a;i>=1;i--)
		{
			if(x[i]==1) check[i] = i;
			else
			{
				if(x[i]==x[i+1]) check[i] = check[i+1];
				else check[i] = i+1;
			}
		}
		for(int i=1;i<=a;i++) ans = ans>check[i]-i?ans:check[i]-i;
		
		printf("%d\n",ans);
	}
}