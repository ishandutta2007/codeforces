#include <stdio.h>
#include <vector>

int check[10010];
std::vector<int> prime;
int main()
{
	for(int i=2;i<=3200;i++)
	{
		if(check[i]==0)
		{
			prime.push_back(i);
			for(int j=i;j<=3200;j+=i) check[j] = 1;
		}
	}
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int g = b-a;
		if(g==1) printf("-1\n");
		else
		{
			int ans = 123456789;
			for(int i=0;i<prime.size();i++)
			{
				if(g%prime[i]==0)
				{
					int s = a%prime[i];
					if(s==0)
					{
						printf("0\n");
						goto u;
					}
					ans = ans<prime[i]-s?ans:prime[i]-s;
					while(g%prime[i]==0) g/=prime[i];
				}
			}
			
			if(g>1)
			{
				int s = a%g;
				if(s==0)
				{
					printf("0\n");
					goto u;
				}
				ans = ans<g-s?ans:g-s;
			}
			printf("%d\n",ans);
			u:;
		}
	}
}