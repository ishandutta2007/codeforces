#include <stdio.h>
#include <algorithm>
#include <map>
#define MOD 1000000007

std::map<int,int> check;
int x[200010];
std::vector<int> V;
long long int fib[200010];
int main()
{
	fib[0] = fib[1] = 1;
	for(int i=2;i<=200000;i++) fib[i] = (fib[i-1]+fib[i-2])%MOD;
	for(int i=1;i<=200000;i++) fib[i] = (fib[i]+fib[i-1])%MOD;
	
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int c = x[i];
		V.clear();
		
		while(c) V.push_back(c%2),c/=2;
		std::reverse(V.begin(),V.end());
		
		int s = 0;
		for(int j=0;j<V.size();j++)
		{
			s*=2, s+=V[j];
			if(check[s])
			{
				int p = j+1;
				while(p<V.size())
				{
					if(V[p]==1) p++;
					else
					{
						if(p+1>=V.size()) goto u;
						else if(V[p+1]==1) goto u;
						else p+=2;
					}
				}
				goto v;
				u:;
			}
			
		}
		
		if(V.size()<=b) ans += fib[b-V.size()];
		ans %= MOD;
		
		v:;
		check[x[i]] = 1;
	}
	printf("%lld",ans);
}